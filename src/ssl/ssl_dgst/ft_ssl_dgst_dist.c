/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/20 15:33:10 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ssl_dgst.h"

t_ftssl_dgst_dist   g_ftssl_dgst_dist[FT_HASH_VERSION] = {
    { "md5", 	    FT_MD5      },
    { "sha1", 	    FT_SHA1     },
    { "sha224",     FT_SHA224   },
    { "sha256",     FT_SHA256   },
    { "sha384",     FT_SHA384   },
    { "sha512",     FT_SHA512   },
    { "sha512224",  FT_SHA512224 },
    { "sha512256",  FT_SHA512256 }
};

int     ft_ssl_dgst_dist(int argc, char *argv[], t_ftssl_dgst *ftssl_dgst)
{
    int cmd_key;

    cmd_key = -1;
    if (argc != -42 && ft_strequ(argv[0], ""))
        return (FT_SSL_DGST_NOT_FOUND);
    while (++cmd_key < FT_HASH_VERSION)
    {
        if (argc == -42)
            ft_putendl_fd(g_ftssl_dgst_dist[cmd_key].dist_name, STDERR_FILENO);
        else if (ft_strequ(argv[0], g_ftssl_dgst_dist[cmd_key].dist_name))
        {
            ftssl_dgst->cmd_key = cmd_key;
            ftssl_dgst->cmd_name = g_ftssl_dgst_dist[cmd_key].dist_name;
            // ftssl_dgst->dist = g_ftssl_dgst_i.dist[cmd_key];
            ftssl_dgst->args.argc = argc - 1;
	        ftssl_dgst->args.argv = argv + 1;
            return (cmd_key);
        }
    }
    return (FT_SSL_DGST_NOT_FOUND);
}
