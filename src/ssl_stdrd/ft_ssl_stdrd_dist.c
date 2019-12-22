/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_stdrd_dist.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 18:12:30 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 19:56:52 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_stdrd.h"

t_ftssl_stdrd_dist   g_ftssl_stdrd_dist[FT_STDRD_CMD] = {
    { "dgst", FT_DGST }
};

int     ft_ssl_stdrd_dispatch_dist(char *dist_name)
{
    int i;
    
    i = -1;
    while (++i < FT_STDRD_CMD)
    {
        if (dist_name == NULL)
            ft_putendl_fd(dist_name, STDERR_FILENO);
        else
            if (ft_strcmp(dist_name, g_ftssl_stdrd_dist[i].dist_name) == 0)
                break;
    }
    return (i);
}