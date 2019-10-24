#ifndef FT_SSL_H
# define FT_SSL_H

# include "../ssl_dgst/ft_ssl_dgst.h"

#define FTSSL_MAX_BUFFER 512
#define FTSSL_MAX_STRINGS 50
#define FTSSL_MAX_CMDFLAG 

/*
 *    Hash sizes:
 *      MD5       16 byte / 128 bit
 *      SHA-1     20 byte / 160 bit
 *      SHA-256   32 byte / 256 bit
 *      SHA-512   64 byte / 512 bit
 */

typedef enum        s_ftssl_status
{
    FT_SSL_SUCCESS,
    FT_SSL_ERROR,
    FT_SSL_USAGE,
    FT_SSL_INVALID_COMMAND
}                   t_ftssl_stat;

typedef enum        s_ftssl_type_enum
{
    FT_DGST,
    FT_CIPHER,
    FT_STDRD,
    FT_SSL_TYPE
}                   t_ftssl_type_e;

typedef union       s_ftssl_context_union
{
    t_dgst_ctx    dgstctx;
}                   t_ftssl_ctx_u;

// typedef struct	s_ftssl_digest_context
// {
//     int			(*ftssl_digst_update)(t_md5_ctx *ctx, const void *data, unsigned long len);
//     int			(*ftssl_digst_final)(t_md5_ctx *ctx, unsigned char *md);
// }				t_dgst_ctx_u;
 

typedef struct	s_ftssl_shell
{
    char        *prompt;
    int         argc;
    char        *argv[FTSSL_MAX_STRINGS];
}				t_ftssl_sh;

// typedef struct	s_ft_ssl_context
// {
//     int             ftssl_cmd;
//     t_dgst_ctx_u ctx;
// }				t_ftssl_ctx;
 
typedef struct        s_ftssl_context
{
    int         ftssl_type;
    int         ftssl_cmd;
    int         (*flags)(char);
    t_ftssl_ctx_u  ctx;
}                   t_ftssl_ctx;

typedef struct	s_ft_ssl
{
    int          ftssl_stat;
    int          (*ftssl_usage)(void);
    int          (*ftssl_error)(const char *);
    t_ftssl_sh    sh;
    t_ftssl_ctx   ctx;
}				t_ftssl;

int		        ft_ssl_init(t_ftssl *ssl, int argc, char const *argv[]);
int		        ft_ssl_reset(t_ftssl *ssl);

int		        ft_ssl_shell(t_ftssl *ssl);

int		        ft_ssl_parse(int argc, char *argv[]);
int             ft_ssl_parse_flag_unknown(char c);
int             ft_ssl_parse_flags_md(char c);
int				ft_ssl_usage(void);
int				ft_ssl_error(const char *cmd);

#endif
