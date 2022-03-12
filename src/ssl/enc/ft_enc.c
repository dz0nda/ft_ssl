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

int		ft_enc(int argc, char* argv[])
{
	// return (ft_enc_old(argc, argv));

	t_arg arg;
	t_enc enc;
	t_ciph enc_ciph;

	ft_memset(&arg, 0, sizeof(arg));
	ft_memset(&enc, 0, sizeof(enc));
	ft_memset(&enc_ciph, 0, sizeof(enc_ciph));

	argv++; // todo
	// if (!ft_strequ("enc", argv[0])) {
	// 	if (ft_enc_get_ciph(enc.cipher, *argv) == FT_EXFAIL) {
	// 		printf("errooor\n");
	// 		// return (FT_EXFAIL);
	// 	}
	// 	argc -= 1;
	// 	argv += 1;
	// }

	ft_enc_opt_init(enc.enc_opt);

	/* Get ciphers (-des, -des-ecb, ...) */
	while (*argv && ft_isopt(*argv)) {
		if (ft_enc_get_ciph(enc.cipher, *(argv)+1) == FT_EXFAIL) {
			break;
		}
		argc -= 1;
		argv += 1;
	}

	int i = -1;
	char* s = NULL;
	while (*argv && ft_isopt(*argv)) {
		while (++i < FT_ENC_OPT_MAX) {
			if (ft_strequ(*(argv)+1, enc.enc_opt[i].opt_name)) {
				enc.ctx[enc.enc_opt[i].opt_key] = enc.enc_opt[i].ft(s, argc, argv + 1);
				break;
			}
		}

		argc -= 2;
		argv += 2;
		i = -1;
	}

	printf("%s:%s\n", enc.ctx[FT_ENC_OPT_K], enc.ctx[FT_ENC_OPT_I]);

	// // calc key
	ft_enc_get_key(&enc_ciph, enc.ctx);

	// open_input
	t_in in;

	ft_memset(&in, 0, sizeof(in));
	in.len = ft_get_input(enc.ctx[FT_ENC_OPT_I], &in.data);
	if (!in.len || !in.data) {
		return (ft_get_input_404(enc.ctx[FT_ENC_OPT_I]));
	}

	printf("%d:%s\n", in.len, in.data);
	printf("%x:%x\n", enc_ciph.key, enc_ciph.iv);

	// // perform b64 if decrypt + b64 enabled

	// // perform cipher if cypher passed

	int len = 0;
	char* cipher = NULL;
	if (enc.cipher[0] != NULL && enc.cipher[1] != NULL) {
		printf(".here\n");

		len = enc.cipher[0](enc_ciph.key, in.data, in.len, &cipher, enc_ciph.iv);
	}
	// // salt if encrypt

	// // perform b64 if encrypt + b64 enbled
	// // int dst_len = ft_b64_get_encoded_len(len);
	// // char* dst = (char*)ft_memalloc(dst_len + 1);

	// ft_b64_enc(dst, dst_len, cipher, len);

	// // ft_write_output(enc.ctx[FT_ENC_OPT_O], dst, 64);

	ft_ouptput(enc.ctx[FT_ENC_OPT_O], cipher, len);

	return (FT_EXOK);

}
