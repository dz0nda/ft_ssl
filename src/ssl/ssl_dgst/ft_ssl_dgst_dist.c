/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/18 13:48:32 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ssl_dgst.h"

t_ftssl_dgst_dist   g_ftssl_dgst_dist[FT_SHA_VERSION] = {
    { "md5", 	FT_MD5      },
    { "sha1", 	FT_SHA1     },
    { "sha224", FT_SHA224   },
    { "sha256", FT_SHA256   },
    { "sha384", FT_SHA384   },
    { "sha512", FT_SHA512   },
    { "sha512224", FT_SHA512224 },
    { "sha512256", FT_SHA512256 }
};

t_ftssl_dgst_i  g_ftssl_dgst_i = {
    .dist = {
        { "md5", 	FT_MD5      },
        { "sha1", 	FT_SHA1     },
        { "sha224", FT_SHA224   },
        { "sha256", FT_SHA256   },
        { "sha384", FT_SHA384   },
        { "sha512", FT_SHA512   },
        { "sha512224", FT_SHA512224 },
        { "sha512256", FT_SHA512256 }
    },
    .outp = {
        { FTSSL_DGST_OUTP_DEFAULT, ft_ssl_dgst_output   },
        { FTSSL_DGST_OUTP_QUIET, ft_ssl_dgst_output_q   },
        { FTSSL_DGST_OUTP_REVERSE, ft_ssl_dgst_output_r },
        { FTSSL_DGST_OUTP_STRING, ft_ssl_dgst_output_string }
    }
};

int     ft_ssl_dgst_dist(int argc, char *argv[], t_ftssl_dgst *ftssl_dgst)
{
    int cmd_key;

    cmd_key = -1;
    if (ft_strequ(argv[0], ""))
        return (FT_SSL_DGST_NOT_FOUND);
    while (++cmd_key < FT_SHA_VERSION)
        if (ft_strequ(argv[0], g_ftssl_dgst_dist[cmd_key].dist_name))
        {
            ftssl_dgst->cmd_key = cmd_key;
            ftssl_dgst->cmd_name = g_ftssl_dgst_dist[cmd_key].dist_name;
            ftssl_dgst->args.argc = argc - 1;
	        ftssl_dgst->args.argv = argv + 1;
            return (cmd_key);
        }
    return (FT_SSL_DGST_NOT_FOUND);
}

int     ft_ssl_dgst_dispatch_dist(char *dist_name)
{
    int i;

    i = -1;
    while (++i < FT_SHA_VERSION)
    {
        if (dist_name == NULL)
            ft_putendl_fd(dist_name, STDERR_FILENO);
        else
            if (ft_strequ(dist_name, g_ftssl_dgst_dist[i].dist_name))
                break;
    }
    return (i);
}

int	    ftssl_dgst_dispatch_outp(t_ftssl_dgst *ftssl_dgst, int ftssl_dgst_key)
{
    int i;
    t_ftssl_dgst_outp_d *outp_d;
     
    i = -1;
    outp_d = g_ftssl_dgst_i.outp;
    while (++i < FTSSL_DGST_OUTP)
        if (ftssl_dgst_key == outp_d[i].outp_key)
            break;
    return (outp_d[i].outp_dist(ftssl_dgst));
}