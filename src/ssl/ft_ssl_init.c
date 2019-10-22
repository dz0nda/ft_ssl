#include "ft_ssl.h"

int		        ft_ssl_init(t_ftssl *ssl, int argc, char *argv[])
{
    ft_memset(ssl, 0, sizeof(t_ftssl));
    if (argc < 2)
        ft_ssl_shell(ssl);
    else
        ft_ssl_parse(argc, argv);
    return (EXIT_SUCCESS);
}