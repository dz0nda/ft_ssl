/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:22:52 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/09 19:36:37 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_ssl_dgst.h"

int   ft_ssl_dgst_err_filedir(t_ftssl_dgst *ftssl_dgst, char *err_msg)
{
  ft_putstr_fd(ftssl_dgst->cmd_name, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd(ftssl_dgst->args.argv[ftssl_dgst->args.iarg], STDERR_FILENO);
  ft_putendl_fd(err_msg, STDERR_FILENO);
  return (EXIT_FAILURE);
}

int   ft_ssl_dgst_err_opt(t_ftssl_dgst *ftssl_dgst, char *err_msg)
{
  ft_putstr_fd(ftssl_dgst->cmd_name, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd(err_msg, STDERR_FILENO);
  ft_putendl_fd(ftssl_dgst->args.argv[ftssl_dgst->args.iarg], STDERR_FILENO);
  ft_ssl_dgst_err_usage(ftssl_dgst->cmd_name);
  return (EXIT_FAILURE);
}

int   ft_ssl_dgst_err_unexpected(t_ftssl_dgst *ftssl_dgst, char *err_msg)
{
  ft_putstr_fd(ftssl_dgst->cmd_name, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd(ftssl_dgst->args.argv[ftssl_dgst->args.iarg], STDERR_FILENO);
  ft_putendl_fd(err_msg, STDERR_FILENO);
  return (EXIT_FAILURE);
}
