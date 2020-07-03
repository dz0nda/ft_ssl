#include "../ft_ssl_dgst.h"

int				ft_ssl_dgst_output_q(t_ftssl_dgst *ftssl_dgst)
{
	ft_putendl(ftssl_dgst->md);
	return (EXIT_SUCCESS);
}