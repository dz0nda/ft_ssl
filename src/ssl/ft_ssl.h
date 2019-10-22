#ifndef FT_SSL_H
# define FT_SSL_H

# include "../md5/ft_md5.h"
# include "../sha1/ft_sha1.h"
# include "../sha256/ft_sha256.h"

/*
 *    Hash sizes:
 *      MD5       16 byte / 128 bit
 *      SHA-1     20 byte / 160 bit
 *      SHA-256   32 byte / 256 bit
 *      SHA-512   64 byte / 512 bit
 */

typedef enum        s_ssl_return
{
    FT_SSL_SUCCESS,
    FT_SSL_USAGE,
    FT_SSL_INVALID_COMMAND
}                   t_ssl_return;

typedef enum        s_ftssl_command
{
    FT_MD5,
    FT_SHA1,
    FT_SHA256,
    FT_SSLCMD
}                   t_ftssl_cmd;

typedef union       s_ftssl_digest_struct
{
    t_md5_ctx       md5ctx;
    t_sha1_ctx      sha1ctx;
    t_sha256_ctx    sha256ctx;
}                   t_ftssl_md;

typedef struct	s_ftssl_digest_context
{
    int			(*ftssl_digst_update)(t_md5_ctx *ctx, const void *data, unsigned long len);
    int			(*ftssl_digst_final)(t_md5_ctx *ctx, unsigned char *md);
}				t_ftssl_dgstctx;
 

typedef struct	s_ft_ssl_shell
{
    char        *prompt;
}				t_ftssl_sh;
 
typedef struct	s_ft_ssl
{
    int           ftssl_cmd;
    char          *flags;
}				t_ftssl;

int				ft_ssl_error(const char *cmd);
int		        ft_ssl_init(t_ftssl *ssl);
int		        ft_ssl_shell(t_ftssl *ssl);
int		        ft_ssl_parse(int argc, char *argv[]);
int    ft_ssl_parse_flag_unknown(char c);
int				ft_ssl_usage(void);

#endif
