#include "ft_ssl.h"

int		        ft_ssl_init(t_ftssl *ssl)
{
    ft_memset(ssl, 0, sizeof(t_ftssl));
    return (EXIT_SUCCESS);
}