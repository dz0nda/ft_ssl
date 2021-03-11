/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/09 17:00:35 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_cipher.h"

int		ft_ssl_cipher_dist(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	static t_ftssl_cipher_dist	dist[FT_SSL_CIPHER_DIST] = {
		{ "base64", FT_SSL_BASE64, ft_ssl_cipher_base64 },
		{ "des", FT_SSL_DES, ft_ssl_cipher_des }
	};
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

int		ft_ssl_cipher(int argc, char *argv[])
{
	t_ftssl_cipher	ctx;

	ft_memset(&ctx, 0, sizeof(ctx));
	if (ft_ssl_cipher_dist(&ctx, argc, argv) == FT_SSL_CIPHER_NOT_FOUND)
		return (FT_SSL_CIPHER_NOT_FOUND);
	return (ctx.dist.dist_ft(argc, argv));
}
