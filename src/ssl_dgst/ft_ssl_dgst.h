#ifndef FT_SSL_DIGST_H
# define FT_SSL_DIGST_H

# include "../dgst/ft_dgst.h"

typedef enum        s_digest_command_enum
{
    FT_MD5,
    FT_SHA1,
    FT_SHA256,
    FT_SSL_DGST_CMD
}                   t_dgst_cmd_e;

typedef enum        s_dgst_flag_enum
{
    FT_DGST_P = 'p',
    FT_DGST_Q = 'q',
    FT_DGST_R = 'r',
    FT_DGST_S = 's',
    FT_DGST_FLAG = 4
}                   s_dgst_flag_e;

typedef union       s_digest_context
{
    t_md5_ctx       md5ctx;
    t_sha1_ctx      sha1ctx;
    t_sha256_ctx    sha256ctx;
}                   t_dgst_ctx;

typedef struct      s_dgst_dispatch
{
    int flag;
    
}                   t_dgst_dsptch;


typedef struct	    s_dgst_context
{
    int             dgst_cmd;
    int             dgst_mbs;
    int             dgst_hs;
    int             dgst_hsb;

    t_dgst_ctx    dgst_ctx;
}				    t_dgst;

int             ft_ssl_parse_type_dgst(char *s);

int			    ft_ssl_dgst_md5_init(t_dgst_ctx *ctx);
int			    ft_ssl_dgst_sha1_init(t_dgst_ctx *ctx);
int			    ft_ssl_dgst_sha256_init(t_dgst_ctx *ctx);

#endif
