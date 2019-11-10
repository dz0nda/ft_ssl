/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:14:00 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 17:55:10 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../dgst/ft_dgst.h"

# define FTSSL_DGST_MAX_BUFFER     8192

typedef struct  s_ftssl_dgst t_ftssl_dgst;

typedef int     t_ftssl_dgst_opt_handler(t_ftssl_dgst *, int);
typedef int     t_ftssl_dgst_outp_handler(t_ftssl_dgst *);

typedef enum    s_ftssl_digest_opt_key
{
    FT_SSL_DGST_OPT_P,
    FT_SSL_DGST_OPT_Q,
    FT_SSL_DGST_OPT_R,
    FT_SSL_DGST_OPT_S,
    FT_SSL_DGST_OPT_MD5,
    FT_SSL_DGST_OPT_SHA1,
    FT_SSL_DGST_OPT_SHA256,
    FT_SSL_DGST_OPT_SHA384,
    FT_SSL_DGST_OPT_SHA512,
    FT_SSL_DGST_OPT
}               t_ftssl_dgst_opt_key;

typedef struct s_ftssl_dgst_option_dist
{
    char    *opt_name;
    int     dist_key;
}               t_ftssl_dgst_opt_dist;

typedef struct s_ftssl_dgst_option
{
    char                        *opt_name;
    int                         opt_key;
    t_ftssl_dgst_opt_handler    *opt_dist;
}               t_ftssl_dgst_opt;

typedef struct s_ftssl_digest_input
{
    int     i;
    int     argc;
    char    **argv;
}               t_ftssl_dgst_inpt;

typedef struct s_ftssl_dgst_context
{
    int     cmd_key;
    char    *cmd_name;
    char    *cmd_arg;
    int     cmd_arg_len;
    char    cmd_dgst[FTSSL_DGST_MAX_BUFFER];
}              t_ftssl_dgst_ctx;

typedef struct s_ftssl_digest_output
{
    int                 outp_flag;
    t_ftssl_dgst_outp_handler   *outp_dist;
}               t_ftssl_dgst_outp;

typedef struct s_ftssl_dgst
{
    t_ftssl_dgst_inpt   inpt;
    t_ftssl_dgst_ctx    ctx;
    t_ftssl_dgst_outp   outp;
}               t_ftssl_dgst;

int     ft_ssl_dgst(int argc, char *argv[]);

int		ft_ssl_dgst_init(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[]);
int     ft_ssl_dgst_exec(t_ftssl_dgst *ftssl_dgst);

int		ft_ssl_dgst_parse_opt(t_ftssl_dgst *ftssl_dgst);
int		ft_ssl_dgst_parse_arg(t_ftssl_dgst *ftssl_dgst);
int		ft_ssl_dgst_parse_options_p(t_ftssl_dgst *ftssl_dgst, int opt_key);

int		ft_ssl_dgst_opt(t_ftssl_dgst *ftssl_dgst, char *opt);

void    ft_ssl_dgst_usage(char *cmd);

int	    ft_ssl_dgst_output(t_ftssl_dgst *ftssl_dgst);
int		ft_ssl_dgst_output_q(t_ftssl_dgst *ftssl_dgst);
int		ft_ssl_dgst_output_r(t_ftssl_dgst *ftssl_dgst);

int     ft_ssl_dgst_error(char *cmd, char *err);
int     ft_ssl_dgst_error_opt(char *cmd, char *opt);
int     ft_ssl_dgst_error_opt_arg(char *cmd, char *opt);

#endif
