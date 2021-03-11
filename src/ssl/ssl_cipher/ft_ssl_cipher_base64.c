/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher_base64.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/11 21:17:20 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_cipher.h"
#include <limits.h>
#include <arpa/inet.h>
#include <errno.h>

int		ft_ssl_cipher_des(int argc, char *argv[])
{
	printf("Hello des");
	return (EXIT_SUCCESS);
}



int		ft_ssl_cipher_base64_debug(t_ftssl_cipher *ctx)
{
	printf("\n-----\n");
	printf("opt.input = %s\n", ctx->opt.input);
	printf("opt.output = %s\n", ctx->opt.output);
	printf("\n-----\n");
	return (EXIT_SUCCESS);
}

int		ft_ssl_cipher_base64_exec(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	static t_ftssl_base64_d		ftssl_base64[2] = {
		{ FT_SSL_CIPHER_ENCODE, ft_ssl_base64 },
		{ FT_SSL_CIPHER_DECODE, ft_ssl_base64_decode },
	};
	char 	*msg = NULL;
	int		msg_len = 0;

	msg_len = ft_get_input(ctx->opt.input, &msg);
	printf("msg: %s\n", msg);
	printf("msg_len: %d\n", msg_len);
	if (msg == NULL || msg_len < 1)
		return (EXIT_FAILURE);
	ftssl_base64[ctx->opt.mode].base64_mode(msg);
	ft_strdel(&msg);
	return (EXIT_SUCCESS);
}

int		ft_ssl_cipher_base64(int argc, char *argv[])
{
	t_ftssl_cipher	ctx;

	// printf("Hello base64\n\n");
	// ft_ssl_base64(argv[1]);
	ft_memset(&ctx, 0, sizeof(ctx));
	ctx.dist.dist_name = argv[0];
	ctx.opt.mode = FT_SSL_CIPHER_ENCODE;
	argc -= 1;
	argv += 1;
	while (ctx.argi < argc)
	{
		if (*argv[ctx.argi] != '-' || argv[ctx.argi][1] == '\0')
			break ;
		if (ft_ssl_cipher_base64_option(&ctx, argc, argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ctx.argi++;
	}

	ft_ssl_cipher_base64_debug(&ctx);
	ft_ssl_cipher_base64_exec(&ctx, argc, argv);

	return (EXIT_SUCCESS);
}
