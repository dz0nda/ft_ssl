#include "ft_ssl.h"

int		        ft_ssl_reset(t_ftssl *ssl)
{
    int i;

    i = -1;
	while (++i < ssl->sh.argc && i < FTSSL_SHMAX_ARG)
		ft_strdel(&ssl->sh.argv[i]);
    ft_memset(ssl, 0, sizeof(t_ftssl));
    ssl->ftssl_usage = &ft_ssl_usage;
    ssl->ftssl_error = &ft_ssl_error;
    return (EXIT_SUCCESS);
}