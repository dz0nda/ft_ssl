/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_core_dispatch.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 22:34:27 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 00:25:38 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_core.h"

t_ftssl_core_    g_ftssl_core_dispatch_key[FT_CORE_KEY] = {
    { "help", FT_HELP }
};

int     ft_ssl_core_dispatch(char *dist_name)
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