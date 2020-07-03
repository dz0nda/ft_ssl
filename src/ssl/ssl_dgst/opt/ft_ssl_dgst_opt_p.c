#include "../ft_ssl_dgst.h"

/*
 * 	Output stdin to stdout by sending TRUE bool to ft_dgst_file
*/

int		ft_ssl_dgst_opt_p(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	(void)opt_key;
	ftssl_dgst->args.iarg++;
	ftssl_dgst->inpt_key = FT_DGST_FILE;
	ftssl_dgst->cmd_arg = NULL;
	ftssl_dgst->outp = FT_SSL_TRUE;
	ft_ssl_dgst_exec(ftssl_dgst);
	ftssl_dgst->outp = FT_SSL_FALSE;
	return (EXIT_SUCCESS);
}