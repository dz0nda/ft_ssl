/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher_base64 options.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/11 21:05:21 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_cipher.h"

int		ft_ssl_cipher_opt_d(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -d\n");
	ctx->opt.mode = FT_SSL_CIPHER_DECODE;
	return (EXIT_SUCCESS);
}

int		ft_ssl_cipher_opt_e(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -e\n");
	ctx->opt.mode = FT_SSL_CIPHER_ENCODE;
	return (EXIT_SUCCESS);
}

int		ft_ssl_cipher_opt_i(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -i\n");
	if ((ctx->opt.input = argv[++ctx->argi]) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_ssl_cipher_opt_o(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -o\n");
	if ((ctx->opt.output = argv[++ctx->argi]) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_ssl_cipher_base64_option(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	static t_ftssl_cipher_opt_d	ft_ssl_cipher_opt[FT_SSL_CIPHER_OPT] = {
		{ FT_SSL_CIPHER_OPT_D, "d", ft_ssl_cipher_opt_d },
		{ FT_SSL_CIPHER_OPT_E, "e", ft_ssl_cipher_opt_e },
		{ FT_SSL_CIPHER_OPT_I, "i", ft_ssl_cipher_opt_i },
		{ FT_SSL_CIPHER_OPT_O, "o", ft_ssl_cipher_opt_o },
	};
	int							opt_key;
	char						*opt;

	opt_key = -1;
	opt = argv[ctx->argi] + 1;
	while (++opt_key < FT_SSL_CIPHER_OPT)
		if (ft_strequ(opt, ft_ssl_cipher_opt[opt_key].opt_name))
			return (ft_ssl_cipher_opt[opt_key].opt_dist(ctx, argc, argv));
	return (ft_ssl_cipher_base64_error(ctx, argc, argv));
}