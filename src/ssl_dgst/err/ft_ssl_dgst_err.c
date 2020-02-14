/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:22:52 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/14 16:29:18 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_ssl_dgst.h"

int   ft_ssl_dgst_err_filedir(char *cmd, char *arg, char *err_msg)
{
  ft_putstr_fd(cmd, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd(arg, STDERR_FILENO);
  ft_putendl_fd(err_msg, STDERR_FILENO);
  return (EXIT_FAILURE);
}

int   ft_ssl_dgst_err_opt(char *cmd, char *arg, char *err_msg)
{
  ft_putstr_fd(cmd, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd(err_msg, STDERR_FILENO);
  ft_putendl_fd(arg, STDERR_FILENO);
  ft_ssl_dgst_err_usage(cmd);
  return (EXIT_FAILURE);
}

int   ft_ssl_dgst_err_unexpected(char *cmd, char *arg, char *err_msg)
{
  ft_putstr_fd(cmd, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd(arg, STDERR_FILENO);
  ft_putendl_fd(err_msg, STDERR_FILENO);
  return (EXIT_FAILURE);
}
