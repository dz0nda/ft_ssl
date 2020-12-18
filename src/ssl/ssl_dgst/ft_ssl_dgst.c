/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:05:36 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/18 12:49:46 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

static int			ft_isopt(t_ftssl_dgst_args args)
{
	if (args.iarg < args.argc)
		if (*args.argv[args.iarg] == '-' && args.argv[args.iarg][1] != '\0')
			return (1);
	return (0);
}

int 		ft_isemptyarg(int iarg, int argc, char *md)
{
	if (iarg == argc && ft_strlen(md) == 0)
		return (1);
	return (0);
}

int 		ft_isarg(int iarg, int argc)
{
	if (iarg < argc)
		return (1);
	return (0);
}

int			ft_ssl_dgst_exec(t_ftssl_dgst *ftssl_dgst)
{
	ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
	ft_dgst(ftssl_dgst->cmd_key, ftssl_dgst->cmd_arg, ftssl_dgst->inpt_key, ftssl_dgst->md, ftssl_dgst->outp);
	ftssl_dgst_dispatch_outp(ftssl_dgst, ftssl_dgst->outp_key);
	ftssl_dgst->inpt_key = FT_DGST_FILE;
	if (ftssl_dgst->outp_key == FTSSL_DGST_OUTP_STRING)
		ftssl_dgst->outp_key = FTSSL_DGST_OUTP_DEFAULT;
	ftssl_dgst->outp = FT_SSL_FALSE;
	return (EXIT_SUCCESS);
}

int     ft_ssl_dgst(int cmd_key, char *cmd_name, int argc, char *argv[])
{
	t_ftssl_dgst			ftssl_dgst;

	ft_memset(&ftssl_dgst, 0, sizeof(ftssl_dgst));
	// ftssl_dgst.cmd_key = cmd_key;
	// ftssl_dgst.cmd_name = cmd_name;
	// ftssl_dgst.args.argc = argc;
	// ftssl_dgst.args.argv = argv;
	// if (ft_ssl_dgst_init(ftssl_dgst))

	// if (ft_ssl_dgst_parse_opt(&ftssl_dgst) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	if (ft_ssl_dgst_dist(argc, argv, &ftssl_dgst) == FT_SSL_DGST_NOT_FOUND)
		return (FT_SSL_DGST_NOT_FOUND);
	// ftssl_dgst.args.argc = argc - 1;
	// ftssl_dgst.args.argv = argv + 1;
	while (ft_isopt(ftssl_dgst.args))
	{
		if (ft_ssl_dgst_option(&ftssl_dgst) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ftssl_dgst.args.iarg++;
	}
	ftssl_dgst.cmd_arg = NULL;
	if (ft_isemptyarg(ftssl_dgst.args.iarg, ftssl_dgst.args.argc, ftssl_dgst.md))
		return (ft_ssl_dgst_exec(&ftssl_dgst));
	while (ft_isarg(ftssl_dgst.args.iarg, ftssl_dgst.args.argc))
	{
		ftssl_dgst.cmd_arg = ftssl_dgst.args.argv[ftssl_dgst.args.iarg];
		if (ft_isreg(ftssl_dgst.cmd_arg))
			ft_ssl_dgst_exec(&ftssl_dgst);
		else if (ft_isdir(ftssl_dgst.cmd_arg))
			ft_ssl_dgst_error(FTSSL_DGST_ERR_DIR, &ftssl_dgst);
		else
			ft_ssl_dgst_error(FTSSL_DGST_ERR_FILE, &ftssl_dgst);
		ftssl_dgst.args.iarg++;
	}
	// if (ft_ssl_dgst_parse_arg(&ftssl_dgst) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
