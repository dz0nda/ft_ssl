/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher_des.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/17 12:25:41 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_cipher.h"

int		ft_ssl_cipher_des_exec(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	static t_ftssl_des_d		ftssl_des[2] = {
		{ FT_SSL_CIPHER_ENCODE, ft_des },
		{ FT_SSL_CIPHER_DECODE, ft_des_decode },
	};
	char 	*msg = NULL;
	int		msg_len = 0;

	if (ctx->opt.input == NULL)
		ctx->opt.input = argv[ctx->argi];
	msg_len = ft_get_input(ctx->opt.input, &msg);
	printf("msg: %s\n", msg);
	printf("msg_len: %d\n", msg_len);
	if (msg == NULL || msg_len < 1)
		return (EXIT_FAILURE);
	ftssl_des[ctx->opt.mode].des_mode(msg);
	ft_strdel(&msg);
	return (EXIT_SUCCESS);
}

int		ft_ssl_cipher_des(int argc, char *argv[])
{
	t_ftssl_cipher	ctx;

	ft_memset(&ctx, 0, sizeof(ctx));
	ctx.dist.dist_name = argv[0];
	ctx.opt.mode = FT_SSL_CIPHER_ENCODE;
	argc -= 1;
	argv += 1;
	while (ctx.argi < argc)
	{
		if (*argv[ctx.argi] != '-' || argv[ctx.argi][1] == '\0')
			break ;
		if (ft_ssl_cipher_des_option(&ctx, argc, argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ctx.argi++;
	}

	ft_ssl_cipher_des_exec(&ctx, argc, argv);

	return (EXIT_SUCCESS);
}
