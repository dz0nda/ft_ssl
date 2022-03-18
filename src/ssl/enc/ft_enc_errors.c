/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_dist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/21 13:36:18 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enc.h"

int ft_enc_err_invalid_command(char* cmd) {
    ft_putstr_fd("ftssl:Error: ", STDERR_FILENO);
    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putendl_fd(" is an invalid command", STDERR_FILENO);
    return (FT_EXFAIL);
}

int ft_enc_err_invalid_hex(char* opt) {
    ft_putstr_fd("invalid hex ", STDERR_FILENO);
    ft_putstr_fd(opt, STDERR_FILENO);
    ft_putendl(" value\n");
    return (FT_EXFAIL);
}