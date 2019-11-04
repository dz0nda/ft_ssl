/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:12:50 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 22:12:51 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

int			ft_ssl(int argc, const char *argv[])
{
	t_ftssl ftssl;

	ft_memset(&ftssl, 0, sizeof(ftssl));
	ft_ssl_init(&ftssl, argc, argv);
	while (42)
	{
		if (ftssl.shmode == FTSSL_SHMODE_ENABLED)
			if (ft_ssl_shell(&ftssl.sh) == EXIT_FAILURE)
				break ;
		ft_ssl_dist_exec(ftssl.sh.argc, ftssl.sh.argv);
		if (ftssl.shmode == FTSSL_SHMODE_DISABLED)
			break;
	}
	return (EXIT_SUCCESS);
}

int			main(int argc, const char *argv[])
{
	return (ft_ssl(argc - 1, ++argv));
}


