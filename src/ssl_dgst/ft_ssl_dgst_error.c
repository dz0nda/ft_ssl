/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_error.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 04:10:49 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 14:27:46 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int     ft_ssl_dgst_error(char *cmd, char *arg, int err)
{
    const char *errors[FTSSL_DGST_ERR] = {
        "Unexpected error.",
        "illegal option -- ",
        "option requires an argument -- ",
        "No such file or directory"
    };

    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    if (err == FTSSL_DGST_ERR_OPT || err == FTSSL_DGST_ERR_ARG)
        ft_putstr_fd(errors[err], STDERR_FILENO);
    ft_putstr_fd(arg, STDERR_FILENO);
    if (err == FTSSL_DGST_ERR_OPT || err == FTSSL_DGST_ERR_ARG)
        ft_ssl_dgst_usage(cmd);
    else
        ft_putstr_fd(errors[err], STDERR_FILENO);
    return (EXIT_FAILURE);
}