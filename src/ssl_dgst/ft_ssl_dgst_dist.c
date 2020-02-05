/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_dist.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 17:49:26 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 22:06:42 by dzonda      ###    #+. /#+    ###.fr     */
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

t_ftssl_dgst_i  g_ftssl_dgst_i = {
    .dist = {
        { "md5", 	FT_MD5      },
        { "sha1", 	FT_SHA1     },
        { "sha224", FT_SHA224   },
        { "sha256", FT_SHA256   },
        { "sha384", FT_SHA384   },
        { "sha512", FT_SHA512   }
    },
    .opt = {
		{ "p", 		FT_SSL_DGST_OPT_P, 		ft_ssl_dgst_opt_p	 },
        { "q", 		FT_SSL_DGST_OPT_Q, 		ft_ssl_dgst_opt_outp },
        { "r", 		FT_SSL_DGST_OPT_R, 		ft_ssl_dgst_opt_outp },
		{ "s", 		FT_SSL_DGST_OPT_S, 		ft_ssl_dgst_opt_s  	 },
		{ "md5", 	FT_SSL_DGST_OPT_MD5, 	ft_ssl_dgst_opt_dist },
		{ "sha1", 	FT_SSL_DGST_OPT_SHA1, 	ft_ssl_dgst_opt_dist },
		{ "sha224", FT_SSL_DGST_OPT_SHA224, ft_ssl_dgst_opt_dist },
		{ "sha256", FT_SSL_DGST_OPT_SHA256, ft_ssl_dgst_opt_dist },
		{ "sha384", FT_SSL_DGST_OPT_SHA384, ft_ssl_dgst_opt_dist },
		{ "sha512", FT_SSL_DGST_OPT_SHA512, ft_ssl_dgst_opt_dist }
    }
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

int		ft_ssl_dgst_opt(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[])
{
    int i;
	char *opt;
    t_ftssl_dgst_opt_d *opt_d;   

	i = -1;
    opt_d = g_ftssl_dgst_i.opt;
	if (ftssl_dgst->cmd_name == NULL)
		opt = argv[ftssl_dgst->iarg];
	else
		opt = argv[ftssl_dgst->iarg] + 1;
	while (++i < FT_SSL_DGST_OPT)
		if (ft_strcmp(opt, opt_d[i].opt_name) == 0)
			return ((opt_d)[i].opt_dist(ftssl_dgst, argc, argv, opt_d[i].opt_key));
	return (ft_ssl_dgst_error(ftssl_dgst->cmd_name, opt, FTSSL_DGST_ERR_OPT));
}
