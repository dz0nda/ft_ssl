#include "ft_ssl_stdrd.h"

int     ft_ssl_stdrd_dispatcher(char *cmd_name)
{
    const t_stdrd_cmd_d dispatcher[FT_SSL_STDRD_CMD] = { };
    int i;

    i = -1;
    while (++i < FT_SSL_STDRD_CMD)
        if (ft_strcmp(cmd_name, dispatcher[i].cmd_name) == 0)
            return (i);
     return (-1);
}
