/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_arg.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 08:15:48 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 08:17:12 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_arg(t_ftssl_dgst *ftssl_dgst, char *arg)
{
	struct stat	st;

	ft_memset(&st, 0, sizeof(st));
	if (lstat(arg, &st) == 0)
	{
		if (S_ISREG(st.st_mode))
		{
			ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
			ft_dgst_file(ftssl_dgst->cmd_key, arg, FT_SSL_FALSE, ftssl_dgst->md);
			ftssl_dgst->outp_dist(ftssl_dgst->cmd_name, arg, 0, ftssl_dgst->md);
		}
		else if (S_ISDIR(st.st_mode))
			return (ft_ssl_dgst_error_dir(ftssl_dgst->cmd_name, arg));
	}
	else
		return (ft_ssl_dgst_error_file(ftssl_dgst->cmd_name, arg));
	return (EXIT_SUCCESS);
}