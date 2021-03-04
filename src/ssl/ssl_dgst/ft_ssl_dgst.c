/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:05:36 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/03 22:36:27 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_dist(t_ftssl_dgst *ctx, int argc, char *argv[])
{
	static t_ftssl_dgst_dist	dist[FT_DGST_VERSION] = {
		{ FT_MD5, "md5", "MD5" },
		{ FT_SHA1, "sha1", "SHA1" },
		{ FT_SHA224, "sha224", "SHA224" },
		{ FT_SHA256, "sha256", "SHA256" },
		{ FT_SHA384, "sha384", "SHA384" },
		{ FT_SHA512, "sha512", "SHA512" },
		{ FT_SHA512224, "sha512224", "SHA51224" },
		{ FT_SHA512256, "sha512256", "SHA512256" }
	};
	int							cmd_key;

	cmd_key = -1;
	while (++cmd_key < FT_DGST_VERSION)
	{
		if (argc == -42)
			ft_putendl_fd(dist[cmd_key].name_lower, STDERR_FILENO);
		else if (ft_strequ(argv[0], dist[cmd_key].name_lower)
		|| ft_strequ(argv[0], dist[cmd_key].name_upper))
		{
			ctx->distrib = dist[cmd_key];
			return (cmd_key);
		}
	}
	return (FT_SSL_DGST_NOT_FOUND);
}

int		ft_ssl_dgst_argument(t_ftssl_dgst *ctx, int argc, char *argv[])
{
	char *arg;

	arg = argv[ctx->argi];
	if (ctx->argi == argc && ft_strlen(ctx->md) == 0)
		return (ft_ssl_dgst_output(FTSSL_DGST_OUTP_DEFAULT, ctx, arg));
	while (ctx->argi < argc)
	{
		if (ft_isreg(argv[ctx->argi]))
			ft_ssl_dgst_output(FTSSL_DGST_OUTP_FILE, ctx, argv[ctx->argi]);
		else if (ft_isdir(argv[ctx->argi]))
			ft_ssl_dgst_error(FTSSL_DGST_ERR_DIR, ctx, argv[ctx->argi]);
		else
			ft_ssl_dgst_error(FTSSL_DGST_ERR_FILE, ctx, argv[ctx->argi]);
		ctx->argi++;
	}
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst(int argc, char *argv[])
{
	t_ftssl_dgst	ctx;

	ft_memset(&ctx, 0, sizeof(ctx));
	if (ft_ssl_dgst_dist(&ctx, argc, argv) == FT_SSL_DGST_NOT_FOUND)
		return (FT_SSL_DGST_NOT_FOUND);
	argc -= 1;
	argv += 1;
	while (ctx.argi < argc)
	{
		if (*argv[ctx.argi] != '-' || argv[ctx.argi][1] == '\0')
			break ;
		if (ft_ssl_dgst_option(&ctx, argc, argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ctx.argi++;
	}
	return (ft_ssl_dgst_argument(&ctx, argc, argv));
}
