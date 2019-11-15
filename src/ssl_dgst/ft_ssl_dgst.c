#include "ft_ssl_dgst.h"

int     ft_ssl_dgst(int argc, char *argv[])
{
	t_ftssl_dgst	ftssl_dgst;

	ft_memset(&ftssl_dgst, 0, sizeof(ftssl_dgst));
	ftssl_dgst.outp_dist = ft_ssl_dgst_output;
	ft_ssl_dgst_opt(&ftssl_dgst, argc, argv);
	if (ft_ssl_dgst_parse_opt(&ftssl_dgst, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_ssl_dgst_parse_arg(&ftssl_dgst, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
