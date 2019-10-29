#ifndef FT_SSL_H
# define FT_SSL_H

# include "../ft_ssl_global.h"

# include "../ssl_dgst/ft_ssl_dgst.h"
# include "../ssl_cipher/ft_ssl_cipher.h"
# include "../ssl_stdrd/ft_ssl_stdrd.h"

typedef		int t_ftssl_cmd_dispatch(char *);
typedef     int t_ftssl_cmd_dist(int, int, char *[]);

typedef enum        s_ftssl_type_enum
{
    FT_DGST = 0,
    FT_CIPHER,
    FT_STDRD,
    FT_UNKNOWN,
    FTSSL_TYPE_E
}                   t_ftssl_type_e;


typedef struct  s_ftssl_dispatcher
{
    int                     type;
    t_ftssl_cmd_dispatch    *cmd_dispatch;
    t_ftssl_cmd_dist        *cmd_dist;
}              t_ftssl_dispatcher;

int		ft_ssl_dispatcher(int argc, char *argv[]);

int		ft_ssl_usage(void);

#endif
