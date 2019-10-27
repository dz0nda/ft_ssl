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
	ft_putstr("ft_ssl: Error: '");
	ft_putstr(sh->cmd);
	ft_putstr("' is an invalid command.\n");
    ft_ssl_usage();
	return (EXIT_SUCCESS);
}