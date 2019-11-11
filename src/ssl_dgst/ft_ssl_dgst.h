/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:14:00 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 18:13:50 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../dgst/ft_dgst.h"

# define FTSSL_DGST_MAX_BUFFER     8192

typedef struct  s_ftssl_dgst t_ftssl_dgst;

typedef int     t_ftssl_dgst_outp(char *, char *, int , char *);
typedef int     t_ftssl_dgst_opt(t_ftssl_dgst *, int, char *[], int);

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

typedef struct  s_ftssl_dgst_option_dispatch
{
    char                *opt_name;
    int                 opt_key;
    t_ftssl_dgst_opt    *opt_dist;
}               t_ftssl_dgst_opt_d;

typedef struct  s_ftssl_dgst
{
    int                 iarg;
    int                 cmd_key;
    char                *cmd_name;
    char 	            md[FTSSL_DGST_MAX_BUFFER];
    int                 outp_key;
    t_ftssl_dgst_outp   *outp_dist;
}               t_ftssl_dgst;

int     ft_ssl_dgst(int argc, char *argv[]);

int		ft_ssl_dgst_opt(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[]);

int	    ft_ssl_dgst_output(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *md);
int		ft_ssl_dgst_output_q(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *md);
int		ft_ssl_dgst_output_r(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *md);

int     ft_ssl_dgst_error_opt(char *cmd, char *opt);
int     ft_ssl_dgst_error_opt_arg(char *cmd, char *opt);
int     ft_ssl_dgst_error_file(char *cmd, char *arg);

void    ft_ssl_dgst_usage(char *cmd);

#endif
