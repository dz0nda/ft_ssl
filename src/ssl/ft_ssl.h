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

typedef enum        s_ssl_message_digest
{
    FT_MD5,
    FT_SHA1,
    FT_SHA256
}                   t_ssl_md;

typedef union       s_ssl_context
{
    t_md5_ctx       md5ctx;
    t_sha1_ctx      sha1ctx;
    t_sha256_ctx    sha256ctx;
}                   t_ssl_ctx;

typedef struct	s_ft_ssl
{
    t_ssl_ctx   ssl_ctx;
}				t_ft_ssl;

int				ft_ssl_error(const char *cmd);
int		        ft_ssl_init(t_ft_ssl *ssl, int argc, char *argv[]);
int		        ft_ssl_parse(int argc, char *argv[]);
int				ft_ssl_usage(void);

#endif
