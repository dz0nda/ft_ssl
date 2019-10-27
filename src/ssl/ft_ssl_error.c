#include "ft_ssl.h"

int		ft_ssl_error(const char *cmd)
{

	return (EXIT_FAILURE);
}

int    ft_ssl_parse_flag_unknown(char c)
{
    printf("unknown option '-%c'\n", c);
    return (EXIT_FAILURE);
}
int     ft_ssl_parse_type_unknown(char *s)
{
	(void *)s;
    return (EXIT_SUCCESS);
}