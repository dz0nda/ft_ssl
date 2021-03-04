/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/03 22:37:22 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_opt_p(t_ftssl_dgst *ctx, int argc, char *argv[])
{
	ctx->opt.output_print = 1;
	ft_ssl_dgst_output(FTSSL_DGST_OUTP_DEFAULT, ctx, NULL);
	ctx->opt.output_print = 0;
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_opt_r(t_ftssl_dgst *ctx, int argc, char *argv[])
{
	ctx->opt.reverse = 1;
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_opt_q(t_ftssl_dgst *ctx, int argc, char *argv[])
{
	ctx->opt.output = FTSSL_DGST_OUTP_QUIET;
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_opt_s(t_ftssl_dgst *ctx, int argc, char *argv[])
{
	char *arg;

	arg = argv[ctx->argi] + 1;
	if (!(ctx->argi + 1 < argc))
		return (ft_ssl_dgst_error(FTSSL_DGST_ERR_OPT_ARG, ctx, arg));
	ctx->argi++;
	ft_ssl_dgst_output(FTSSL_DGST_OUTP_STRING, ctx, argv[ctx->argi]);
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_option(t_ftssl_dgst *ctx, int argc, char *argv[])
{
	static t_ftssl_dgst_opt_d	ft_ssl_dgst_opt[FT_SSL_DGST_OPT] = {
		{ FT_SSL_DGST_OPT_P, "p", ft_ssl_dgst_opt_p },
		{ FT_SSL_DGST_OPT_Q, "q", ft_ssl_dgst_opt_q },
		{ FT_SSL_DGST_OPT_R, "r", ft_ssl_dgst_opt_r },
		{ FT_SSL_DGST_OPT_S, "s", ft_ssl_dgst_opt_s },
	};
	int							opt_key;
	char						*opt;

	opt_key = -1;
	opt = argv[ctx->argi] + 1;
	while (++opt_key < FT_SSL_DGST_OPT)
		if (ft_strequ(opt, ft_ssl_dgst_opt[opt_key].opt_name))
			return (ft_ssl_dgst_opt[opt_key].opt_dist(ctx, argc, argv));
	if (ft_ssl_dgst_dist(ctx, argc, argv) != FT_SSL_DGST_NOT_FOUND)
		return (EXIT_SUCCESS);
	return (ft_ssl_dgst_error(FTSSL_DGST_ERR_OPT, ctx, opt));
}
