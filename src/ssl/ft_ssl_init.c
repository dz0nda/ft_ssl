#include "ft_ssl.h"

static int      ft_ssl_init_sh(t_ftssl_sh *sh, int argc, char const *argv[])
{
    int i;

    i = -1;
	while (++i < argc && i < FTSSL_MAX_STRINGS)
		if ((sh->argv[i] = ft_strdup(argv[i])) == NULL)
            return (EXIT_FAILURE);
    sh->argc = argc;
    return (EXIT_SUCCESS);
}

static int      ft_ssl_reset_sh(t_ftssl_sh *sh)
{
    int i;

    i = -1;
	while (++i < sh->argc && i < FTSSL_MAX_STRINGS)
		ft_strdel(&sh->argv[i]);
    return (EXIT_SUCCESS);
}

int		        ft_ssl_init(t_ftssl *ssl, int argc, char const *argv[])
{
    ft_memset(ssl, 0, sizeof(t_ftssl));
    ssl->ftssl_usage = &ft_ssl_usage;
    ssl->ftssl_error = &ft_ssl_error;
    if (ft_ssl_init_sh(&ssl->sh, argc - 1, ++argv) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int		        ft_ssl_reset(t_ftssl *ssl)
{
    if (ft_ssl_reset_sh(&ssl->sh) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    ft_memset(ssl, 0, sizeof(t_ftssl));
    return (EXIT_SUCCESS);
}