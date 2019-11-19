/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_usage.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:11:53 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 20:05:17 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ftssl_usage_table		g_ftssl_usage[FTSSL_DIST_E] = {
	{ "Help commands:",  ft_ssl_prgm_dispatch_dist },
	{ "Message Digest commands:", ft_ssl_dgst_dispatch_dist },
	{ "Cipher commands:", ft_ssl_cipher_dispatch_dist },
	{ "Standard commands:", ft_ssl_stdrd_dispatch_dist }
};

int		ft_ssl_usage(int cmd_key, char *cmd_name, int argc, char *argv[])
{
	int			key_dist;
	
	(void)cmd_key;
	(void)cmd_name;
	(void)argc;
	(void)argv;
	key_dist = -1;
	while (++key_dist < FTSSL_DIST_E)
	{
		ft_putendl_fd(g_ftssl_usage[key_dist].dist_title, STDERR_FILENO);
		g_ftssl_usage[key_dist].dist_dispatch(NULL);
	}
	return (EXIT_SUCCESS);
}
