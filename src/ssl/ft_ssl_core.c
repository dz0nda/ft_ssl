/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_core.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 13:01:39 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 14:10:05 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ftssl_core_dist           g_ftssl_core_dist[FT_CORE_CMD] = {
    { "help", FT_HELP }
};

t_ftssl_core_usage_dist		g_ftssl_usage[FTSSL_DIST_E] = {
	{ "Help commands:",  ft_ssl_core_dispatch_dist },
	{ "Message Digest commands:", ft_ssl_dgst_dispatch_dist },
	{ "Cipher commands:", ft_ssl_cipher_dispatch_dist },
	{ "Standard commands:", ft_ssl_stdrd_dispatch_dist }
};

int		ft_ssl_usage(void)
{
	int			key_dist;
	
	key_dist = -1;
	while (++key_dist < FTSSL_DIST_E)
	{
		ft_putendl_fd(g_ftssl_usage[key_dist].dist_title, STDERR_FILENO);
		g_ftssl_usage[key_dist].dist_check(NULL);
	}
	return (EXIT_SUCCESS);
}

int     ft_ssl_core_dispatch_dist(char *dist_name)
{
    int i;
    
    i = -1;
    while (++i < FT_CORE_CMD)
    {
        if (dist_name == NULL)
            ft_putendl(dist_name);
        else
            if (ft_strcmp(dist_name, g_ftssl_core_dist[i].dist_name) == 0)
                break;
    }
    return (i);
}

int     ft_ssl_core(int cmd_key, char *cmd_name, int argc, char *argv[])
{
    (void)cmd_key;
	(void)cmd_name;
	(void)argc;
	(void)argv;
    return (ft_ssl_usage());
}