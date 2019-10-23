#ifndef FT_SSL_DIGST_H
# define FT_SSL_DIGST_H

# include "../md5/ft_md5.h"
# include "../ssl/ft_ssl.h"

typedef enum        s_ftssl_digest_command_enum
{
    FT_MD5,
    FT_SHA1,
    FT_SHA256,
    FT_SSL_DGST_CMD
}                   t_ftssl_dgst_cmd_e;

typedef union       s_ftssl_digest_context_union
{
    t_md5_ctx       md5ctx;
    t_sha1_ctx      sha1ctx;
    t_sha256_ctx    sha256ctx;
}                   t_ftssl_dgst_ctx_u;

typedef struct	    s_ft_ssl_dgst_context
{
    int             ftssl_dgst_cmd;
    t_ftssl_dgst_ctx_u ftssl_dgst_ctx;
}				    t_ftssl_dgst_ctx;
 
int				ft_dgst(const unsigned char *d, unsigned long n, unsigned char *md);

int			    ft_ssl_dgst_md5_init(t_ftssl_dgst_ctx_u *ctx);
int			    ft_ssl_dgst_sha1_init(t_ftssl_dgst_ctx_u *ctx);
int			    ft_ssl_dgst_sha256_init(t_ftssl_dgst_ctx_u *ctx);

#endif
