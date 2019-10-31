#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../ft_ssl_global.h"
# include "../dgst/ft_dgst.h"

# define FT_DGST_MAX_STDIN 1024

typedef struct      s_digest_context t_dgst_ctx;

typedef     int t_dgst_cmd_dist(int, int, char *[]);
typedef     int t_dgst_step(t_dgst_ctx *);

typedef enum    s_digest_command_enum
{
    FT_MD5,
    FT_SHA1,
    FT_SHA256,
    FT_DGST_CMD
}               t_dgst_cmd_e;

typedef enum    s_digest_input_enum
{
    FT_DGST_INPUT,
    FT_DGST_FILE,
    FT_DGST_STRING
}               t_dgst_ipt_e;

typedef struct  s_digest_command_dispatcher
{
    int     cmd_key;
    char    *cmd_name;
}               t_dgst_cmd_d;

typedef struct      s_digest_input
{
    int     ipt_key;
    char    *ipt_name;
}                   t_dgst_ipt;

// typedef struct      s_digest_context
// {
//     int         cmd_key;
//     int         len_hs;
//     int         len_mbs;
//     int         endian;
//     int         len_state;
//     uint32_t    *state;
//     uint8_t     *block;
// }                   t_dgst_ctx;

typedef struct      s_digest_context_dispatch
{
    int         cmd_key;
    t_dgst_ctx  ctx;
}                   t_dgst_ctx_d;

typedef struct     s_digest_action
{
    int             cmd_key;
    t_dgst_step     *init;
    t_dgst_step     *update;
    t_dgst_step     *final;
}                  t_dgst_act;

int     ft_ssl_dgst(int cmd_key, int argc, char *argv[]);

int     ft_dgst_dispatcher(char *cmd_name);
int     ft_dgst_dispatcher_ctx(int cmd_key, t_dgst_ctx *ctx);
int		ft_dgst_dispatcher_act(int cmd_key, t_dgst_act *act);


void    ft_ssl_dgst_usage(void);


// functions for dgst

// int			ft_dgst_init_md5_sha1(t_dgst_ctx *ctx);
int			ft_ssl_dgst_init_sha256(t_dgst_ctx *ctx);

int			ft_ssl_dgst_update_md5(t_dgst_ctx *ctx);
int			ft_ssl_dgst_update_sha1(t_dgst_ctx *ctx);
int			ft_ssl_dgst_update_sha256(t_dgst_ctx *ctx);

int			ft_ssl_dgst_final(t_dgst_ctx *ctx);

int				ft_ssl_dgst_result(t_dgst_ctx *ctx);
#endif
