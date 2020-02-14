#include "../ft_ssl_dgst.h"

/*
 * 	Assign outp_dist and outp_flag only if FLAG_Q is not already set
*/

int		ft_ssl_dgst_opt_outp(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[], int opt_key)
{
	(void)argc;
	(void)argv;
	if (ftssl_dgst->outp_key != FTSSL_DGST_OUTP_QUIET)
	{
		if (opt_key == FT_SSL_DGST_OPT_R)
			ftssl_dgst->outp_key = FTSSL_DGST_OUTP_REVERSE;
		else if (opt_key == FT_SSL_DGST_OPT_Q)
			ftssl_dgst->outp_key = FTSSL_DGST_OUTP_QUIET;
	}
	ftssl_dgst->iarg++;
	return (EXIT_SUCCESS);
}