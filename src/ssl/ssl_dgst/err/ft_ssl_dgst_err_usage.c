/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_err_usage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:22:16 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/14 16:20:04 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_ssl_dgst.h"

void     ft_ssl_dgst_err_usage(char *cmd)
{
    ft_putstr_fd("usage: ", STDERR_FILENO);
    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putendl_fd(" [-pqr] [-s string] [files ...]", STDERR_FILENO);
}
