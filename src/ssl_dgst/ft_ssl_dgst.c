#include "ft_ssl_dgst.h"

void	ft_ssl_dgst_show_all(t_ftssl_dgst ftssl_dgst)
{
	int i = -1;
	printf("\n== Show inpt ==\n");
	printf("\t.i : %d\n", ftssl_dgst.inpt.i);
	printf("\t.argc : %d\n", ftssl_dgst.inpt.argc);
	while (++i < ftssl_dgst.inpt.argc)
		printf("\t.argv[%d] : %s\n", i, ftssl_dgst.inpt.argv[i]);

	printf("\n== Show ctx ==\n");
	printf("\t.cmd_key : %d\n", ftssl_dgst.ctx.cmd_key);
	printf("\t.cmd_name : %s\n", ftssl_dgst.ctx.cmd_name);
	printf("\t.cmd_arg : %s\n", ftssl_dgst.ctx.cmd_arg);
	printf("\t.cmd_arg_len : %d\n", ftssl_dgst.ctx.cmd_arg_len);
	printf("\t.cmd_dgst : %s\n", ftssl_dgst.ctx.cmd_dgst);

	printf("\n== Show outp ==\n");
	printf("\t.outp_flag : %d\n", ftssl_dgst.outp.outp_flag);
}

int     ft_ssl_dgst_exec(t_ftssl_dgst *ftssl_dgst)
{
	char	dgst[FTSSL_DGST_MAX_BUFFER];

	printf("exec \n");

	ft_bzero(dgst, FTSSL_DGST_MAX_BUFFER);
	ft_dgst(ftssl_dgst->ctx.cmd_key, ftssl_dgst->ctx.cmd_arg, ftssl_dgst->ctx.cmd_arg_len, ftssl_dgst->ctx.cmd_dgst);
	ftssl_dgst->outp.outp_dist(ftssl_dgst);
}

int     ft_ssl_dgst(int argc, char *argv[])
{
	t_ftssl_dgst	ftssl_dgst;

	ft_memset(&ftssl_dgst, 0, sizeof(ftssl_dgst));
	ft_ssl_dgst_init(&ftssl_dgst, argc, argv);
	ft_ssl_dgst_opt(&ftssl_dgst, ftssl_dgst.inpt.argv[0]);
	if (ft_ssl_dgst_parse_opt(&ftssl_dgst) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_ssl_dgst_parse_arg(&ftssl_dgst);
	ft_ssl_dgst_show_all(ftssl_dgst);
	return (EXIT_FAILURE);   
}
