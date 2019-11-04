/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_error.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:12:18 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 22:12:19 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

int     ft_ssl_error(int argc, char *argv[])
{
    ft_putstr("ftssl:Error: '");
    ft_putstr(argv[0]);
    ft_putendl("' is an invalid command.");
    ft_ssl_usage(0, NULL);
    return (EXIT_SUCCESS);
}