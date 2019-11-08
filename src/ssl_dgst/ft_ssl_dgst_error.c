/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_error.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 04:10:49 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 19:08:20 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int     ft_ssl_dgst_error(char *cmd, char *err)
{
    ft_putstr(cmd);
    ft_putstr(": illegal option -- ");
    ft_putendl(err);
    ft_ssl_dgst_usage(cmd);
    return (EXIT_SUCCESS);
}

int     ft_ssl_dgst_error_opt(char *cmd, char opt)
{
    ft_putstr(cmd);
    ft_putstr(": illegal option -- ");
    ft_putendl(opt);
    ft_ssl_dgst_usage(cmd);
    return (EXIT_SUCCESS);
}

int     ft_ssl_dgst_error_arg(char *cmd, char opt)
{
    ft_putstr(cmd);
    ft_putstr(": option requires an argument -- ");
    ft_putendl(opt);
    ft_ssl_dgst_usage(cmd);
    return (EXIT_SUCCESS);
}