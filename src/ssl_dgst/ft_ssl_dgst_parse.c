/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_parse.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 08:15:56 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 10:01:18 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_parse_opt(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[])
{
	while (ftssl_dgst->iarg < argc && *argv[ftssl_dgst->iarg] == '-')
	{
		if (argv[ftssl_dgst->iarg][1] == '\0')
			break ;
		if (ft_ssl_dgst_opt(ftssl_dgst, argc, argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_parse_arg(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[])
{
	struct stat	st;
	int err;
	
	err = EXIT_SUCCESS;
	ft_memset(&st, 0, sizeof(st));
	if (ftssl_dgst->iarg == argc && ft_strlen(ftssl_dgst->md) == 0)
	{
		// ft_dgst_file(ftssl_dgst->cmd_key, NULL, FT_SSL_FALSE, ftssl_dgst->md);
		ft_dgst_file(ftssl_dgst->cmd_key, NULL, FT_SSL_FALSE, ftssl_dgst->md);
		ftssl_dgst->outp_dist(ftssl_dgst->cmd_name, NULL, 0, ftssl_dgst->md);
	}
	else
		while (ftssl_dgst->iarg < argc)
		{
			err = ft_ssl_dgst_arg(ftssl_dgst, argv[ftssl_dgst->iarg]);
			ftssl_dgst->iarg++;
		}
	return (err);
}