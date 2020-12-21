/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:13:21 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/21 13:42:33 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_core.h"


int		ft_ssl_usage(void)
{
	static t_ftssl_core_usage_dist		ftssl_usage_dist[FTSSL_DIST] = {
		{ "Help commands:",           ft_ssl_core 	},
		{ "Message Digest commands:", ft_ssl_dgst 	},
		{ "Cipher commands:",         ft_ssl_cipher },
	};
	int			key_dist;
	
	key_dist = -1;
	while (++key_dist < FTSSL_DIST)
	{
		ft_putendl_fd(ftssl_usage_dist[key_dist].dist_title, STDERR_FILENO);
		ftssl_usage_dist[key_dist].dist_ft(-42, NULL);
		ft_putchar('\n');
	}
	return (EXIT_SUCCESS);
}