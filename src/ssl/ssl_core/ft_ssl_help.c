/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:13:21 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/05 20:34:52 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_core.h"

static t_ftssl_core_usage_dist		g_ftssl_usage[FTSSL_DIST_MAX] = {
	{ "Help commands:",           ft_ssl_core_dispatch_dist 	},
	{ "Message Digest commands:", ft_ssl_dgst_dispatch_dist 	},
	{ "Cipher commands:",         ft_ssl_cipher_dispatch_dist },
	{ "Standard commands:",       ft_ssl_stdrd_dispatch_dist 	}
};

int		ft_ssl_usage(void)
{
	int			key_dist;
	
	key_dist = -1;
	while (++key_dist < FTSSL_DIST_MAX)
	{
		ft_putendl_fd(g_ftssl_usage[key_dist].dist_title, STDERR_FILENO);
		g_ftssl_usage[key_dist].dist_check(NULL);
	}
	return (EXIT_SUCCESS);
}