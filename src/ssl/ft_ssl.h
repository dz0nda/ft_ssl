#ifndef FT_SSL_H
# define FT_SSL_H

# include "../ssl_dgst/ft_ssl_dgst.h"
# include "../ssl_cipher/ft_ssl_cipher.h"
# include "../ssl_stdrd/ft_ssl_stdrd.h"

#define FTSSL_MAX_INPUT_SHELL 1024

# define FTSSL_SHMAX_BUFFER 1024
# define FTSSL_SHMAX_ARG 50

typedef     struct s_ftssl t_ftssl;
typedef     struct s_ftssl_shell t_ftssl_sh;
typedef		int t_ftssl_dist(t_ftssl *);
typedef     int t_ftssl_dist_parser(char *s);


#define FTSSL_MAX_CMDFLAG 3

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
    FT_SSL_COMMAND_INVALID,
    FT_SSL_COMMAND_MISSING,
    FT_SSL_ARGUMENT_MISSING
}                   t_ftssl_stat;

typedef enum        s_ftssl_type_enum
{
    FT_DGST = 0,
    FT_CIPHER,
    FT_STDRD,
    FT_UNKNOWN,
    FTSSL_TYPE_E
}                   t_ftssl_type_e;

typedef union       s_ftssl_context_union
{
}                   t_ftssl_ctx_u;

typedef enum        s_ftssl_command_enum
{
    FT_SSL_CMD_VALID,
    FT_SSL_CMD_INVALID,
    FT_SSL_CMD_MISSING
}                   t_ftssl_cmd_e;

typedef struct	s_ftssl_shell
{
    char        *cmd;
    int         argc;
    char        *argv[FTSSL_SHMAX_ARG];
}				t_ftssl_sh;

typedef struct        s_ftssl_context
{
    int         ftssl_type;
    int         ftssl_cmd;
    int         (*flags)(char);
    t_ftssl_ctx_u  ctx;

    int         ctx_type;
    int         (*ctx_cmd)(struct s_ftssl *);
}                   t_ftssl_ctx;

typedef enum s_shell_mode_e
{
    FT_SHMODE_FALSE,
    FT_SHMODE_TRUE
}            t_shmode_e;

// typedef struct s_ftssl_cmd {
//   int		    type;
//   t_ftssl_dist	*dist;
//   }             t_ftssl_cmd;

typedef struct	s_ftssl
{
    int         ftssl_mode;
    int         ftssl_stat;
    int          (*ftssl_usage)(void);
    int          (*ftssl_error)(const char *);
    int          (*ftssl_cmd)(struct s_ftssl *);
    int         key;
    t_ftssl_sh    sh;
    t_ftssl_ctx   ctx;
}				t_ftssl;



typedef struct s_ftssl_type_dispatch
{
    int type;
    t_ftssl_dist_parser *ftssl_parse_cmd;
    t_ftssl_dist        *ftssl_dist;
}              t_ftssl_type_dispatch;

// extern const t_ftssl_type_dispatch g_ftssl_type_dispatch[FTSSL_TYPE_E];

int		        ft_ssl_reset(t_ftssl *ssl);
int		        ft_ssl_init(t_ftssl *ssl, int argc, char const *argv[]);

int		        ft_ssl_shell(t_ftssl_sh  *sh);


int             ft_dgst(t_ftssl *sh);
int				ft_cipher(t_ftssl *sh);
int			    ft_stdrd(t_ftssl *sh);
int             ft_unknown(t_ftssl *sh);

int             ft_ssl_parse_type_unknown(char *s);
int		        ft_ssl_parse(int argc, char *argv[]);
int             ft_ssl_parse_flag_unknown(char c);
int             ft_ssl_parse_flags_md(char c);
int				ft_ssl_usage(void);
int				ft_ssl_error(const char *cmd);

#endif
