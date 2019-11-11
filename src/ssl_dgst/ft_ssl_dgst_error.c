/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_error.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 04:10:49 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 01:42:39 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int     ft_ssl_dgst_error_opt(char *cmd, char *opt)
{
    ft_putstr(cmd);
    ft_putstr(": illegal option -- ");
    ft_putendl(opt);
    ft_ssl_dgst_usage(cmd);
    return (EXIT_FAILURE);
}

int     ft_ssl_dgst_error_opt_arg(char *cmd, char *opt)
{
    ft_putstr(cmd);
    ft_putstr(": option requires an argument -- ");
    ft_putendl(opt);
    ft_ssl_dgst_usage(cmd);
    return (EXIT_FAILURE);
}

int     ft_ssl_dgst_error_file(char *cmd, char *arg)
{
    ft_putstr(cmd);
    ft_putstr(": ");
    ft_putstr(arg);
    ft_putendl(": error to access file");
    return (EXIT_FAILURE);
}