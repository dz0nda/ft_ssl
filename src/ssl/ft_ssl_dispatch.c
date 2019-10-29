#include "ft_ssl.h"

int     ft_ssl_unknown(int key, int argc, char *argv[])
{
    return (1);
}

int     ft_ssl_unknown_dispatcher(char *cmd_name)
{
    return (1);
}

int		ft_ssl_dispatcher(int argc, char *argv[])
{
	const t_ftssl_dispatcher dispatcher[FTSSL_TYPE_E] = {
		{ FT_DGST, ft_dgst_dispatcher, ft_ssl_dgst },
		{ FT_CIPHER, ft_ssl_cipher_dispatcher, ft_ssl_cipher },
		{ FT_STDRD, ft_ssl_stdrd_dispatcher, ft_ssl_stdrd },
		{ FT_UNKNOWN, ft_ssl_unknown_dispatcher, ft_ssl_unknown },
	};
    int i;

    i = -1;
    while (++i < FTSSL_TYPE_E)
		if (dispatcher[i].cmd_dispatch(argv[0]) == EXIT_SUCCESS)
			break;
	return (EXIT_SUCCESS);
}