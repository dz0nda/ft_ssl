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

int		ft_ssl_init_sh(t_ftssl_sh *sh, int argc, char const *argv[])
{
    int i;

    i = 0;
	if ((sh->argc = argc) < 1)
		return (EXIT_SUCCESS);
	if ((sh->cmd = ft_strdup(argv[0])) == NULL)
        return (EXIT_FAILURE);
	while (++i < argc && i < FTSSL_SHMAX_ARG)
		if ((sh->argv[i - 1] = ft_strdup(argv[i])) == NULL)
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int		ft_ssl_init(t_ftssl *ssl, int argc, char const *argv[])
{
    if (ft_ssl_init_sh(&ssl->sh, argc, argv) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
