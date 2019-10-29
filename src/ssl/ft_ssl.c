#include "ft_ssl.h"

// int		ft_ssl_execute(t_ftssl	*ssl)
// {
// 	const t_ftssl_dispatcher ftssl_type_dispatch[FTSSL_TYPE_E] = {
// 		{ FT_DGST, ft_ssl_parse_type_dgst, ft_dgst },
// 		{ ft_ssl_cipher, ft_ssl_parse_type_cipher, ft_ssl_cipher },
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





// int			ft_ssl(t_ftssl_ctx *ctx)
// {
	
// }

int			main(int argc, char const *argv[])
{
	if (argc > 1)
		;// ft_ssl_shell();
	ft_ssl_dispatcher(argc - 1, (char **)++argv);
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


