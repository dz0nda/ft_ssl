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

int		ft_enc_dist(t_ssl_cipher* ctx, int argc, char* argv[])
{
	static t_ssl_cipher_dist dist[FT_SSL_CIPHER_DIST] = {
		{ "base64", 	FT_SSL_CIPHER_BASE64, ft_ssl_base64 },
		{ "des", 		FT_SSL_CIPHER_DES, ft_ssl_des },
		{ "des-ecb",	FT_SSL_CIPHER_DES_ECB, ft_ssl_des },
		{ "des-cbc", 	FT_SSL_CIPHER_DES_CBC, ft_ssl_des },
	};
	// static t_ssl_cipher_dist	dist[FT_SSL_CIPHER_DIST] = {
	// 	{ "base64", FT_SSL_CIPHER_BASE64, ft_ssl_base64 },
	// 	{ "des", FT_SSL_CIPHER_DES, ft_ssl_des_ecb },
	// 	{ "des-ecb", FT_SSL_CIPHER_DES_ECB, ft_ssl_des_ecb },
	// 	{ "des-cbc", FT_SSL_CIPHER_DES_CBC, ft_ssl_des_cbc },
	// };
	int							dist_key;

	dist_key = -1;
	while (++dist_key < FT_SSL_CIPHER_DIST)
	{
		if (argc == -42)
			ft_putendl_fd(dist[dist_key].dist_name, STDERR_FILENO);
		else if (ft_strequ(argv[0], dist[dist_key].dist_name))
		{
			ctx->dist = dist[dist_key];
			return(dist_key);
		}
	}
	return (FT_SSL_CIPHER_NOT_FOUND);
}

// int		ft_enc_ciphers()

int		ft_enc(int argc, char* argv[])
{
	// return (ft_enc_help());
	t_ssl_cipher	ctx;
	t_enc enc;

	// if (argv[0] != "enc") {
		// parse_alias_command(&ctx, argv[0]) 
	//}

	// while ()
	//	parse_ciphername(&ctx, argc, argv)

	// printsf("%s-%s\n", argv[0], argv[1]);

	argv++;
	ft_memset(&enc, 0, sizeof(enc));

	ft_enc_opt_init(enc.enc_opt);

	int i = -1;

	/* Get ciphers (-des, -des-ecb, ...) */
	while (*argv && ft_isopt(*argv)) {
		if (ft_enc_get_ciph(enc.cipher, *(argv)+1) == FT_EXFAIL) {
			break;
		}
		argc -= 1;
		argv += 1;
	}

	i = -1;
	char* s = NULL;
	while (*argv && ft_isopt(*argv)) {
		while (++i < FT_ENC_OPT_MAX) {
			if (ft_strequ(*(argv)+1, enc.enc_opt[i].opt_name)) {
				enc.ctx[enc.enc_opt[i].opt_key] = enc.enc_opt[i].ft(s, argc, argv + 1);
				break;
			}
		}
		// ft_enc_opt_dispatch(enc.ctx, argc, argv);
		// printf("%s\n", *argv);
		argc -= 2;
		argv += 2;
		i = -1;
	}

	// open_input
	t_in in;

	ft_memset(&in, 0, sizeof(in));
	in.len = ft_get_input(enc.ctx[FT_ENC_OPT_I], &in.data);

	if (!in.len || !in.data) {
		return (ft_get_input_404(enc.ctx[FT_ENC_OPT_I]));
	}

	int len = 0;
	char* cipher = NULL;

	// perform b64 if decrypt + b64 enabled

	// perform cipher if cypher passed

	// perform b64 if encrypt + b64 enbled
	// ft_memset(&ctx, 0, sizeof(ctx));
	// if (ft_enc_dist(&ctx, argc, argv) == FT_SSL_CIPHER_NOT_FOUND)
	// 	return (FT_SSL_CIPHER_NOT_FOUND);
	// return (ctx.dist.dist_ft(argc, argv));
}
