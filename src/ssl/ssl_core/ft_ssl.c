/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:12:50 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/04 00:46:09 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_core.h"

const t_ftssl_dist_t		g_ftssl_dist[FTSSL_DIST_MAX] = {
	{ FTSSL_CORE, ft_ssl_core_dispatch_dist, FT_CORE_CMD, ft_ssl_core },
	{ FTSSL_DGST, ft_ssl_dgst_dispatch_dist, FT_SHA_VERSION, ft_ssl_dgst },
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

static int						ft_ssl_dispatch(int argc, char *argv[])
{
	int		key_dist;
	int		key_cmd;

	key_dist = -1;
	key_cmd = -1;
	if (argv[0] == NULL)
		return (EXIT_SUCCESS);
	while (++key_dist < FTSSL_DIST_MAX)
	{
		if ((key_cmd = g_ftssl_dist[key_dist].dist_check(argv[0]))
					!= g_ftssl_dist[key_dist].dist_dispatch_max)
			return (g_ftssl_dist[key_dist].dist_ft(key_cmd, argv[0], argc - 1, argv + 1));
	}
	return (ft_ssl_error(argc, argv));
}

int			ft_ssl(int argc, const char *argv[])
{
		t_ftssl	ftssl;

		ft_memset(&ftssl, 0, sizeof(ftssl));			


		return (ftssl.err);
}

int			main(int argc, const char *argv[])
{
		t_ftssl	ftssl;

		ft_memset(&ftssl, 0, sizeof(ftssl));			
		ft_ssl_shell_init(&ftssl.sh, argc - 1, ++argv);
		while (42)
		{
			if (ftssl.shmode == FTSSL_SHMODE_ENABLED)
				if (ft_ssl_shell(&ftssl.sh) == EXIT_FAILURE)
					break ;
			ftssl.err = ft_ssl_dispatch(ftssl.sh.argc, ftssl.sh.argv);
			if (ftssl.shmode == FTSSL_SHMODE_DISABLED)
				break ;
		}
		ft_ssl_shell_reset(&ftssl.sh);
		return (ftssl.err);
}
