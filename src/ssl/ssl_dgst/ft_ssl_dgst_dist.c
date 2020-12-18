/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/04 00:46:09 by dzonda           ###   ########lyon.fr   */
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
    .opt = {
		{ FT_SSL_DGST_OPT_P,        "p",        ft_ssl_dgst_opt_p	 },
        { FT_SSL_DGST_OPT_Q,        "q", 		ft_ssl_dgst_opt_outp },
        { FT_SSL_DGST_OPT_R,        "r", 		ft_ssl_dgst_opt_outp },
		{ FT_SSL_DGST_OPT_S,        "s", 	 	ft_ssl_dgst_opt_s  	 },
		{ FT_SSL_DGST_OPT_MD5,      "md5", 	    ft_ssl_dgst_opt_dist },
		{ FT_SSL_DGST_OPT_SHA1,     "sha1",     ft_ssl_dgst_opt_dist },
		{ FT_SSL_DGST_OPT_SHA224,   "sha224",   ft_ssl_dgst_opt_dist },
		{ FT_SSL_DGST_OPT_SHA256,   "sha256",   ft_ssl_dgst_opt_dist },
		{ FT_SSL_DGST_OPT_SHA384,   "sha384",   ft_ssl_dgst_opt_dist },
		{ FT_SSL_DGST_OPT_SHA512,   "sha512",   ft_ssl_dgst_opt_dist }
    },
    .err = {
        { FTSSL_DGST_ERR_NO,        "Unexpected error.",                ft_ssl_dgst_err_unexpected  },
        { FTSSL_DGST_ERR_OPT,       "illegal option -- ",               ft_ssl_dgst_err_opt         },
        { FTSSL_DGST_ERR_OPT_ARG,   "option requires an argument -- ",  ft_ssl_dgst_err_opt         },
        { FTSSL_DGST_ERR_FILE,      ": No such file or directory",      ft_ssl_dgst_err_filedir     },
        { FTSSL_DGST_ERR_DIR,       ": Is a directory",                 ft_ssl_dgst_err_filedir     }
    },
    .outp = {
        { FTSSL_DGST_OUTP_DEFAULT, ft_ssl_dgst_output   },
        { FTSSL_DGST_OUTP_QUIET, ft_ssl_dgst_output_q   },
        { FTSSL_DGST_OUTP_REVERSE, ft_ssl_dgst_output_r },
        { FTSSL_DGST_OUTP_STRING, ft_ssl_dgst_output_string }
    }
};

int     ft_ssl_dgst_dispatch_dist(char *dist_name)
{
    int i;

    i = -1;
    while (++i < FT_SHA_VERSION)
    {
        if (dist_name == NULL)
            ft_putendl_fd(dist_name, STDERR_FILENO);
        else
            if (ft_strcmp(dist_name, g_ftssl_dgst_dist[i].dist_name) == 0)
                break;
    }
    return (i);
}

int		ft_ssl_dgst_opt(t_ftssl_dgst *ftssl_dgst)
{
    int i;
	char *opt;
    t_ftssl_dgst_opt_d *opt_d;
    t_ftssl_dgst_args args = ftssl_dgst->args;

	i = -1;
    opt_d = g_ftssl_dgst_i.opt;
	if (ftssl_dgst->cmd_name == NULL)
		opt = args.argv[args.iarg];
	else
		opt = args.argv[args.iarg] + 1;
	while (++i < FT_SSL_DGST_OPT)
		if (ft_strcmp(opt, opt_d[i].opt_name) == 0)
			return (opt_d[i].opt_dist(ftssl_dgst, opt_d[i].opt_key));
	return (ft_ssl_dispatch_err(FTSSL_DGST_ERR_OPT, ftssl_dgst));
}

int     ft_ssl_dispatch_err(int err, t_ftssl_dgst *ftssl_dgst)
{
    int i;
    t_ftssl_dgst_err_d *err_d;

	i = -1;
    err_d = g_ftssl_dgst_i.err;
    while (++i < FTSSL_DGST_ERR)
        if (err == err_d[i].err_key)
            break;
    return (err_d[i].err_dist(ftssl_dgst, err_d[i].err_msg));
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