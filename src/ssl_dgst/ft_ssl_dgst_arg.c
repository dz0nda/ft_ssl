#include "ft_ssl_dgst.h"

// int    ft_ssl_parse_flags_md(char c)
// {
//     const char *flags = "pqrs";
//     size_t  nbflags;
//     int i;

//     nbflags = strlen(flags);
//     i = -1;
//     while (++i < nbflags)
//         if (flags[i] == c)
//             return (EXIT_SUCCESS);
//     return (EXIT_FAILURE);
// }

// int     ft_ssl_check_cmd(char *cmd)
// {
//     const char *ftssl_cmd[FT_DGST_CMD] = { "md5", "sha1", "sha256" };
//     int i;

//     i = -1;
//     while (++i < FT_DGST_CMD)
//         if (ft_strcmp(cmd, ftssl_cmd[i]) == 0)
//             break;
//     return (i);
// }

// int		ft_ssl_parse(int argc, char *argv[])
// {
// 	int pqrs[4];
//     int  i, files;
//     FILE *inf, *outf;

//     memset(pqrs, 0, sizeof(pqrs));
//     while (++i < argc)
//     {
//         if (argv[i][0] == '-')
//         {
//             while (*++argv[i])
//             {
//                 if (ft_ssl_parse_flags_md(*argv[i]) == EXIT_FAILURE)
//                     return (ft_ssl_parse_flag_unknown(*argv[i]));
//                 else
//                     printf("flag '%c' recognized \n", *argv[i]);
//             }
//         }
//         else
//         {
//             printf("'%s' will be considered as a file\n", argv[i]);
//         }
//     }
// 	return (EXIT_SUCCESS);
// }


// int 	ft_ssl_parse_execute_file(char *file)
// {
// 	printf("'%s' will be considered as a file\n", file);
// 	return (EXIT_SUCCESS);
// }

// int 	ft_ssl_parse_execute_flag(char *flag)
// {
// 	int i;

// 	i = 0;
// 	while (flag[++i] != '\0')
// 	{
// 		if (ft_ssl_parse_flags_md(flag[i]) == EXIT_FAILURE)
// 			return (ft_ssl_parse_flag_unknown(flag[i]));
// 		else
// 			printf("flag '%c' recognized \n", flag[i]);
// 	}
// 	return (EXIT_SUCCESS);
// }


// int		ft_ssl_parse_execute(t_ftssl *ssl, int argc, char *argv[])
// {
// 	int pqrs[4];
//     int  i = 0;
// 	int  j = -1;

//     memset(pqrs, 0, sizeof(pqrs));
// 	if (argv[i] == NULL)
// 	{
// 		ssl->ftssl_stat = FT_SSL_COMMAND_MISSING;
// 		return 1;
// 	}
//     while (++i < argc)
//     {
// 		if (*argv[i] == '-')
// 			ft_ssl_parse_execute_flag(argv[i]);
// 		else
// 			ft_ssl_parse_execute_file(argv[i]);
//     }
// 	return (EXIT_SUCCESS);
// }
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

char	*ft_ssl_input_string(char *d, char *s, int len)
{

	ft_putendl(s);
	return (ft_strdup(s));
}

// char	*ft_ssl_input_dispatch(int type)
// {
// 	if (type == FT_INPUT_STRING)
// 		return (ft_ssl_input_string);
//     return (ft_ssl_input_fd(input->fd));
// }

// int     ft_ssl_dgst_parse_file(t_ftssl_dgst *dgst, char i)
// {
//     dgst->ftssl_dgst_input[i] = ft_ssl_input_dispatch;
// }

int     ft_ssl_dgst_parse(t_ftssl_dgst *dgst, int argc, char *argv[])
{
    int  i = -1;

    while (++i < argc)
    {
		// if (*argv[i] == '-')
		// 	ft_ssl_parse_execute_flag(argv[i]);
		// else
	
		dgst->ftssl_dgst_input[i] = ft_ssl_(dgst, argv[i]);
    }
	return (EXIT_SUCCESS);
}