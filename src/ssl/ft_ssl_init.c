#include "ft_ssl.h"

int		        ft_ssl_init(t_ft_ssl *ssl, int argc, char *argv[])
{
    ft_ssl_parse(argc, argv);
    return (EXIT_SUCCESS);
}