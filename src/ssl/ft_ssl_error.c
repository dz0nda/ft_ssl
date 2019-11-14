/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_error.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:12:18 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 08:30:33 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

int		ft_ssl_error(int argc, char *argv[])
{
	(void)argc;
	ft_putstr_fd("ftssl:Error: '", STDERR_FILENO);
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putendl_fd("' is an invalid command.", STDERR_FILENO);
	ft_ssl_usage(0, NULL);
	return (EXIT_SUCCESS);
}
