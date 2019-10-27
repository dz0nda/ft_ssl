#include "ft_ssl.h"

int         ft_dgst(t_ftssl_sh *sh)
{
    printf("ïm in dgst\n");
    
               
	return (EXIT_SUCCESS);
}

int		    ft_cipher(t_ftssl_sh *sh)
{
    printf("ïm in cipher\n");
	return (EXIT_SUCCESS);
}

int			ft_stdrd(t_ftssl_sh *sh)
{
    printf("ïm in stdrd\n");
	return (EXIT_SUCCESS);
}

int         ft_unknown(t_ftssl_sh *sh)
{
    printf("%s fonction inconnue\n", sh->argv[0]);
	return (EXIT_SUCCESS);
}