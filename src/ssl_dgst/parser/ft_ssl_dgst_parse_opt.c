/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_parse_opt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:57:49 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/15 19:21:20 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_dgst.h"

int			ft_isopt(int iarg, int argc, char *argv)
{
	if (iarg < argc && *argv == '-' && argv[1] != '\0')
		return (1);
	return (0);
}

int			ft_ssl_dgst_parse_opt(t_ftssl_dgst *ftssl_dgst, t_ftssl_dgst_args args)
{
	while (ft_isopt(ftssl_dgst->iarg, args.argc, args.argv[ftssl_dgst->iarg]))
		if (ft_ssl_dgst_opt(ftssl_dgst, args.argc, args.argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}