/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_opt_dist.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 21:22:25 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 21:22:29 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_ssl_dgst.h"

int		ft_ssl_dgst_opt_dist(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[], int opt_key)
{
	const int opt_dist[FT_DGST_CMD][2] = {
		{ FT_SSL_DGST_OPT_MD5, FT_MD5 },
		{ FT_SSL_DGST_OPT_SHA1, FT_SHA1 },
		{ FT_SSL_DGST_OPT_SHA224, FT_SHA224 },
		{ FT_SSL_DGST_OPT_SHA256, FT_SHA256 },
		{ FT_SSL_DGST_OPT_SHA384, FT_SHA384 },
		{ FT_SSL_DGST_OPT_SHA512, FT_SHA512 }
	};
    int i;

    i = -1;
	(void)argc;
	while (++i < FT_DGST_CMD)
		if (opt_key == opt_dist[i][0])
			break ;
	if (i == FT_DGST_CMD)
		return (EXIT_FAILURE);
	ftssl_dgst->cmd_key = opt_dist[i][1];
	if (argv[ftssl_dgst->iarg][0] == '-')
		ftssl_dgst->cmd_name = argv[ftssl_dgst->iarg] + 1;
	else
		ftssl_dgst->cmd_name = argv[ftssl_dgst->iarg];
	ftssl_dgst->iarg++;
	return (EXIT_SUCCESS);
}