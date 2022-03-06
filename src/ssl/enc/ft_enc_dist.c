/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_dist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/21 13:36:18 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enc.h"

t_ftssl_cipher_dist		g_ftssl_cipher_dist[FT_SSL_CIPHER_DIST] = {
	{ "base64", FT_SSL_BASE64 },
	{ "des", FT_SSL_DES }
};

int		ft_enc_dist(int argc, char *argv[])
{
	static t_ftssl_cipher_dist	ftssl_cipher_dist[FT_SSL_CIPHER_DIST] = {
		{ "base64", FT_SSL_BASE64 },
		{ "des", FT_SSL_DES }
	};
	int							dist_key;

	dist_key = -1;
	if (argc != -42 && ft_strequ(argv[0], ""))
		return (FT_SSL_CIPHER_NOT_FOUND);
	while (++dist_key < FT_SSL_CIPHER_DIST)
	{
		if (argc == -42)
			ft_putendl_fd(ftssl_cipher_dist[dist_key].dist_name, STDERR_FILENO);
		else if (ft_strequ(argv[0], ftssl_cipher_dist[dist_key].dist_name))
			ft_putendl("Command not yet implemented");
	}
	return (FT_SSL_CIPHER_NOT_FOUND);
}
