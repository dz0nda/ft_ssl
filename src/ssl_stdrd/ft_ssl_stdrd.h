#ifndef FT_SSL_STDRD_H
# define FT_SSL_STDRD_H

# include "../ft_ssl_global.h"

typedef enum        s_stdrd_command_enum
{
    FT_SSL_STDRD_CMD
}                   t_stdrd_cmd_e;

typedef struct	    s_standard
{
    int             cmd;
}				    t_stdrd;

int                 ft_ssl_parse_type_stdrd(char *s);

// int				ft_stdrd(t_stdrd *ctx);

#endif
