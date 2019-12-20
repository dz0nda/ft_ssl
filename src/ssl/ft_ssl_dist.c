/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dist.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:13:04 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 14:10:28 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

const t_ftssl_dist_t	g_ftssl_dist[FTSSL_DIST_E] = {
	{ FTSSL_CORE, ft_ssl_core_dispatch_dist, FT_CORE_CMD, ft_ssl_core },
	{ FTSSL_DGST, ft_ssl_dgst_dispatch_dist, FT_DGST_CMD, ft_ssl_dgst },
	{ FTSSL_CIPHER, ft_ssl_cipher_dispatch_dist, FT_CIPHER_CMD, ft_ssl_cipher },
	{ FTSSL_STDRD, ft_ssl_stdrd_dispatch_dist, FT_STDRD_CMD, ft_ssl_stdrd }
};

static int		ft_ssl_error(int argc, char *argv[])
{
	(void)argc;
	ft_putstr_fd("ftssl:Error: '", STDERR_FILENO);
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putendl_fd("' is an invalid command.", STDERR_FILENO);
	ft_ssl_usage();
	return (EXIT_SUCCESS);
}

int			ft_ssl_dispatch(int argc, char *argv[])
{
	int		key_dist;
	int		key_cmd;

	key_dist = -1;
	key_cmd = -1;
	if (argv[0] == NULL)
		return (EXIT_SUCCESS);
	while (++key_dist < FTSSL_DIST_E)
	{
		if ((key_cmd = g_ftssl_dist[key_dist].dist_check(argv[0]))
					!= g_ftssl_dist[key_dist].dist_dispatch_max)
			return (g_ftssl_dist[key_dist].dist_ft(key_cmd, argv[0], argc - 1, argv + 1));
	}
	return (ft_ssl_error(argc, argv));
}
