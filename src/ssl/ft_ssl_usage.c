/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_usage.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:11:53 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 14:36:08 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
		{ "dgst" }
	};
	int key_dist;
	int	key_dist_cmd;

	(void)argc;
	(void)argv;
	key_dist = -1;
	while (++key_dist < FTSSL_DIST_E)
	{
		key_dist_cmd = -1;
		ft_putendl_fd(dist[key_dist], STDERR_FILENO);
		if (dist_cmd[key_dist] != NULL)
			while (dist_cmd[key_dist][++key_dist_cmd] != NULL )
				ft_putendl_fd(dist_cmd[key_dist][key_dist_cmd], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (EXIT_FAILURE);
}