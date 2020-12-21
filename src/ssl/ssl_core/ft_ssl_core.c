/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:01:39 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/21 13:13:44 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_core.h"

int     ft_ssl_core(int argc, char *argv[])
{
	if (ft_ssl_core_dist(argc, argv) == FT_SSL_DIST_NOT_FOUND)
		return (FT_SSL_DIST_NOT_FOUND);
	return (EXIT_SUCCESS);
}