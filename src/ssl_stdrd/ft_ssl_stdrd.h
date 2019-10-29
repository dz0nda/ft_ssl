#ifndef FT_SSL_STDRD_H
# define FT_SSL_STDRD_H

# include "../ft_ssl_global.h"

typedef enum        s_standard_command_enum
{
    FT_SSL_STDRD_CMD
}                   t_stdrd_cmd_e;

typedef struct  s_standard_command_dispatcher
{
    int     cmd_key;
    char    *cmd_name;
}               t_stdrd_cmd_d;

int     ft_ssl_stdrd(int cmd_key, int argc, char *argv[]);

int     ft_ssl_stdrd_dispatcher(char *cmd_name);

void    ft_ssl_stdrd_usage(void);

#endif
