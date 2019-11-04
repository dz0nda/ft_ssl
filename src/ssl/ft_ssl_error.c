#include "ft_ssl.h"

int     ft_ssl_error(int argc, char *argv[])
{
    ft_putstr("ftssl:Error: '");
    ft_putstr(argv[0]);
    ft_putendl("' is an invalid command.");
    ft_ssl_usage(0, NULL);
    return (EXIT_SUCCESS);
}