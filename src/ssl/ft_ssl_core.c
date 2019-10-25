#include "ft_ssl.h"

int         ft_dgst(t_ftssl *ctx)
{
    printf("ïm in dgst\n");
	return (EXIT_SUCCESS);
}

int		    ft_cipher(t_ftssl *ctx)
{
    printf("ïm in cipher\n");
	return (EXIT_SUCCESS);
}

int			ft_stdrd(t_ftssl *ctx)
{
    printf("ïm in stdrd\n");
	return (EXIT_SUCCESS);
}

int         ft_unknown(t_ftssl *ctx)
{
    printf("%s fonction inconnue\n", ctx->sh.argv[0]);
	return (EXIT_SUCCESS);
}