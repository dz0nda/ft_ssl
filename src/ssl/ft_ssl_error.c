#include "ft_ssl.h"

int		ft_ssl_error(const char *cmd)
{
	ft_putstr("ft_ssl: Error: '");
	ft_putstr(cmd);
	ft_putstr("' is an invalid command.\n");
	return (EXIT_FAILURE);
}

int    ft_ssl_parse_flag_unknown(char c)
{
    printf("unknown option '-%c'\n", c);
    return (EXIT_FAILURE);
}