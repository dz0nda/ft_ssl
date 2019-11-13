#include "ft_ssl_dgst.h"

// void	ft_ssl_dgst_show_all(t_ftssl_dgst ftssl_dgst)
// {
// 	int i = -1;
// 	printf("\n== Show inpt ==\n");
// 	printf("\t.i : %d\n", ftssl_dgst.inpt.i);
// 	printf("\t.argc : %d\n", ftssl_dgst.inpt.argc);
// 	while (++i < ftssl_dgst.inpt.argc)
// 		printf("\t.argv[%d] : %s\n", i, ftssl_dgst.inpt.argv[i]);

// 	printf("\n== Show ctx ==\n");
// 	printf("\t.cmd_key : %d\n", ftssl_dgst.ctx.cmd_key);
// 	printf("\t.cmd_name : %s\n", ftssl_dgst.ctx.cmd_name);
// 	printf("\t.cmd_arg : %s\n", ftssl_dgst.ctx.cmd_arg);
// 	printf("\t.cmd_arg_len : %d\n", ftssl_dgst.ctx.cmd_arg_len);
// 	printf("\t.cmd_dgst : %s\n", ftssl_dgst.ctx.cmd_dgst);

// 	printf("\n== Show outp ==\n");
// 	printf("\t.outp_flag : %d\n", ftssl_dgst.outp.outp_flag);
// }

int		ft_ssl_dgst_parse_opt(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[])
{
	while (ftssl_dgst->iarg < argc && *argv[ftssl_dgst->iarg] == '-')
	{
		if (argv[ftssl_dgst->iarg][1] == '\0')
			break ;
		if (ft_ssl_dgst_opt(ftssl_dgst, argc, argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		// ft_putendl(ftssl_dgst.md);
	}
	if (ftssl_dgst->iarg == argc && ft_strlen(ftssl_dgst->md) == 0)
	{
		ft_dgst_file(ftssl_dgst->cmd_key, NULL, FT_SSL_FALSE, ftssl_dgst->md);
		ftssl_dgst->outp_dist(ftssl_dgst->cmd_name, NULL, 0, ftssl_dgst->md);
	}
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_parse_arg(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[])
{
	struct stat	st;
	int err = EXIT_SUCCESS;

	ft_memset(&st, 0, sizeof(st));
	while (ftssl_dgst->iarg < argc)
	{
		if (lstat(argv[ftssl_dgst->iarg] , &st) == 0)
		{
			if (S_ISREG(st.st_mode))
			{
				ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
				ft_dgst_file(ftssl_dgst->cmd_key, argv[ftssl_dgst->iarg], FT_SSL_FALSE, ftssl_dgst->md);
				ftssl_dgst->outp_dist(ftssl_dgst->cmd_name, argv[ftssl_dgst->iarg], 0, ftssl_dgst->md);
			}
			else if (S_ISDIR(st.st_mode))
				err = ft_ssl_dgst_error_dir(ftssl_dgst->cmd_name, argv[ftssl_dgst->iarg]);
		}
		else
			err = ft_ssl_dgst_error_file(ftssl_dgst->cmd_name, argv[ftssl_dgst->iarg]);
		ftssl_dgst->iarg++;
	}
	return (err);
}

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
	return (EXIT_FAILURE);
}
