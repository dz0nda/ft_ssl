#include "ft_ssl.h"

int		ft_ssl_usage(int argc, char *argv[])
{
	const char *dist[FTSSL_DIST_E] = {
		"Help commands:", "Message Digest commands:",
		"Cipher commands:", "Standard commands:"
	};
	const char *dist_cmd[FTSSL_DIST_E][FTSSL_SHMAX_BUFFER] = {
		{ "help" },
		{ "md5", "sha1" "sha256" },
		{ "base64", "des" },
		{ NULL }
	};
	int key_dist;
	int	key_dist_cmd;

	(void)argc;
	(void)argv;
	key_dist = -1;
	while (++key_dist < FTSSL_DIST_E)
	{
		key_dist_cmd = -1;
		ft_putendl(dist[key_dist]);
		if (dist_cmd[key_dist] != NULL)
			while (dist_cmd[key_dist][++key_dist_cmd] != NULL )
				ft_putendl(dist_cmd[key_dist][key_dist_cmd]);
		ft_putstr("\n");
	}
	return (EXIT_FAILURE);
}