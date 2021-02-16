/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_core_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:11:08 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/21 13:42:24 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_core.h"

int		ft_ssl_core_dist(int argc, char *argv[])
{
	static t_ftssl_core_dist	ftssl_core_dist[FT_SSL_CORE_DIST] = {
		{ "help", FT_SSL_HELP }
	};
	int							dist_key;

	dist_key = -1;
	if (argc != -42 && ft_strequ(argv[0], ""))
		return (FT_SSL_DIST_NOT_FOUND);
	while (++dist_key < FT_SSL_CORE_DIST)
	{
		if (argc == -42)
			ft_putendl_fd(ftssl_core_dist[dist_key].dist_name, STDERR_FILENO);
		else if (ft_strequ(argv[0], ftssl_core_dist[dist_key].dist_name))
			return (ft_ssl_usage());
	}
	return (FT_SSL_DIST_NOT_FOUND);
}
