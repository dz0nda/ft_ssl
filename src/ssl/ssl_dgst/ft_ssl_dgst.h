/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:14:00 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/11 18:27:59 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../../crypto/dgst/ft_dgst.h"

# define FTSSL_DGST_MAX_BUFFER      8192
# define FT_SSL_DGST_NOT_FOUND      -42

typedef struct  s_ftssl_dgst    t_ftssl_dgst;

typedef int     t_ftssl_dgst_opt(t_ftssl_dgst *, int, char *[]);
typedef int     t_ftssl_dgst_err(t_ftssl_dgst *, char *);
typedef int     t_ftssl_dgst_error(int, char *, char *);
typedef int     t_ftssl_dgst_outp(t_ftssl_dgst *);

typedef enum    s_ftssl_digest_key
{
    FTSSL_DGST_OUTP_DEFAULT,
    FTSSL_DGST_OUTP_QUIET,
    FTSSL_DGST_OUTP_STRING,
    FTSSL_DGST_OUTP_FILE,
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

typedef struct  s_ftssl_dgst_errorno
{
    int                 err_key;
    t_ftssl_dgst_error    *err_dist;
}               s_ftssl_dgst_errorno;

typedef struct  s_ftssl_dgst_output_dispatch
{
    int                 outp_key;
    t_ftssl_dgst_outp   *outp_dist;
}               t_ftssl_dgst_outp_d;



typedef struct  s_ftssl_dgst_dist
{
    int                 key;
    char                *name;
    t_dgst_init    *init;
    t_dgst_pre_process  *pre_process;
    t_dgst_process         *hash;
    t_dgst_final   *final;
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
    int                 argi;
    int                 cmd_key;
    char                *cmd_arg;
    t_ftssl_dgst_dist   dist;
    int                 inpt_key;
    int                 outp_key;
    int                 flag_r;
    int                 flag_q;
    char 	            md[FTSSL_DGST_MAX_BUFFER];
    // t_ftssl_dgst_args   args;
    int                 err;
}               t_ftssl_dgst;

typedef struct  s_ftssl_dgst_interface
{
    t_ftssl_dgst_dist   dist[FT_DGST_VERSION];
    t_ftssl_dgst_opt_d  opt[FT_SSL_DGST_OPT];
    t_ftssl_dgst_err_d  err[FTSSL_DGST_ERR];
    t_ftssl_dgst_outp_d outp[FTSSL_DGST_OUTP];
}               t_ftssl_dgst_i;

int     ft_ssl_dgst(int argc, char *argv[]);
int			ft_ssl_dgst_exec(t_ftssl_dgst *ftssl_dgst);
int		ft_ssl_dgst_get_input(char *file, char **input);

int     ft_ssl_dgst_dist(int argc, char *argv[], t_ftssl_dgst *ftssl_dgst);
char    *ft_ssl_dgst_dist_execute(uint8_t *msg, unsigned int msg_len, char *md, t_ftssl_dgst *ftssl_dgst);

int		ft_ssl_dgst_option(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[]);
int     ft_ssl_dgst_error(int err_key, t_ftssl_dgst *ftssl_dgst);
int     ft_ssl_dgst_output(t_ftssl_dgst *ftssl_dgst);


#endif
