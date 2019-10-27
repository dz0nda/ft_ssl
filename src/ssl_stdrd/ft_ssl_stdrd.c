#include "ft_ssl_stdrd.h"

void     ft_ssl_usage_stdrd(void)
{
    ft_putstr("Standard commands: \n");
    ft_putstr(" \n");
}

int     ft_ssl_parse_type_stdrd(char *s)
{
    const char *ft_ssl_dgst_cmds[FT_SSL_STDRD_CMD] = { };
    int i;

    i = -1;
    while (++i < FT_SSL_STDRD_CMD)
        if (ft_strcmp(s, ft_ssl_dgst_cmds[i]) == 0)
            return (0);
    return (1);
}

// int				        ft_stdrd(t_stdrd *ctx)
// {
//     printf("ïm in stdrd\n");

// 	return (1);
// }