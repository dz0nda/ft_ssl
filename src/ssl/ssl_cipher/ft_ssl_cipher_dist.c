/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher_dist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/04 21:59:49 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ssl_cipher.h"

t_ftssl_cipher_dist   g_ftssl_cipher_dist[FT_CIPHER_CMD] = {
    { "base64", FT_BASE64 },
    { "des",    FT_DES }
};

int     ft_ssl_cipher_dispatch_dist(char *dist_name)
{
    int i;
    
    i = -1;
    while (++i < FT_CIPHER_CMD)
    {
        if (dist_name == NULL)
            ft_putendl_fd(dist_name, STDERR_FILENO);
        else
            if (ft_strcmp(dist_name, g_ftssl_cipher_dist[i].dist_name) == 0)
                break;
    }
    return (i);
}