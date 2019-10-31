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

int		read_file(char *dst, char *src, int len)
{
	static int fd = -1;
	int i;
	int bytes_read;
	char c[2];

	i = -1;
	bytes_read = -1;
	ft_memset(c, 0, sizeof(c));
	if (access(src, F_OK) == -1)
		return (-1);
	if (fd == -1 && (fd = open(src, O_RDONLY)) == -1)
		return (-1);
	while (++i < len)
	{
		if ((bytes_read = read(fd, &c, 1)) < 1)
			break ;
        ft_strcat(dst, c);
        ft_memset(c, 0, sizeof(c));
    }
	if (bytes_read < 1 && close(fd) == -1)
		return (-1);
	else if (bytes_read < 1)
		fd = -1;
	return (i);
}

int		read_string(char *dst, char *src, int len)
{
	static int i = 0;
	int j;

	j = 0;
	while (j < len)
	{
		if (src[i] == '\0')
			break;
        dst[j++] = src[i++];
    }
	if (src[i] == '\0')
		i = 0;
	dst[j] = '\0';
	return (j);
}

int		read_input(char *dst, char *src, int len)
{
	static int bytes_read = 1;
	static char buffer[4096];
	char c[2];

	printf("sizeof buffer : %ld\n", sizeof(buffer));
	// ft_bzero(buffer, sizeof(buffer));
	ft_memset(c, 0, sizeof(c));
	if (bytes_read == 1)
		while ((bytes_read = read(0, &c, 1)) > 0)
		{
			ft_strcat(buffer, c);
			ft_memset(c, 0, sizeof(c));
		}
	return (read_string(dst, buffer, len));
}

int 	get_input(uint8_t *block, t_dgst_ipt ipt, int len)
{
	if (ipt.ipt_key == FT_DGST_FILE)
	{
		return (read_file((char *)block, ipt.ipt_name, len));
			// printf("File %s not found or not accessible.\n", ipt.ipt_name);
	}
	if (ipt.ipt_key == FT_DGST_STRING)
		return (read_string((char *)block, ipt.ipt_name, len));
	if (ipt.ipt_key == FT_DGST_INPUT)
		return (read_input((char *)block, ipt.ipt_name, len));
	return (EXIT_SUCCESS);
}

int     ft_ssl_dgst_execute(t_dgst_ctx *ctx, t_dgst_act *act, t_dgst_ipt ipt)
{
	char *string_input;
	int len_input;
	char md[ctx->len_hs];

	len_input = 0;
	act->init(ctx);
	ft_memset(ctx->block, 0, sizeof(uint8_t));
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

int     ft_ssl_dgst(int cmd_key, int argc, char *argv[])
{
    printf("dgst has been.\n");
    
	int  i;
    t_dgst_ctx  ctx;
	t_dgst_act	act;

	i = 0;
    ft_memset(&ctx, 0, sizeof(t_dgst_ctx));
    ft_dgst_dispatcher_ctx(cmd_key, &ctx);
	ft_dgst_dispatcher_act(cmd_key, &act);
    printf("cmd = %d && hs = %d\n", i, argc);
	if (i + 1 == argc)
		ft_ssl_dgst_execute(&ctx, &act, (t_dgst_ipt){ FT_DGST_INPUT, NULL });
	else
		while (++i < argc)
		{
			printf("%s - len %d .\n", argv[i], ft_strlen(argv[i]));
			// if (*argv[i] == '-')
			// 	ft_ssl_parse_execute_flag(argv[i]);
			// else
			ft_ssl_dgst_execute(&ctx, &act, (t_dgst_ipt){ FT_DGST_FILE, argv[i] });
		}
	return (0);   
}
