/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dist.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:13:04 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 09:57:19 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

int		ft_ssl_dist_exec(int argc, char *argv[])
{
	const t_ftssl_dist_t	dist[FTSSL_DIST_E] = {
		{ FTSSL_HELP, { "help" }, ft_ssl_usage },
		{ FTSSL_DGST, { "md5", "sha1", "sha224", "sha256", "sha384", "sha512" },
			ft_ssl_dgst },
		{ FTSSL_CIPHER, { "base64", "des" }, ft_ssl_cipher },
		{ FTSSL_STDRD, { "dgst" }, ft_ssl_stdrd } };
	int						key_dist;
	int						key_name;

	key_dist = -1;
	if (argv[0] == NULL)
		return (EXIT_SUCCESS);
	while (++key_dist < FTSSL_DIST_E)
	{
		key_name = -1;
		while (dist[key_dist].dist_name[++key_name] != NULL)
			if (ft_strcmp(dist[key_dist].dist_name[key_name], argv[0]) == 0)
				return (dist[key_dist].dist_ft(argc, argv));
	}
	return (ft_ssl_error(argc, argv));
}
