/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc.c                                    		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 13:32:23 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enc.h"


int ft_ssl_des_exec_salt(char** cipher, int cipher_len, char* salt) {
	char* tmp = NULL;

	if ((tmp = ft_memalloc(cipher_len)) == NULL) {
		return (FT_FALSE);
	}
	ft_memcpy(tmp, cipher[0], cipher_len);
	ft_strdel(cipher);
	if ((*cipher = ft_memalloc(cipher_len + 16 + 1)) == NULL) {
		return (FT_FALSE);
	}
	// ft_memset(cipher[0], '\0', cipher_len + 16 + 1);
	ft_memcpy(&(*cipher)[0], "Salted__", 8);
	ft_memcpy(&(*cipher)[8], salt, 8);
	ft_memcpy(&(*cipher)[16], tmp, cipher_len);
	free(tmp);
	return (cipher_len + 16);
}

int ft_ouptput(char* file, char* output, int breaker) {
	int fd;
	int i;
	int length;
	// printf("LAAA\n");

	fd = 1;
	i = 0;
	length = breaker;
	if (file != NULL &&
		(fd = open(file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
		return (0);

	// if (breaker > 0) {
	//     while (i + breaker < length) {
	//       write(fd, &output[i], breaker);
	//       write(fd, "\n", 1);
	//       i += breaker;
	//     }
	// }

	write(fd, &output[i], length);
	// if (breaker) write(fd, "\n", 1);

	return (length);
}


int		ft_enc(int argc, char* argv[])
{
	// return (ft_enc_old(argc, argv));

	t_arg arg;
	t_enc_opt opt;
	t_ciph enc_ciph;

	ft_memset(&arg, 0, sizeof(arg));
	ft_memset(&opt, 0, sizeof(opt));
	ft_memset(&enc_ciph, 0, sizeof(enc_ciph));

	arg.c = argc;
	arg.v = (char**)argv;

	/* Parse alias command */
	if (!ft_strequ("enc", *arg.v)) {
		if (ft_enc_get_ciph(opt.cipher, &arg) == FT_EXFAIL) {
			return (-42);
			// return (ft_enc_err_invalid_command(*arg.v));
		}
	}
	else {
		arg.c -= 1;
		arg.v += 1;
	}

	/* Parse options */
	while (*arg.v && ft_isopt(*arg.v)) {
		*arg.v = *(arg.v) + 1;
		if (ft_enc_get_ciph(opt.cipher, &arg) == FT_EXFAIL
			&& ft_enc_get_opt(&opt, &arg) == FT_EXFAIL) {
			return (ft_enc_help());
		}
		// *arg.v = *(arg.v) - 1;
	}

	// // calc key
	// printf("%s\n", opt.cipher);
	if (opt.cipher[0] != NULL && ft_enc_get_key(&enc_ciph, &opt) == FT_EXFAIL) {
		return (FT_EXFAIL);
	}

	// open_input
	t_in in;

	ft_memset(&in, 0, sizeof(in));
	in.len = ft_get_input(opt.in, &in.data);
	if (!in.len || !in.data) {
		return (ft_get_input_404(opt.in));
	}

	// // perform b64 if decrypt + b64 enabled
	if (opt.b64 && opt.enc == FT_ENC_D) {
		in.data[--(in.len)] = '\0';
		int dst_len = ft_b64_get_decoded_len((t_uchar*)in.data, in.len);

		char* dst = (char*)ft_memalloc(dst_len + 1);

		ft_b64_dec((t_uchar*)dst, dst_len, (t_uchar*)in.data, in.len);

		free(in.data);

		in.data = dst;
		in.len = dst_len;
	}
	// // perform cipher if cypher passed

	int len = 0;
	char* cipher = NULL;
	if (opt.cipher[0] != NULL && opt.cipher[1] != NULL) {
		// printf(".here\n");

		len = opt.cipher[opt.enc](enc_ciph.key, in.data, in.len, &cipher, enc_ciph.iv);

		// printf(".%s.\n", enc_ciph.salt);

		if (opt.enc == FT_ENC_E && ft_strlen(enc_ciph.salt)) {
			// printf("here\n\n\n\n");
			len = ft_ssl_des_exec_salt(&cipher, len, enc_ciph.salt);
		}
	}
	else {
		len = in.len;
		cipher = in.data;
	}


	// // salt if encrypt

	// // perform b64 if encrypt + b64 enbled
	// // int dst_len = ft_b64_get_encoded_len(len);
	// // char* dst = (char*)ft_memalloc(dst_len + 1);

	// printf("%s\n", cipher);

	if (opt.b64 && opt.enc == FT_ENC_E) {
		int dst_len = ft_b64_get_encoded_len(len);
		char* dst = (char*)ft_memalloc(dst_len + 1);

		ft_b64_enc(dst, dst_len, cipher, len);
		ft_write_output(opt.out, dst, 64);
	}
	else {
		ft_ouptput(opt.out, cipher, len);
	}

	return (FT_EXOK);
}
