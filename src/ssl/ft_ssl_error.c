#include "ft_ssl.h"

int		ft_ssl_error(int err_key)
{
    const t_ftssl_err err[FTSSL_ERR_E] = {
        FTSSL_ERR_MALLOC, "A malloc allocation has failed."
    };
    int i;

    i = -1;
    while (++i < FTSSL_ERR_E)
        if (err_key = err[i].err_key)
        {
            ft_putstr_fd("ftssl:Error: ", 2);
            ft_putendl_fd(err[err_key].err_msg, 2);
        }
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