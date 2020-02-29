/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_parse_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:05:36 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/19 21:05:53 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_dgst.h"

int		ft_isreg(char *arg)
{
	struct stat	st;

	ft_memset(&st, 0, sizeof(st));
	if (lstat(arg, &st) == 0 && S_ISREG(st.st_mode))
		return (1);
	return (0);
}

int		ft_isdir(char *arg)
{
	struct stat	st;

	ft_memset(&st, 0, sizeof(st));
	if (lstat(arg, &st) == 0 && S_ISDIR(st.st_mode))
		return (1);
	return (0);
}

int 		ft_isarg(int iarg, int argc)
{
	if (iarg < argc)
		return (1);
	return (0);
}

int 		ft_isemptyarg(int iarg, int argc, char *md)
{
	if (iarg == argc && ft_strlen(md) == 0)
		return (1);
	return (0);
}

int			ft_ssl_dgst_parse_arg(t_ftssl_dgst *ftssl_dgst, t_ftssl_dgst_args args)
{
	int err;
	
	err = EXIT_SUCCESS;
	if (ft_isemptyarg(ftssl_dgst->iarg, args.argc, ftssl_dgst->md))
	{
		ft_dgst(ftssl_dgst->cmd_key, NULL, FT_DGST_FILE, ftssl_dgst->md, FT_SSL_FALSE);
		// ft_dgst_file(ftssl_dgst->cmd_key, NULL, FT_SSL_FALSE, ftssl_dgst->md);
		ftssl_dgst_dispatch_outp(ftssl_dgst->cmd_name, NULL, 0, ftssl_dgst->md, ftssl_dgst->outp_key);
	}
	else
		while (ft_isarg(ftssl_dgst->iarg, args.argc))
		{
      if (ft_isreg(args.argv[ftssl_dgst->iarg]))
      {
        ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
				ft_dgst(ftssl_dgst->cmd_key, args.argv[ftssl_dgst->iarg], FT_DGST_FILE, ftssl_dgst->md, FT_SSL_FALSE);
        // ft_dgst_file(ftssl_dgst->cmd_key, args.argv[ftssl_dgst->iarg], FT_SSL_FALSE, ftssl_dgst->md);
        ftssl_dgst_dispatch_outp(ftssl_dgst->cmd_name, args.argv[ftssl_dgst->iarg], 0, ftssl_dgst->md, ftssl_dgst->outp_key);
      }
      else if (ft_isdir(args.argv[ftssl_dgst->iarg]))
        err = ft_ssl_dispatch_err(ftssl_dgst->cmd_name, args.argv[ftssl_dgst->iarg], FTSSL_DGST_ERR_DIR);
      else
        err = ft_ssl_dispatch_err(ftssl_dgst->cmd_name, args.argv[ftssl_dgst->iarg], FTSSL_DGST_ERR_FILE);

			// err = ft_ssl_dgst_arg(ftssl_dgst, argv[ftssl_dgst->iarg]);
			ftssl_dgst->iarg++;
		}
	return (EXIT_SUCCESS);
}