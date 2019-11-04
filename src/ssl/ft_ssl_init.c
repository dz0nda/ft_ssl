#include "ft_ssl.h"

int     ft_ssl_init(t_ftssl *ftssl, int argc, const char *argv[])
{
    int i;

    i = -1;
    ft_memset(ftssl, 0, sizeof(ftssl));
    if (argc == 0)
        ftssl->shmode = FTSSL_SHMODE_ENABLED;
    else
    {
        ftssl->sh.argc = argc;
        while (++i < ftssl->sh.argc && i < FTSSL_SHMAX_CMD)
            ftssl->sh.argv[i] = ft_strdup(argv[i]);
    }
    return (EXIT_SUCCESS);
}