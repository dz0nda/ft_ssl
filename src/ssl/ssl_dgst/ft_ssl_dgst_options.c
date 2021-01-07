/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/22 23:53:17 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

/*
 * 	Assign outp_dist and outp_flag only if FLAG_Q is not already set
*/

int		ft_ssl_dgst_opt_p(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	(void)opt_key;
	char buf[4096];
	char *s = NULL;
	char *tmp = NULL;
	int  nbuf = 0;
	int length = 0;

	length = ft_ssl_dgst_get_input(NULL, &s);
	// ftssl_dgst->inpt_key = FT_DGST_STRING;
	ftssl_dgst->cmd_arg = s;
	// ftssl_dgst->outp = FT_SSL_TRUE;
	ft_putstr(ftssl_dgst->cmd_arg);
	ft_ssl_dgst_exec(ftssl_dgst);
	ft_strdel(&ftssl_dgst->cmd_arg);
	// ftssl_dgst->outp = FT_SSL_FALSE;
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_opt_r(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	// if (ftssl_dgst->outp_key != FTSSL_DGST_OUTP_QUIET)
	ftssl_dgst->flag_r = 1;
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_opt_q(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	ftssl_dgst->outp_key = FTSSL_DGST_OUTP_QUIET;
	return (EXIT_SUCCESS);
}

/*
 * 	Assign cmd_arg and cmd_arg_len only if argv[i + 1] exists
 * 	Return fatal error for ssl_dgst instead
*/

int		ft_ssl_dgst_opt_s(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	t_ftssl_dgst_args *args;
	
	(void)opt_key;
	args = &ftssl_dgst->args;
	if (!(args->iarg + 1 < args->argc))
		return (ft_ssl_dgst_error(FTSSL_DGST_ERR_OPT_ARG, ftssl_dgst));
	ftssl_dgst->args.iarg++;
	// ftssl_dgst->inpt_key = FT_DGST_STRING;
	if (ftssl_dgst->outp_key != FTSSL_DGST_OUTP_QUIET)
		ftssl_dgst->outp_key = FTSSL_DGST_OUTP_STRING;
	ftssl_dgst->cmd_arg = (args->argv[args->iarg] == NULL) ? "" : args->argv[args->iarg];
	// ft_ssl_dgst_exec(ftssl_dgst);
	ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
	ft_hash(ftssl_dgst->cmd_key, (uint8_t *)ftssl_dgst->cmd_arg, ft_strlen(ftssl_dgst->cmd_arg), ftssl_dgst->md);
	ft_ssl_dgst_output(ftssl_dgst);

	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_option(t_ftssl_dgst *ftssl_dgst)
{
  t_ftssl_dgst_opt_d ft_ssl_dgst_opt[FT_SSL_DGST_OPT] = {
		{ FT_SSL_DGST_OPT_P, "p", ft_ssl_dgst_opt_p },
    { FT_SSL_DGST_OPT_Q, "q",	ft_ssl_dgst_opt_q },
    { FT_SSL_DGST_OPT_R, "r", ft_ssl_dgst_opt_r },
		{ FT_SSL_DGST_OPT_S, "s",	ft_ssl_dgst_opt_s },
  };
  int opt_key;
	char *opt;
  t_ftssl_dgst_args args = ftssl_dgst->args;

	opt_key = -1;
	opt = args.argv[args.iarg] + 1;
	while (++opt_key < 4)
		if (ft_strequ(opt, ft_ssl_dgst_opt[opt_key].opt_name))
			return (ft_ssl_dgst_opt[opt_key].opt_dist(ftssl_dgst, ft_ssl_dgst_opt[opt_key].opt_key));
	if (ft_ssl_dgst_dist(args.argc, args.argv, ftssl_dgst) != FT_SSL_DGST_NOT_FOUND)
			return (EXIT_SUCCESS);
	return (ft_ssl_dgst_error(FTSSL_DGST_ERR_OPT, ftssl_dgst));
}
