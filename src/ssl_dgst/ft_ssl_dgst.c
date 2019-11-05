#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_parse_flag(t_dgst *dgst, int argc, char *argv[])
{
	// const char
	// int i;

	// i = 1;
}

int     ft_ssl_dgst_parse(t_dgst *dgst, int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	j = 0;
	printf("argc %d\n", argc);
	while (i < argc && argv[i] &&  argv[i][j] == '-')
	{
		while (argv[i][++j])
		{
			if (argv[i][j] == 's')
				ft_ssl_dgst_mdsha_string(dgst, argv[i + 1], ft_strlen(argv[i + 1]));// printf("sok\n");
			else if (argv[i][j] == 'p')
				ft_ssl_dgst_mdsha_file(dgst, NULL); // printf("pok\n");
			else if (argv[i][j] == 'q')
				dgst->output = ft_ssl_dgst_output_q;
			else if (argv[i][j] == 'r')
			{
				printf("rok\n");
				dgst->output = ft_ssl_dgst_output_r;
			}
			else
				return (ft_ssl_dgst_error(argv[0], &argv[i][j]));
		}
		i++;
		j = 0;
	}
	if (i == argc)
		ft_ssl_dgst_mdsha_file(dgst, NULL);
	else
		while (i < argc)
			ft_ssl_dgst_mdsha_file(dgst, argv[i++]);
}

int     ft_ssl_dgst(int argc, char *argv[])
{
    printf("dgst has been.\n");
    t_dgst dgst;

	ft_memset(&dgst, 0, sizeof(dgst));
	ft_ssl_dgst_init(&dgst, argv[0]);
	printf("\n\nLen : %d \n\n\n", dgst.ctx.len_state);
	// if (argc > 1)
		ft_ssl_dgst_parse(&dgst, argc, argv);
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
