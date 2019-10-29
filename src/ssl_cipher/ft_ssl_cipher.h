#ifndef FT_SSL_CIPHER_H
# define FT_SSL_CIPHER_H

# include "../ft_ssl_global.h"

typedef enum        s_cipher_command_enum
{
    FT_BASE64,
    FT_DES,
    FT_SSL_CIPHER_CMD
}                   t_cipher_cmd_e;

typedef struct  s_cipher_command_dispatcher
{
    int     cmd_key;
    char    *cmd_name;
}               t_cipher_cmd_d;

int     ft_ssl_cipher(int cmd_key, int argc, char *argv[]);

int     ft_ssl_cipher_dispatcher(char *cmd_name);

void     ft_ssl_cipher_usage(void);

#endif
