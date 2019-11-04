#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_mdsha_file(t_dgst *dgst, char *filename)
{
	int i, fd;
	char c[2];
	t_dgst_dist dist;
	t_dgst_ctx 	ctx;

	i = -1;
	ft_bzero(c, sizeof(c));
	dist = dgst->dist;
	ctx = dgst->ctx;

	if (access(filename, F_OK) == -1 || (fd = open(filename, O_RDONLY)) == -1)
		return (-1);

	ctx.state = (uint32_t *)ft_memalloc(sizeof(uint32_t) * ctx.len_state);
	ctx.block = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (ctx.len_mbs * 2));
	dist.init(&ctx);
	while ((ctx.iblock = read(fd, ctx.block, ctx.len_mbs)) == ctx.len_mbs)
	{
		ctx.len_input += ctx.iblock;
		dist.transform(&ctx);
		ft_memset(ctx.block, 0, sizeof(ctx.block));
	}
	ctx.len_input += ctx.iblock;
	// while (read(fd, c, 1) > 0)
	// {
	// 	ctx.len_input++;
	// 	ctx.block[ctx.iblock++] = c[0];
	// 	if (ctx.iblock == ctx.len_mbs)
	// 	{
	// 		dist.transform(&ctx);
	// 		ctx.iblock = 0;
	// 	}
	// 	ft_bzero(c, sizeof(c));
	// }
	dist.final(&ctx);
	dist.transform(&ctx); // need to be run in final
	ft_ssl_dgst_result(&ctx);
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_mdsha_string(t_dgst *dgst, char *data, size_t len)
{
	int i;
	t_dgst_dist dist;
	t_dgst_ctx 	ctx;

	i = -1;
	dist = dgst->dist;
	ctx = dgst->ctx;
	ctx.state = (uint32_t *)ft_memalloc(sizeof(uint32_t) * ctx.len_state);
	ctx.block = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (ctx.len_mbs * 2));
	ctx.len_input = len;
	dist.init(&ctx);
	while (ctx.idata < len)
	{
		ctx.block[ctx.iblock++] = data[ctx.idata++];
		if (ctx.iblock == ctx.len_mbs)
		{
			dist.transform(&ctx);
			ctx.iblock = 0;
		}
	}
	dist.final(&ctx);
	dist.transform(&ctx); // need to be run in final
	ft_ssl_dgst_result(&ctx);
	return (EXIT_SUCCESS);
}

int     ft_ssl_dgst(int argc, char *argv[])
{
    printf("dgst has been.\n");
    t_dgst dgst;

	ft_memset(&dgst, 0, sizeof(dgst));
	ft_ssl_dgst_init(&dgst, argv[0]);
	printf("\n\nLen : %d \n\n\n", dgst.ctx.len_state);
	ft_ssl_dgst_mdsha_file(&dgst, "ft_ssl");
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
