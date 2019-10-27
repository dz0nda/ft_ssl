#include "ft_ssl.h"

int 	ft_ssl_parse_execute_file(char *file)
{
	printf("'%s' will be considered as a file\n", file);
	return (EXIT_SUCCESS);
}

int 	ft_ssl_parse_execute_flag(char *flag)
{
	int i;

	i = 0;
	while (flag[++i] != '\0')
	{
		if (ft_ssl_parse_flags_md(flag[i]) == EXIT_FAILURE)
			return (ft_ssl_parse_flag_unknown(flag[i]));
		else
			printf("flag '%c' recognized \n", flag[i]);
	}
	return (EXIT_SUCCESS);
}

// int		ft_ssl_parse_execute(int argc, char *argv[])
// {
// 	int pqrs[4];
//     int  i = 0;
// 	int  j = -1;

//     memset(pqrs, 0, sizeof(pqrs));
//     while (++i < argc)
//     {
// 		if (*argv[i] == '-')
// 			ft_ssl_parse_execute_flag(argv[i]);
// 		else
// 			ft_ssl_parse_execute_file(argv[i]);
		
//         // while (argv[i][0] == '-' && *++argv[i])
//         // {
// 		// 	if (ft_ssl_parse_flags_md(*argv[i]) == EXIT_FAILURE)
// 		// 		return (ft_ssl_parse_flag_unknown(*argv[i]));
// 		// 	else
// 		// 		printf("flag '%c' recognized \n", *argv[i]);
//         // }
//         // if (argv[i][0] != '-')
// 		// {
//         //     printf("'%s' will be considered as a file\n", argv[i]);
//         // }
//     }
// 	return (EXIT_SUCCESS);
// }

// int 	ft_ssl_parse_command(t_ftssl *ssl)
// {
// 	const char *ftssl_commands[FT_SSL_TYPE][FT_SSL_DGST_CMD] = { 
// 		{ "md5", "sha1", "sha256" }, { NULL, NULL, NULL },
// 		{ NULL, NULL, NULL } };
//     int type;
// 	int	cmd;

//     type = -1;
//     while (++type < FT_SSL_TYPE)
// 	{
// 		cmd = -1;
// 		while (++cmd < FT_SSL_DGST_CMD && ftssl_commands[type][cmd] != NULL)
//         	if (ft_strcmp(ssl->sh.argv[0], ftssl_commands[type][cmd]) == 0)
// 			{
// 				ssl->ctx.ftssl_type = type;
// 				ssl->ctx.ftssl_cmd = cmd;
// 				return (EXIT_SUCCESS);
// 			}
// 	}
// 	ssl->ftssl_stat = FT_SSL_COMMAND_INVALID;
//     return (EXIT_SUCCESS);
// }

int		ft_ssl_parse_execute(t_ftssl *ssl, int argc, char *argv[])
{
	int pqrs[4];
    int  i = 0;
	int  j = -1;

    memset(pqrs, 0, sizeof(pqrs));
	if (argv[i] == NULL)
	{
		ssl->ftssl_stat = FT_SSL_COMMAND_MISSING;
		return 1;
	}
    while (++i < argc)
    {
		if (*argv[i] == '-')
			ft_ssl_parse_execute_flag(argv[i]);
		else
			ft_ssl_parse_execute_file(argv[i]);
    }
	return (EXIT_SUCCESS);
}

int 	ft_ssl_parse_type(t_ftssl *ssl)
{
	static int (* const ftssl_parse_cmd[FT_SSL_TYPE])(char *) = { 
		ft_ssl_parse_type_dgst,
		ft_ssl_parse_type_cipher,
		ft_ssl_parse_type_stdrd
	};
	static int (* const ftssl_cmd[FT_SSL_TYPE + 1])(t_ftssl *) = { 
		ft_dgst,
		ft_cipher,
		ft_stdrd,
		ft_unknown
	};
    int i;

    i = -1;
    while (++i < FT_SSL_TYPE)
		if (ftssl_parse_cmd[i](ssl->sh.argv[0]) == EXIT_SUCCESS)
			break ;
	// 	{
	// 		ssl->ctx.ftssl_type = i;
	// 		ssl->ctx.ftssl_cmd = ftssl_cmd[i];
	// 		return (EXIT_SUCCESS);
	// 	}
	// }
	// ssl->ftssl_stat = FT_SSL_COMMAND_INVALID;
	ssl->key = i;
	ssl->ftssl_cmd = ftssl_cmd[i];
	return (EXIT_SUCCESS);

	// const char *ftssl_type[FT_SSL_TYPE] = { 
	// 	{ "md5", "sha1", "sha256" }, { NULL, NULL, NULL },
	// 	{ NULL, NULL, NULL } };
    // int type;
	// int	cmd;

    // type = -1;
    // while (++type < FT_SSL_TYPE)
	// {
	// 	cmd = -1;
	// 	while (++cmd < FT_SSL_DGST_CMD && ftssl_commands[type][cmd] != NULL)
    //     	if (ft_strcmp(ssl->sh.argv[0], ftssl_commands[type][cmd]) == 0)
	// 		{
	// 			ssl->ctx.ftssl_type = type;
	// 			ssl->ctx.ftssl_cmd = cmd;
	// 			return (EXIT_SUCCESS);
	// 		}
	// }
	// ssl->ftssl_stat = FT_SSL_COMMAND_INVALID;
    // return (EXIT_SUCCESS);
}

char	*ft_ssl_input_fd(int fd)
{
	int len = 512;
	int i = -1;
    char c[2];
    int bytes_read;
	char buffer[513];
	
	ft_memset(buffer, 0, sizeof(buffer));
	ft_memset(c, 0, sizeof(c));
	while (++i < len)
	{
		if ((bytes_read = read(fd, &c, 1)) < 0)
			break;
		if (c[0] == '\n')
			break ;
        ft_strcat(buffer, c);
        // ft_putchar(c[0]);
        ft_memset(c, 0, sizeof(c));
    }
	return (ft_strdup(buffer));
}

char	*ft_ssl_input_string(char *s)
{
	ft_putendl(s);
	return (ft_strdup(s));
}

char	*ft_ssl_input_dispatch(t_input_u *input, int type)
{
	if (type == FT_INPUT_FILE)
		return (ft_ssl_input_fd(input->fd));
	if (type == FT_INPUT_STRING)
		return (ft_ssl_input_string(input->s));
}

int 	ft_ssl_dispatch()
{
	const t_ftssl_cmd	ftssl_dispatcher[] = {
		{ FT_DGST, ft_dgst},
		{ FT_CIPHER, ft_cipher},
		{ FT_STDRD,	ft_stdrd },
    };

	
}

int		ft_ssl_execute(t_ftssl	*ssl)
{
	// if (ssl->ftssl_stat == FT_SSL_ARGUMENT_MISSING)
	// ft_ssl_getInput(ssl);
	// ft_ssl_parse_type(ssl);
	// ssl->ftssl_cmd(ssl);
	// while (ssl->ftssl_mode == FT_SHMODE_TRUE)
	// {

	if (ssl->sh.argc == 0)
		ft_ssl_getInput(ssl);
	ft_ssl_parse_type(ssl);
	ssl->ftssl_cmd(ssl);
	ft_ssl_reset(ssl);

	// t_input_u input;
	// input.s = "mystring";
	// int type = 1;
	// ssl->ftssl_input = ft_ssl_input_dispatch;
	// ssl->ftssl_input(&input, type);

	// if (ssl->sh.argc == 0)
	// 	ft_ssl_shell(&ssl->sh);
	// if (ssl->sh.argc == 0)
	// 	return (ssl->ftssl_usage());
	// ft_ssl_parse_command(ssl);
	// if (ssl->ftssl_stat != FT_SSL_SUCCESS)
	// 	return (ssl->ftssl_error(ssl->sh.argv[0]));
	// ft_ssl_parse_execute(ssl->sh.argc, ssl->sh.argv);
	return (EXIT_SUCCESS);
}

// int 	dispatchType(t_ftssl *ssl)
// {
// 	if (ssl->ctx.ftssl_type == FT_DGST)
// 		return (ft_dgst((t_dgst *)&ssl->ctx.ctx, ssl->ctx.ftssl_cmd));
// 	return (-1);
// }


static int		ft_ssl_init(t_ftssl *ssl, int argc, char const *argv[])
{
    int i;

    i = 0;
	if (argc < 1)
		return (EXIT_SUCCESS);
	// ssl->sh.cmd = ft_strdup(argv[0]);
	ft_strncpy(ssl->sh.cmd, argv[0], FTSSL_SHMAX_BUFFER);
	while (++i < argc && i < FTSSL_SHMAX_ARG)
		ft_strncpy(ssl->sh.cmd, argv[i], FTSSL_SHMAX_BUFFER);
		// if ((ssl->sh.argv = ft_strdup(argv[i])) == NULL)
        //     return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int		main(int argc, char const *argv[])
{
	t_ftssl	ssl;

	ft_ssl_reset(&ssl);
	if (ft_ssl_init(&ssl, argc - 1, ++argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_ssl_execute(&ssl);
	ft_ssl_reset(&ssl);
	return (EXIT_SUCCESS);

	// ft_ssl_execute(&ssl);
	// ft_ssl_shell(&ssl);
// 	dispatchType(&ssl);
	// int i = -1;
	// while (++i < ssl.sh.argc)
	// 	ft_putendl(ssl.sh.argv[i]);
	// if (argc < 2)
	// 	return (ssl.usage());
	// if (argc < 2)
	// 	ft_ssl_shell(&ssl);
	
	
	// const unsigned char arg[64] = "abc";

	// unsigned char md[16];
	// size_t        len;

	// ft_bzero(md, sizeof(md));
	// len = ft_strlen((const char *)arg);
	// ft_dgst(arg, len, md);
	// printf("\nMD5(%s)\n", md);
	// ft_ssl_reset(&ssl);
	return (ssl.ftssl_stat);
}
