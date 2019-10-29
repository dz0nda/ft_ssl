#include "ft_ssl.h"

// int		ft_ssl_execute(t_ftssl	*ssl)
// {
// 	const t_ftssl_dispatcher ftssl_type_dispatch[FTSSL_TYPE_E] = {
// 		{ FT_DGST, ft_ssl_parse_type_dgst, ft_dgst },
// 		{ FT_CIPHER, ft_ssl_parse_type_cipher, ft_cipher },
// 		{ FT_STDRD, ft_ssl_parse_type_stdrd, ft_stdrd },
// 		{ FT_UNKNOWN, ft_ssl_parse_type_unknown, ft_unknown },
// 	};
//     int i;

//     i = -1;
//     while (++i < FTSSL_TYPE_E)
// 		if (ftssl_type_dispatch[i].ftssl_parse_cmd(ssl->sh.cmd) != -1)
// 			break;
// 	ftssl_type_dispatch[i].ftssl_dist(ssl);
// 	return (EXIT_SUCCESS);
// }

int     ft_ssl_dgst_dispatcher(int argc, char *argv[])
{
    const t_ftssl_dgst_dispatcher[FT_DGST_CMD] = {
        "md5",
        "sha1",
        "sha256"
    };
    int i;

    i = -1;
    while (++i < FT_DGST_CMD)
        if (ft_strcmp(s, ft_ssl_dgst_cmd[i]) == 0)
            return (i);
    return (-1);
}

int		ft_ssl_dispatcher(int argc, char *argv)
{
	const t_ftssl_dispatcher ftssl_dispatcher[FTSSL_TYPE_E] = {
		{ FT_DGST, ft_ssl_dgst_dispatcher },
		{ FT_CIPHER, ft_ssl_parse_type_cipher },
		{ FT_STDRD, ft_ssl_parse_type_stdrd, ft_stdrd },
		{ FT_UNKNOWN, ft_ssl_parse_type_unknown, ft_unknown },
	};
    int i;

    i = -1;
    while (++i < FTSSL_TYPE_E)
		if (ftssl_dispatcher[i].ftssl_parse_cmd(argv[0]) != -1)
			break;
	ftssl_type_dispatch[i].ftssl_dist(ssl);
	return (EXIT_SUCCESS);
}

int			ft_ssl(t_ftssl_ctx *ctx)
{
	
}

int			main(int argc, char const *argv[])
{
	if (argc > 1)
		;// ft_ssl_shell();
	ft_ssl_dispatch_type(argc - 1, ++argv);
	return (EXIT_SUCCESS);
	// t_ftssl	ssl;

	// ft_memset(&ssl, 0, sizeof(ssl));
	// if (ft_ssl_init(&ssl, argc - 1, ++argv) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	// if (ssl.sh.argc < 1) ;
	// // 	while (ft_ssl_shell(&ssl.sh) > 0)
	// // 		; //ft_ssl_execute(&ssl);
	// else
	// 	ft_ssl_execute(&ssl);
	// ft_ssl_reset(&ssl);
	// return (EXIT_SUCCESS);
}


