#include "../ft_ssl_dgst.h"

/*
 * 	Output stdin to stdout by sending TRUE bool to ft_dgst_file
*/

int		ft_ssl_dgst_opt_p(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[], int opt_key)
{
	(void)argc;
	(void)argv;
	(void)opt_key;
	ftssl_dgst->iarg++;
	ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
	// ft_dgst_file(ftssl_dgst->cmd_key, NULL, FT_SSL_TRUE, ftssl_dgst->md);
	// ft_dgst_file(ftssl_dgst->cmd_key, NULL, FT_SSL_TRUE, ftssl_dgst->md);
	ft_dgst(ftssl_dgst->cmd_key, NULL, FT_DGST_FILE, ftssl_dgst->md, FT_SSL_TRUE);
	// ftssl_dgst->outp_dist(ftssl_dgst->cmd_name, NULL, 0, ftssl_dgst->md);
	ftssl_dgst_dispatch_outp(ftssl_dgst->cmd_name, NULL, 0, ftssl_dgst->md, ftssl_dgst->outp_key);
	return (EXIT_SUCCESS);
}