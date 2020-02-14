#include "../ft_ssl_dgst.h"

/*
 * 	Assign cmd_arg and cmd_arg_len only if argv[i + 1] exists
 * 	Return fatal error for ssl_dgst instead
*/

int		ft_ssl_dgst_opt_s(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[], int opt_key)
{	
	(void)opt_key;
	if (!(ftssl_dgst->iarg + 1 < argc))
		return (ft_ssl_dispatch_err(ftssl_dgst->cmd_name, argv[ftssl_dgst->iarg] + 1, FTSSL_DGST_ERR_OPT_ARG));
	ftssl_dgst->iarg++;
	ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
	// ft_dgst_string(ftssl_dgst->cmd_key, argv[ftssl_dgst->iarg], ft_strlen(argv[ftssl_dgst->iarg]), ftssl_dgst->md);
	if (argv[ftssl_dgst->iarg] == NULL)
		ft_dgst_string(ftssl_dgst->cmd_key, "", 0, ftssl_dgst->md);
	else
		ft_dgst_string(ftssl_dgst->cmd_key, argv[ftssl_dgst->iarg], ft_strlen(argv[ftssl_dgst->iarg]), ftssl_dgst->md);
	if (argv[ftssl_dgst->iarg] == NULL)
		ftssl_dgst_dispatch_outp(ftssl_dgst->cmd_name, "", 1, ftssl_dgst->md, ftssl_dgst->outp_key);
	else
		ftssl_dgst_dispatch_outp(ftssl_dgst->cmd_name, argv[ftssl_dgst->iarg], ft_strlen(argv[ftssl_dgst->iarg]), ftssl_dgst->md, ftssl_dgst->outp_key);
	ftssl_dgst->iarg++;
	// ft_putendl(ftssl_dgst->md);
	return (EXIT_SUCCESS);
}