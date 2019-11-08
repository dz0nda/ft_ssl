/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:14:00 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 21:50:31 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../dgst/ft_dgst.h"

# define FTSSL_DGST_MAX_BUFFER     8192

typedef struct      s_digest         t_dgst;
typedef struct      s_digest_context t_dgst_ctx;
typedef struct      s_digest_input   t_dgst_ipt;

typedef     int t_dgst_cmd_dist(int, int, char *[]);
typedef     int t_dgst_act_step(t_dgst_ctx *);
typedef     int t_dgst_act_model(t_dgst_ctx *);
typedef     int t_dgst_act_input(t_dgst_ctx *, t_dgst_ipt);


typedef     int  t_dgst_process(t_dgst_ctx *);
typedef     int  t_dgst_result(const char *, const char *);

typedef     int  t_dgst_output(t_dgst *, char *, int);
typedef     char t_dgst_file(const char *, char *);
typedef     char t_dgst_string(const void *, unsigned int, char *);


typedef     int  t_ftssl_dgst_handler(t_ftssl_dgst *);

typedef enum    s_digest_flag_enum
{
    FT_SSL_DGST_FLAG_P = 'p',
    FT_SSL_DGST_FLAG_Q = 'q',
    FT_SSL_DGST_FLAG_R = 'r',
    FT_SSL_DGST_FLAG_S = 's',
    FT_SSL_DGST_FLAG = 4
}               t_dgst_flag_outp_e;

typedef struct s_digest_dist
{
    t_dgst_process  *init;
    t_dgst_process  *transform;
    t_dgst_process  *final;
}              t_dgst_dist;

typedef struct s_ftssl_digest_output
{
    int             outp_flag;
    t_ftssl_dgst_outp   *outp_dist;
}               t_ftssl_dgst_outp;

typedef struct s_ftssl_dgst_option
{
    int                     opt_flag;
    t_ftssl_dgst_handler    *opt_dist;
}               t_ftssl_dgst_opt;


typedef struct s_ftssl_digest_input
{
    char    *cmd_name;
    char    *cmd_arg;
    int     cmd_arg_len;
    char    *cmd_dgst;
}               t_ftssl_dgst_inpt;

typedef struct s_ftssl_dgst
{
    int     iarg;
    int     jarg;
    int     argc;
    char    **argv;
    t_ftssl_dgst_inpt   inpt;
    t_ftssl_dgst_outp   outp;
}               t_ftssl_dgst;

typedef struct      s_digest
{
    int             cmd_key;
    char            *cmd_name;
    t_dgst_dist     dist;
    t_dgst_output   *output;
}                   t_dgst;

typedef struct      s_ftssl_digest_context
{
    t_dgst_dist     dgst_dist;
    t_dgst_ctx      dgst_ctx;
}                   t_ftssl_dgst_ctx;

typedef struct      s_ftssl_digest_dist_table
{
    int                 cmd_key;
    char                *cmd_name;
    t_ftssl_dgst_ctx    cmd_ctx;
}                   t_ftssl_dgst_dist_t;


int     ft_ssl_dgst(int argc, char *argv[]);

int     ft_ssl_dgst_init(t_dgst *ftssl_dgst, const char *cmd_name);

int		ft_ssl_dgst_mdsha(t_dgst *dgst, char *data, size_t len);

void    ft_ssl_dgst_usage(char *cmd);

int	    ft_ssl_dgst_result(t_dgst_ctx *ctx);
int		ft_ssl_dgst_result_q(t_dgst_ctx *ctx);
int		ft_ssl_dgst_result_r(t_dgst_ctx *ctx);

int	    ft_ssl_dgst_output(t_dgst *dgst, char *data, int len);
int		ft_ssl_dgst_output_q(t_dgst *dgst, char *data, int len);
int		ft_ssl_dgst_output_r(t_dgst *dgst, char *data, int len);

int     ft_ssl_dgst_error(char *cmd, char *err);
int     ft_ssl_dgst_error_opt(char *cmd, char opt);
int     ft_ssl_dgst_error_arg(char *cmd, char arg);

#endif
