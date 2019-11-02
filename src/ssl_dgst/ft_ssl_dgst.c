#include "ft_ssl_dgst.h"

// char	*ft_ssl_input_fd(int fd, int len)
// {
// 	int len = 512;
// 	int i = -1;
//     char c[2];
//     int bytes_read;
// 	char buffer[513];
	
// 	ft_memset(buffer, 0, sizeof(buffer));
// 	ft_memset(c, 0, sizeof(c));
// 	while (++i < len)
// 	{
// 		if ((bytes_read = read(fd, &c, 1)) < 0)
// 			break;
// 		if (c[0] == '\n')
// 			break ;
//         ft_strcat(buffer, c);
//         // ft_putchar(c[0]);
//         ft_memset(c, 0, sizeof(c));
//     }
// 	return (ft_strdup(buffer));
// }


// void readFile(int fd, int len) {
//     char buffer[10];
//     int bytes_read;
//     int k = 0;
//     do {
//         char t = 0;
//         bytes_read = read(fd, &t, 1); 
//         buffer[k++] = t;    
//         printf("%c", t);
//         if(t == '\n' && t == '\0') {
//             printf("%d", atoi(buffer));
//             for(int i=0; i<10; i++)
//                 buffer[i]='\0';
//             k = 0;
//         }
//     }
//     while (bytes_read != 0); 
// }

int     ft_ssl_dgst_execute(t_dgst_ctx *ctx, t_dgst_act *act, t_dgst_ipt ipt)
{
	char *string_input;
	int len_input;
	char md[ctx->len_hs];

	len_input = 0;
	act->init(ctx);
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	while ((ctx->len_block = get_input(ctx->block, ipt, ctx->len_mbs)) == ctx->len_mbs)
	{
		ctx->len_input += ctx->len_block;
		printf("len_read %d - ", ctx->len_block);
		ft_putendl((char *)ctx->block);// write(1, ctx->block, ctx->len_mbs);// for(int i = 0; i < ctx->len_mbs; i++)
		ft_memset(ctx->block, 0, sizeof(uint8_t));
	}
	ctx->len_input += ctx->len_block;	
	printf("len_read %d - \n len_input - %d\n", ctx->len_block, ctx->len_input);
	ft_putendl((char *)ctx->block);
	act->final(ctx);
	act->update(ctx);
	ft_ssl_dgst_result(ctx);


		// {
		// 	// ft_putchar(ctx->block[i]);
		// 	// ft_memset(ctx->block, 0, ctx->len_mbs);
		// }
	// act->update(ctx);
	// act->final(ctx);
	return (EXIT_SUCCESS);
}

int     ft_ssl_dgst_perform(t_dgst *dgst, t_dgst_ipt ipt)
{
	t_dgst_ctx *ctx; 
	t_dgst_act *act;

	ctx = &dgst->ctx;
	act = &dgst->act;
	dgst->act.init(&dgst->ctx);
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	while ((ctx->len_block = get_input(ctx->block, ipt, ctx->len_mbs)) == ctx->len_mbs)
	{
		ctx->len_input += ctx->len_block;	
		act->update(ctx);
		ft_memset(ctx->block, 0, sizeof(ctx->block));
	}
	ctx->len_input += ctx->len_block;	
	act->final(ctx);
	act->update(ctx);
	ft_ssl_dgst_result(ctx);
}

// int 	ft_ssl_dgst_init(t_dgst *dgst)
// {

// }

int		ft_ssl_dgst_flags(char flag)
{
	

}

int     ft_ssl_dgst(int cmd_key, int argc, char *argv[])
{
    printf("dgst has been.\n");
    
	int  i;
    t_dgst_ctx  ctx;
	t_dgst_act	act;
	t_dgst		dgst;

	i = 0;
    ft_memset(&ctx, 0, sizeof(t_dgst_ctx));
	// ft_dgst_init(&dgst);
	dgst.cmd_name = argv[0];
    ft_dgst_dispatcher_ctx(cmd_key, &dgst.ctx);
	ft_dgst_dispatcher_act(cmd_key, &dgst.act);
	dgst.input.ipt_key = FT_DGST_INPUT;
	dgst.input.ipt_name = NULL;
    printf("cmd = %d && hs = %d\n", i, argc);
	if (++i == argc)
			ft_ssl_dgst_perform(&dgst, dgst.input); // ft_ssl_dgst_execute(&dgst.ctx, &dgst.act, (t_dgst_ipt){ FT_DGST_INPUT, NULL });// 
	while (i < argc)
	{
		if (argv[i] != NULL && *argv[i] == '-')
		{
			// ft_ssl_dgst_flags();
			printf("flag will modified\n");
		}
		else if (argv[i] != NULL)
		{
			printf("here argument\n");
			dgst.input.ipt_key = FT_DGST_FILE;
			dgst.input.ipt_name = argv[i];
		}
		i++;
		printf("execute\n");
		// ft_ssl_dgst_perform(&dgst, dgst.input); // ft_ssl_dgst_execute(&dgst.ctx, &dgst.act, (t_dgst_ipt){ FT_DGST_INPUT, NULL });// 
	}
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
