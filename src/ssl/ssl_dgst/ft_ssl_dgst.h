/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:14:00 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/04 00:46:15 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../../crypto/dgst/ft_dgst.h"

# define FTSSL_DGST_MAX_BUFFER     8192

typedef struct  s_ftssl_dgst    t_ftssl_dgst;

typedef int     t_ftssl_dgst_opt(t_ftssl_dgst *, int);
typedef int     t_ftssl_dgst_err(t_ftssl_dgst *, char *);
typedef int     t_ftssl_dgst_outp(t_ftssl_dgst *);

typedef enum    s_ftssl_digest_key
{
    FTSSL_DGST_OUTP_DEFAULT,
    FTSSL_DGST_OUTP_QUIET,
    FTSSL_DGST_OUTP_REVERSE,
    FTSSL_DGST_OUTP_STRING,
    FTSSL_DGST_OUTP
}               e_ftssl_dgst_k;

typedef enum    s_ftssl_digest_err_key
{
    FTSSL_DGST_ERR_NO,
    FTSSL_DGST_ERR_OPT,
    FTSSL_DGST_ERR_OPT_ARG,
    FTSSL_DGST_ERR_FILE,
    FTSSL_DGST_ERR_DIR,
    FTSSL_DGST_ERR
}               t_ftssl_dgst_err_key;

typedef enum    s_ftssl_digest_opt_key
{
    FT_SSL_DGST_OPT_P,
    FT_SSL_DGST_OPT_Q,
    FT_SSL_DGST_OPT_R,
    FT_SSL_DGST_OPT_S,
    FT_SSL_DGST_OPT_MD5,
    FT_SSL_DGST_OPT_SHA1,
    FT_SSL_DGST_OPT_SHA224,
    FT_SSL_DGST_OPT_SHA256,
    FT_SSL_DGST_OPT_SHA384,
    FT_SSL_DGST_OPT_SHA512,
    FT_SSL_DGST_OPT
}               t_ftssl_dgst_opt_key;

typedef struct  s_ftssl_dgst_option_dispatch
{
    int                 opt_key;
    char                *opt_name;
    t_ftssl_dgst_opt    *opt_dist;
}               t_ftssl_dgst_opt_d;

typedef struct  s_ftssl_dgst_error_dispatch
{
    int                 err_key;
    char                *err_msg;
    t_ftssl_dgst_err    *err_dist;
}               t_ftssl_dgst_err_d;

typedef struct  s_ftssl_dgst_output_dispatch
{
    int                 outp_key;
    t_ftssl_dgst_outp   *outp_dist;
}               t_ftssl_dgst_outp_d;

typedef struct  s_ftssl_dgst_dist
{
    char        *dist_name;
    int         dist_key;
}               t_ftssl_dgst_dist;

typedef struct  s_ftssl_dgst_arg
{
    int         iarg;
    int         argc;
    char        **argv;
}               t_ftssl_dgst_args;

typedef struct  s_ftssl_dgst
{
    int                 iarg;
    int                 cmd_key;
    char                *cmd_name;
    char                *cmd_arg;
    int                 outp;
    int                 outp_key;
    int                 inpt_key;
    int                 opt_key;
    int                 err_key;
    int                 err_msg;
    char 	            md[FTSSL_DGST_MAX_BUFFER];
    t_ftssl_dgst_args   args;
}               t_ftssl_dgst;

typedef struct  s_ftssl_dgst_interface
{
    t_ftssl_dgst_dist   dist[FT_SHA_VERSION];
    t_ftssl_dgst_opt_d  opt[FT_SSL_DGST_OPT];
    t_ftssl_dgst_err_d  err[FTSSL_DGST_ERR];
    t_ftssl_dgst_outp_d outp[FTSSL_DGST_OUTP];
}               t_ftssl_dgst_i;

int     ft_ssl_dgst(int cmd_key, char *cmd_name, int argc, char *argv[]);
int			ft_ssl_dgst_exec(t_ftssl_dgst *ftssl_dgst);
/*
 *  DISPATCHER
*/

int     ft_ssl_dgst_dispatch_dist(char *dist_name);
int		ft_ssl_dgst_opt(t_ftssl_dgst *ftssl_dgst);
int     ft_ssl_dispatch_err(int err, t_ftssl_dgst *ftssl_dgst);
int	    ftssl_dgst_dispatch_outp(t_ftssl_dgst *ftssl_dgst, int ftssl_dgst_key);

/*
 *  PARSER
*/

int		ft_ssl_dgst_parse_opt(t_ftssl_dgst *ftssl_dgst);
int		ft_ssl_dgst_parse_arg(t_ftssl_dgst *ftssl_dgst);

/*
 *  OPT 
*/

int		ft_ssl_dgst_opt_p(t_ftssl_dgst *ftssl_dgst, int opt_key);
int		ft_ssl_dgst_opt_s(t_ftssl_dgst *ftssl_dgst, int opt_key);
int		ft_ssl_dgst_opt_outp(t_ftssl_dgst *ftssl_dgst, int opt_key);
int		ft_ssl_dgst_opt_dist(t_ftssl_dgst *ftssl_dgst, int opt_key);

/*
 *  ERR 
*/

int   ft_ssl_dgst_err_unexpected(t_ftssl_dgst *ftssl_dgst, char *err_msg);
int   ft_ssl_dgst_err_opt(t_ftssl_dgst *ftssl_dgst, char *err_msg);
int   ft_ssl_dgst_err_filedir(t_ftssl_dgst *ftssl_dgst, char *err_msg);
void  ft_ssl_dgst_err_usage(char *cmd);

/*
 *  OUTPUT 
*/

int	    ft_ssl_dgst_output(t_ftssl_dgst *ftssl_dgst);
int		ft_ssl_dgst_output_q(t_ftssl_dgst *ftssl_dgst);
int		ft_ssl_dgst_output_r(t_ftssl_dgst *ftssl_dgst);
int		ft_ssl_dgst_output_string(t_ftssl_dgst *ftssl_dgst);

#endif
