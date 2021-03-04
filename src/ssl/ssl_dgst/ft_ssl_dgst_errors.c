/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/03 22:35:13 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

static void		ft_ssl_dgst_err_usage(char *cmd)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putendl_fd(" [-pqr] [-s string] [files ...]", STDERR_FILENO);
}

int				ft_ssl_dgst_err_fd(int err, char *dist, char *dist_arg)
{
	ft_putstr_fd(dist, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(dist_arg, STDERR_FILENO);
	if (err == FTSSL_DGST_ERR_FILE)
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	else
		ft_putendl_fd(": Is a directory", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int				ft_ssl_dgst_err_option(int err, char *dist, char *dist_arg)
{
	ft_putstr_fd(dist, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (err == FTSSL_DGST_ERR_OPT)
		ft_putstr_fd("illegal option -- ", STDERR_FILENO);
	else
		ft_putstr_fd("option requires an argument -- ", STDERR_FILENO);
	ft_putendl_fd(dist_arg, STDERR_FILENO);
	ft_ssl_dgst_err_usage(dist);
	return (EXIT_FAILURE);
}

int				ft_ssl_dgst_err_no(int err, char *dist, char *dist_arg)
{
	(void)err;
	ft_putstr_fd(dist, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(dist_arg, STDERR_FILENO);
	ft_putendl_fd("Unexpected error.", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int				ft_ssl_dgst_error(int err_key, t_ftssl_dgst *ctx, char *arg)
{
	const t_ftssl_dgst_err_d err[FTSSL_DGST_ERR] = {
		{ FTSSL_DGST_ERR_NO, ft_ssl_dgst_err_no },
		{ FTSSL_DGST_ERR_OPT, ft_ssl_dgst_err_option },
		{ FTSSL_DGST_ERR_OPT_ARG, ft_ssl_dgst_err_option },
		{ FTSSL_DGST_ERR_FILE, ft_ssl_dgst_err_fd },
		{ FTSSL_DGST_ERR_DIR, ft_ssl_dgst_err_fd }
	};

	return (err[err_key].err_dist(err_key, ctx->distrib.name_lower, arg));
}
