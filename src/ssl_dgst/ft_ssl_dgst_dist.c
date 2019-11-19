/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_dist.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 17:49:26 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 19:56:43 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

t_ftssl_dgst_dist   g_ftssl_dgst_dist[FT_DGST_CMD] = {
    { "md5", 	FT_MD5      },
    { "sha1", 	FT_SHA1     },
    { "sha224", FT_SHA224   },
    { "sha256", FT_SHA256   },
    { "sha384", FT_SHA384   },
    { "sha512", FT_SHA512   }
};

int     ft_ssl_dgst_dispatch_dist(char *dist_name)
{
    int i;
    
    i = -1;
    while (++i < FT_DGST_CMD)
    {
        if (dist_name == NULL)
            ft_putendl_fd(dist_name, STDERR_FILENO);
        else
            if (ft_strcmp(dist_name, g_ftssl_dgst_dist[i].dist_name) == 0)
                break;
    }
    return (i);
}