#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../ft_ssl_global.h"
// # include "../dgst/ft_dgst.h"

typedef enum    s_digest_command_enum
{
    FT_MD5,
    FT_SHA1,
    FT_SHA256,
    FT_DGST_CMD
}               t_dgst_cmd_e;

typedef struct  s_digest_command_dispatcher
{
    int     cmd_key;
    char    *cmd_name;
}               t_dgst_cmd_d;

int     ft_ssl_dgst(int cmd_key, int argc, char *argv[]);

int     ft_dgst_dispatcher(char *cmd_name);

void    ft_ssl_dgst_usage(void);

#endif
