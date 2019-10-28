#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../dgst/ft_dgst.h"


typedef enum        s_digest_command_enum
{
    FT_MD5,
    FT_SHA1,
    FT_SHA256,
    FT_DGST_CMD
}                   t_dgst_cmd_e;

typedef enum        s_dgst_flag_enum
{
    FT_DGST_P = 'p',
    FT_DGST_Q = 'q',
    FT_DGST_R = 'r',
    FT_DGST_S = 's',
    FT_DGST_FLAG = 4
}                   s_dgst_flag_e;


/*
 *	
 *  Input for dgst
 * 
*/


# define FTSSL_DGSTMAX_ARG 50

typedef union s_digest_input_u  t_dgst_input_u;
typedef struct s_digest_context     t_dgst_ctx;
typedef struct s_ftssl_digest   t_ftssl_dgst;
typedef int t_ftssl_dgst_input(t_dgst_input_u *, int);
typedef int t_dgst_step(t_dgst_ctx *);


typedef enum s_digest_argument_e
{
    FT_INPUT_FILE,
    FT_INPUT_STRING
}            t_dgst_argument_e;

typedef union s_digest_input_u
{
    int fd;
    char *s;
}             t_dgst_input_u;

typedef struct s_digest_input
{
    int type;
    t_dgst_input_u  file;
}              t_digest_ipt;

typedef struct      s_ftssl_digest_argument
{
    int type;
    t_dgst_input_u  file;
}                   t_ftssl_dgst_arg;

typedef struct      s_digest_context
{
    int         len_hs;
    int         len_mbs;
    int         endian;
    int         len_state;
    uint32_t    *state;
    uint8_t     *block;
}                   t_dgst_ctx;

typedef struct     s_digest_action
{
    t_dgst_step     *init;
    t_dgst_step     *update;
}                  t_dgst_act;

typedef struct      s_ftssl_digest
{
    int         cmd_key;
    char        *cmd_name;
    char        *(*ftssl_dgst_input)(t_digest_ipt);
    t_dgst_ctx  *ctx;
    t_dgst_act  act;
}                   t_ftssl_dgst;

int             ft_ssl_parse_type_dgst(char *s);

void            ft_ssl_usage_dgst(void);

int			ft_ssl_dgst_init_md5_sha1(t_dgst_ctx *ctx);
int			ft_ssl_dgst_init_sha256(t_dgst_ctx *ctx);

int			ft_ssl_dgst_update_md5(t_dgst_ctx *ctx);
int			ft_ssl_dgst_update_sha1(t_dgst_ctx *ctx);
int			ft_ssl_dgst_update_sha256(t_dgst_ctx *ctx);



#endif
