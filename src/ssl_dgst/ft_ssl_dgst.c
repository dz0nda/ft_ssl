#include "ft_ssl_dgst.h"

// int		ft_ssl_dgst_parse_flag(t_dgst *dgst, int argc, char *argv[])
// {
// 	// const char
// 	// int i;

// 	// i = 1;
// }

// int		ft_ssl_dgst_parse_options(t_dgst *dgst, int argc, char *argv[], int i)
// {
// 	int	j;

// 	j = 0;
	
// }


// int     ft_ssl_dgst_parse(t_dgst *dgst, int argc, char *argv[])
// {
// 	int i;
// 	int j;

// 	i = 1;
// 	j = 0;
// 	printf("argc %d\n", argc);
// 	while (i < argc && argv[i] &&  argv[i][j] == '-')
// 	{
// 		while (argv[i][++j])
// 		{
// 			if (argv[i][j] == 's')
// 				ft_ssl_dgst_mdsha_string(dgst, argv[i + 1], ft_strlen(argv[i + 1]));// printf("sok\n");
// 			else if (argv[i][j] == 'p')
// 				ft_ssl_dgst_mdsha(dgst, NULL, 0); // printf("pok\n");
// 			else if (argv[i][j] == 'q')
// 				dgst->output = ft_ssl_dgst_output_q;
// 			else if (argv[i][j] == 'r')
// 			{
// 				printf("rok\n");
// 				dgst->output = ft_ssl_dgst_output_r;
// 			}
// 			else
// 				return (ft_ssl_dgst_error(argv[0], &argv[i][j]));
// 		}
// 		i++;
// 		j = 0;
// 	}
// 	if (i == argc)
// 		ft_ssl_dgst_mdsha(dgst, NULL, 0);
// 	else
// 		while (i < argc)
// 			ft_ssl_dgst_mdsha(dgst, argv[i++], 0);
// }

int     ft_ssl_dgst_init2(t_ftssl_dgst *ftssl_dgst, const char *cmd_name)
{


}

int		ft_ssl_dgst_parse_options_r(t_ftssl_dgst *ftssl_dgst)
{
	ft_putendl("Parse -r");

	if (ftssl_dgst->outp.outp_flag != FT_SSL_DGST_FLAG_Q)
	{
		ftssl_dgst->outp.outp_flag = FT_SSL_DGST_FLAG_R;
		ftssl_dgst->outp.outp_dist = ft_ssl_dgst_output_r;
	}
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_parse_options_q(t_ftssl_dgst *ftssl_dgst)
{
	ft_putendl("Parse -q");

	ftssl_dgst->outp.outp_flag = FT_SSL_DGST_FLAG_Q;
	ftssl_dgst->outp.outp_dist = ft_ssl_dgst_output_q;
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_parse_options_p(t_ftssl_dgst *ftssl_dgst)
{
	char buffer[FTSSL_DGST_MAX_BUFFER];

	ft_putendl("Parse -p");

    ft_bzero(buffer, sizeof(buffer));
    if (read(0, buffer, FTSSL_DGST_MAX_BUFFER - 1) < 1)
        return (EXIT_FAILURE);
	ft_putendl(buffer);
	// Execute
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_parse_options_s(t_ftssl_dgst *ftssl_dgst)
{
	int	*piarg;
	int	*pjarg;

	ft_putendl("Parse -s");

	piarg = &ftssl_dgst->iarg;
	pjarg = &ftssl_dgst->jarg;
	if (ftssl_dgst->argv[*piarg][*pjarg + 1] != '\0')
		return (EXIT_FAILURE);
	if (ftssl_dgst->argv[*piarg + 1] == NULL)
		return (ft_ssl_dgst_error_arg(ftssl_dgst->inpt.cmd_name, 's'));
	ftssl_dgst->inpt.cmd_arg = ftssl_dgst->argv[*piarg + 1];
	ftssl_dgst->inpt.cmd_arg_len = ft_strlen(ftssl_dgst->argv[*piarg + 1]);
	*piarg++;
	*pjarg = 0;
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_dispatch_option(t_ftssl_dgst *ftssl_dgst, char flag)
{
	t_ftssl_dgst_opt opt[FT_SSL_DGST_FLAG] = {
		{ FT_SSL_DGST_FLAG_P, ft_ssl_dgst_parse_options_p },
        { FT_SSL_DGST_FLAG_Q, ft_ssl_dgst_parse_options_q },
        { FT_SSL_DGST_FLAG_R, ft_ssl_dgst_parse_options_r },
		{ FT_SSL_DGST_FLAG_S, ft_ssl_dgst_parse_options_s }
    };
	int i;
	
	i = -1;
	while (++i < FT_SSL_DGST_FLAG)
		if (flag == opt[i].opt_flag)
			return (opt[i].opt_dist(ftssl_dgst));
	return (ft_ssl_dgst_error_opt(ftssl_dgst->inpt.cmd_name, flag));
}

int		ft_ssl_dgst_exec(t_ftssl_dgst *ftssl_dgst) 

int		ft_ssl_dgst_parse_options(t_ftssl_dgst *ftssl_dgst)
{

	int	*piarg;
	int	*pjarg;

	piarg = &ftssl_dgst->iarg;
	pjarg = &ftssl_dgst->jarg;
	while (*piarg < ftssl_dgst->argc && ftssl_dgst->argv[*piarg][*pjarg] == '-')
	{
		if (ftssl_dgst->argv[*piarg][*pjarg + 1] == '\0')
			break;
		while (ftssl_dgst->argv[*piarg][*++pjarg] != '\0')
			if (ft_ssl_dgst_dispatch_option(ftssl_dgst, ftssl_dgst->argv[*piarg][*pjarg]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	while (*piarg < ftssl_dgst->argc)
		ft_ssl_dgst_
	return (EXIT_SUCCESS);
}

int     ft_ssl_dgst(int argc, char *argv[])
{
    printf("dgst has been.\n");
    t_dgst dgst;
	int i;
	t_ftssl_dgst	ftssl_dgst;

	i = 1;
	ft_memset(&ftssl_dgst, 0, sizeof(ftssl_dgst));
	ftssl_dgst.argc = argc;
	ftssl_dgst.argv = argv;

	// ft_ssl_dgst_init2(&ftssl_dgst, argv[0]);
	ft_ssl_dgst_parse_options(&ft_ssl_dgst);
	// ft_memset(&dgst, 0, sizeof(dgst));
	// ft_ssl_dgst_init(&dgst, argv[0]);
	// printf("\n\nLen : %d \n\n\n", dgst.dist.ctx.len_state);
	// // if (argc > 1)
	// 	ft_ssl_dgst_parse(&dgst, argc, argv);
	// else
		// ft_ssl_dgst_mdsha_file(&dgst, NULL);
	
	// ft_ssl_dgst_mdsha_string(&dgst, "abc", 3);
	// t_dgst 	ftssl_dgst;

	// if (ft_ssl_dgst_init(&ftssl_dgst, argv[0]) == EXIT_SUCCESS)
	// 	return (EXIT_FAILURE);
	// int  i;
    // t_dgst_ctx  ctx;
	// t_dgst_act	act;
	// t_dgst		dgst;

	// i = 0;
    // ft_memset(&ctx, 0, sizeof(t_dgst_ctx));
	// // ft_dgst_init(&dgst);
	// dgst.cmd_name = argv[0];
    // ft_dgst_dispatcher_ctx(cmd_key, &dgst.ctx);
	// ft_dgst_dispatcher_act(cmd_key, &dgst.act);
	// dgst.input.ipt_key = FT_DGST_INPUT;
	// dgst.input.ipt_name = NULL;
    // printf("cmd = %d && hs = %d\n", i, argc);
	// if (++i == argc)
	// 		ft_ssl_dgst_mdsha_file(&dgst, NULL); //ft_ssl_dgst_perform(&dgst, dgst.input); // ft_ssl_dgst_execute(&dgst.ctx, &dgst.act, (t_dgst_ipt){ FT_DGST_INPUT, NULL });// 
	// while (i < argc)
	// {
	// 	if (argv[i] != NULL && *argv[i] == '-')
	// 	{
	// 		// ft_ssl_dgst_flags();
	// 		printf("flag will modified\n");
	// 	}
	// 	else if (argv[i] != NULL)
	// 	{
	// 		printf("here argument\n");
	// 		dgst.input.ipt_key = FT_DGST_FILE;
	// 		dgst.input.ipt_name = argv[i];
	// 	}
	// 	// i++;
	// 	printf("execute\n");
	// 	// ft_ssl_dgst_perform(&dgst, dgst.input); // ft_ssl_dgst_execute(&dgst.ctx, &dgst.act, (t_dgst_ipt){ FT_DGST_INPUT, NULL });// 
	// }
	// if (++i == argc)
	// 	ft_ssl_dgst_perform(&dgst, (t_dgst_ipt){ FT_DGST_INPUT, NULL }); // ft_ssl_dgst_execute(&dgst.ctx, &dgst.act, (t_dgst_ipt){ FT_DGST_INPUT, NULL });// 
	// else
	// 	while (i < argc)
	// 	{
	// 		printf("%s - len %d .\n", argv[i], ft_strlen(argv[i]));
	// 		// if (*argv[i] == '-')
	// 		// {

	// 		// 	// ft_
	// 		// 	// ft_ssl_parse_execute_flag(argv[i]);
	// 		// }
	// 		ft_ssl_dgst_perform(&dgst, (t_dgst_ipt){ FT_DGST_FILE, argv[i] }); // ft_ssl_dgst_execute(&dgst.ctx, &dgst.act, (t_dgst_ipt){ FT_DGST_INPUT, NULL });// 
	// 		// else
	// 		// ft_ssl_dgst_execute(&dgst.ctx, &dgst.act, (t_dgst_ipt){ FT_DGST_FILE, argv[i] });
	// 		i++;
	// 	}
	return (0);   
}
