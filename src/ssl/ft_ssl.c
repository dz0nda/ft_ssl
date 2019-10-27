#include "ft_ssl.h"

const t_ftssl_type_dispatch g_ftssl_type_dispatch[FT_SSL_TYPE] = {
	{ FT_DGST, ft_ssl_parse_type_dgst, ft_dgst },
	{ FT_CIPHER, ft_ssl_parse_type_cipher, ft_cipher },
	{ FT_STDRD, ft_ssl_parse_type_stdrd, ft_stdrd },
	{ FT_UNKNOWN, ft_ssl_parse_type_unknown, ft_unknown },
 };

int 	ft_ssl_parse_type(t_ftssl *ssl)
{
    int i;

    i = -1;
    while (++i < FT_SSL_TYPE)
		if (g_ftssl_type_dispatch[i].ftssl_parse_cmd(ssl->sh.cmd) == EXIT_SUCCESS)
			break;
	g_ftssl_type_dispatch[i].ftssl_dist(&ssl->sh);
	return (EXIT_SUCCESS);
}



int		ft_ssl_execute(t_ftssl	*ssl)
{
	ft_ssl_parse_type(ssl);

	return (EXIT_SUCCESS);
}

// int 	dispatchType(t_ftssl *ssl)
// {
// 	if (ssl->ctx.ftssl_type == FT_DGST)
// 		return (ft_dgst((t_dgst *)&ssl->ctx.ctx, ssl->ctx.ftssl_cmd));
// 	return (-1);
// }

int		main(int argc, char const *argv[])
{
	t_ftssl	ssl;

	ft_memset(&ssl, 0, sizeof(ssl));
	if (ft_ssl_init(&ssl, argc - 1, ++argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ssl.sh.argc < 1)
		; // launch shell
	else
		ft_ssl_execute(&ssl);
	return (EXIT_SUCCESS);
}


