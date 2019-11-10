/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_error.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 04:10:49 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 17:48:43 by dzonda      ###    #+. /#+    ###.fr     */
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
