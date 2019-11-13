/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_error.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 04:10:49 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 14:38:35 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int     ft_ssl_dgst_error_opt(char *cmd, char *opt)
{
    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putstr_fd(": illegal option -- ", STDERR_FILENO);
    ft_putendl_fd(opt, STDERR_FILENO);
    ft_ssl_dgst_usage(cmd);
    return (EXIT_FAILURE);
}

int     ft_ssl_dgst_error_opt_arg(char *cmd, char *opt)
{
    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putstr_fd(": option requires an argument -- ", STDERR_FILENO);
    ft_putendl_fd(opt, STDERR_FILENO);
    ft_ssl_dgst_usage(cmd);
    return (EXIT_FAILURE);
}

int     ft_ssl_dgst_error_file(char *cmd, char *arg)
{
    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putstr_fd(arg, STDERR_FILENO);
    ft_putendl_fd(": No such file or directory", 2);
    return (EXIT_FAILURE);
}

int     ft_ssl_dgst_error_dir(char *cmd, char *arg)
{
    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putstr_fd(arg, STDERR_FILENO);
    ft_putendl_fd(": Is a directory", 2);
    return (EXIT_FAILURE);
}