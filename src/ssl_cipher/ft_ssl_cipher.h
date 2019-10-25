#ifndef FT_SSL_CIPHER_H
# define FT_SSL_CIPHER_H

# include "../ft_ssl_global.h"

typedef enum        s_cipher_command_enum
{
    FT_BASE64,
    FT_DES,
    FT_SSL_CIPHER_CMD
}                   t_cipher_cmd_e;

typedef enum        s_cipher_flag_enum
{
    FT_CIPHER_D = 'd',
    FT_CIPHER_E = 'e',
    FT_CIPHER_I = 'i',
    FT_CIPHER_O = 'o',
    FT_CIPHER_FLAG = 4
}                   t_cipher_flag_e;

typedef struct	    s_cipher_context
{
    int             cmd;
}				    t_cipher;

int                 ft_ssl_parse_type_cipher(char *s);

// int				ft_cipher(t_cipher *ctx);

#endif
