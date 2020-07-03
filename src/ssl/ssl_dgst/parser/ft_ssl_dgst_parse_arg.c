/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_parse_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:05:36 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/21 00:26:18 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_dgst.h"

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

int			ft_ssl_dgst_parse_arg(t_ftssl_dgst *ftssl_dgst)
{	
	t_ftssl_dgst_args *args = &ftssl_dgst->args;

	ftssl_dgst->inpt_key = FT_DGST_FILE;
	if (ftssl_dgst->outp_key == FTSSL_DGST_OUTP_STRING)
		ftssl_dgst->outp_key = FTSSL_DGST_OUTP_DEFAULT;
	ftssl_dgst->outp = FT_SSL_FALSE;
	if (ft_isemptyarg(args->iarg, args->argc, ftssl_dgst->md))
	{
		ftssl_dgst->cmd_arg = NULL;
		ft_ssl_dgst_exec(ftssl_dgst);
	}
	else
		while (ft_isarg(args->iarg, args->argc))
		{
      if (ft_isreg(args->argv[args->iarg]))
			{
				ftssl_dgst->cmd_arg = args->argv[args->iarg];
        ft_ssl_dgst_exec(ftssl_dgst); 
			}
      else if (ft_isdir(args->argv[args->iarg]))
        ft_ssl_dispatch_err(FTSSL_DGST_ERR_DIR, ftssl_dgst);
      else
        ft_ssl_dispatch_err(FTSSL_DGST_ERR_FILE, ftssl_dgst);
			ftssl_dgst->iarg++;
			ftssl_dgst->args.iarg++;
		}
	return (EXIT_SUCCESS);
}