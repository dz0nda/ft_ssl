#include "ft_ssl_dgst.h"

int     ft_ssl_dgst(int cmd_key, char *cmd_name, int argc, char *argv[])
{
	t_ftssl_dgst	ftssl_dgst;

	ft_memset(&ftssl_dgst, 0, sizeof(ftssl_dgst));
	ftssl_dgst.cmd_key = cmd_key;
	ftssl_dgst.cmd_name = cmd_name;
	// if (ft_ssl_dgst_init(ftssl_dgst))

	if (ft_ssl_dgst_parse_opt(&ftssl_dgst, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_ssl_dgst_parse_arg(&ftssl_dgst, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
