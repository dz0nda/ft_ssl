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


int		ft_enc(int argc, char* argv[])
{
	// return (ft_enc_old(argc, argv));

	t_arg arg;
	t_enc enc;
	t_ciph enc_ciph;
	t_enc_opt opt;

	ft_memset(&arg, 0, sizeof(arg));
	arg.c = argc;
	arg.v = (char**)argv;

	ft_memset(&enc, 0, sizeof(enc));
	ft_memset(&opt, 0, sizeof(opt));
	ft_memset(&enc_ciph, 0, sizeof(enc_ciph));


	// if (!ft_strequ("enc", argv[0])) {
	// 	if (ft_enc_get_ciph(enc.cipher, *argv) == FT_EXFAIL) {
	// 		printf("errooor\n");
	// 		// return (FT_EXFAIL);
	// 	}
	// 	argc -= 1;
	// 	argv += 1;
	// }

	// ft_enc_opt_init(enc.enc_opt);

	/* Parse alias command */
	if (!ft_strequ("enc", *arg.v)) {
		// printf("%s\n", *arg.v);
		if (ft_enc_get_ciph(opt.cipher, &arg) == FT_EXFAIL) {
			// ft_putendl_fd(&("openssl:Error:" + "es" + "is an invalid command"), 1);
			printf("Ivqlid command\n");
			return (FT_EXFAIL);
		}

		// arg.c -= 1;
		// arg.v += 1;
	}

	/* Parse */
	while (*arg.v && ft_isopt(*arg.v)) {
		*arg.v = *(arg.v) + 1;
		if (ft_enc_get_ciph(opt.cipher, &arg) == FT_EXFAIL
			&& ft_enc_get_opt(&opt, &arg) == FT_EXFAIL) {
			// break;
			return (FT_EXFAIL);
		}
		// *arg.v = *(arg.v) - 1;
	}

	// int i = -1;
	// char* s = NULL;
	// while (*argv && ft_isopt(*argv)) {
	// 	while (++i < FT_ENC_OPT_MAX) {
	// 		if (ft_strequ(*(argv)+1, enc.enc_opt[i].opt_name)) {
	// 			enc.ctx[enc.enc_opt[i].opt_key] = enc.enc_opt[i].ft(s, argc, argv + 1);
	// 			break;
	// 		}
	// 	}

	// 	argc -= 2;
	// 	argv += 2;
	// 	i = -1;
	// }

	// printf("%s:%s\n", enc.ctx[FT_ENC_OPT_K], enc.ctx[FT_ENC_OPT_I]);
	// printf("%s:%s\n", opt.key, opt.in);

	// // calc key
	ft_enc_get_key(&enc_ciph, &opt);

	// open_input
	t_in in;

	ft_memset(&in, 0, sizeof(in));
	in.len = ft_get_input(opt.in, &in.data);
	if (!in.len || !in.data) {
		return (ft_get_input_404(opt.in));
	}

	// printf("%d:%s\n", in.len, in.data);
	// printf("%x:%x\n", enc_ciph.key, enc_ciph.iv);

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

	// printf("%s\n", cipher);

	// // salt if encrypt

	// // perform b64 if encrypt + b64 enbled
	// // int dst_len = ft_b64_get_encoded_len(len);
	// // char* dst = (char*)ft_memalloc(dst_len + 1);

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
