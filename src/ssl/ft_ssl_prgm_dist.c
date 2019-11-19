/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_prgm_dist.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 19:21:56 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 20:08:41 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ftssl_prgm_dist   g_ftssl_prgm_dist[FT_PRGM_CMD] = {
    { "help", FT_HELP }
};

int     ft_ssl_prgm_dispatch_dist(char *dist_name)
{
    int i;
    
    i = -1;
    while (++i < FT_PRGM_CMD)
    {
        if (dist_name == NULL)
            ft_putendl(dist_name);
        else
            if (ft_strcmp(dist_name, g_ftssl_prgm_dist[i].dist_name) == 0)
                break;
    }
    return (i);
}