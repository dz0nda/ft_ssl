#include "../ft_ssl_dgst.h"

/*
 * 	Assign cmd_arg and cmd_arg_len only if argv[i + 1] exists
 * 	Return fatal error for ssl_dgst instead
*/

int		ft_ssl_dgst_opt_s(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	t_ftssl_dgst_args *args;
	
	(void)opt_key;
	args = &ftssl_dgst->args;
	if (!(args->iarg + 1 < args->argc))
		return (ft_ssl_dispatch_err(FTSSL_DGST_ERR_OPT_ARG, ftssl_dgst));
	ftssl_dgst->args.iarg++;
	ftssl_dgst->inpt_key = FT_DGST_STRING;
	if (ftssl_dgst->outp_key != FTSSL_DGST_OUTP_REVERSE && ftssl_dgst->outp_key != FTSSL_DGST_OUTP_QUIET)
		ftssl_dgst->outp_key = FTSSL_DGST_OUTP_STRING;
	ftssl_dgst->cmd_arg = (args->argv[args->iarg] == NULL) ? "" : args->argv[args->iarg];
	ft_ssl_dgst_exec(ftssl_dgst);
	ftssl_dgst->iarg++;
	ftssl_dgst->args.iarg++;
	return (EXIT_SUCCESS);
}