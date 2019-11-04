/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:14:00 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 22:40:19 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../dgst/ft_dgst.h"

# define        FT_DGST_MAX_STDIN 1024

typedef struct      s_digest_context t_dgst_ctx;
typedef struct      s_digest_input   t_dgst_ipt;

typedef     int t_dgst_cmd_dist(int, int, char *[]);
typedef     int t_dgst_act_step(t_dgst_ctx *);
typedef     int t_dgst_act_model(t_dgst_ctx *);
typedef     int t_dgst_act_input(t_dgst_ctx *, t_dgst_ipt);


typedef     int  t_dgst_process(t_dgst_ctx *);
typedef     char t_dgst_file(const char *, char *);
typedef     char t_dgst_string(const void *, unsigned int, char *);

typedef enum    s_digest_command_enum
{
    FT_MD5,
    FT_SHA1,
    FT_SHA256,
    FT_DGST_CMD
}               t_dgst_cmd_e;

typedef struct s_digest_dist
{
    t_dgst_process  *init;
    t_dgst_process  *transform;
    t_dgst_process  *final;
}              t_dgst_dist;

typedef struct      s_digest
{
    int             cmd_key;
    char            *cmd_name;
    t_dgst_ctx      ctx;
    t_dgst_dist     dist;
}                   t_dgst;

int     ft_ssl_dgst(int argc, char *argv[]);

int     ft_ssl_dgst_init(t_dgst *ftssl_dgst, const char *cmd_name);

int 	get_input(uint8_t *block, t_dgst_ipt ipt, int len);
int     ft_ssl_dgst_input(t_dgst_ctx *ctx, t_dgst_ipt ipt);

// int     ft_dgst_dispatcher(char *cmd_name);
// int     ft_dgst_dispatcher_ctx(int cmd_key, t_dgst_ctx *ctx);
// int		ft_dgst_dispatcher_act(int cmd_key, t_dgst_act *act);


void    ft_ssl_dgst_usage(void);


// functions for dgst

// int			ft_dgst_init_md5_sha1(t_dgst_ctx *ctx);
// // int			ft_ssl_dgst_init_sha256(t_dgst_ctx *ctx);

// int			ft_ssl_dgst_final(t_dgst_ctx *ctx);

int				ft_ssl_dgst_result(t_dgst_ctx *ctx);
#endif
