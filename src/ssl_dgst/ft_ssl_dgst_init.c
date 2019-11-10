#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_init(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[])
{
	ftssl_dgst->inpt.argc = argc;
	ftssl_dgst->inpt.argv = argv;
	ftssl_dgst->outp.outp_dist = ft_ssl_dgst_output;
	return (EXIT_SUCCESS);
}
