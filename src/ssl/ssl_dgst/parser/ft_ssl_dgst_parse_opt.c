/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_parse_opt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:57:49 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/06 15:25:15 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_dgst.h"

int			ft_isopt(t_ftssl_dgst_args args)
{
	if (args.iarg < args.argc)
		if (*args.argv[args.iarg] == '-' && args.argv[args.iarg][1] != '\0')
			return (1);
	return (0);
}

int			ft_ssl_dgst_parse_opt(t_ftssl_dgst *ftssl_dgst)
{
	while (ft_isopt(ftssl_dgst->args))
		if (ft_ssl_dgst_opt(ftssl_dgst) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}