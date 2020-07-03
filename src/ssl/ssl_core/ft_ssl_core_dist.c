/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_core_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:11:08 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/03 21:11:42 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_core.h"

t_ftssl_core_dist           g_ftssl_core_dist[FT_CORE_CMD] = {
    { "help", FT_HELP }
};

int     ft_ssl_core_dispatch_dist(char *dist_name)
{
    int i;
    
    i = -1;
    while (++i < FT_CORE_CMD)
    {
        if (dist_name == NULL)
            ft_putendl(dist_name);
        else
            if (ft_strcmp(dist_name, g_ftssl_core_dist[i].dist_name) == 0)
                break;
    }
    return (i);
}