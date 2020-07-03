/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:50:02 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/20 23:52:12 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_dgst.h"

int				ft_ssl_dgst_output_string(t_ftssl_dgst *ftssl_dgst)
{
	int i;

	i = -1;
	while (ftssl_dgst->cmd_name[++i] != '\0')
		ft_putchar(ft_toupper(ftssl_dgst->cmd_name[i]));
	ft_putstr(" (");
	ft_putchar('\"');
		if (ftssl_dgst->args.argv[ftssl_dgst->args.iarg] && ftssl_dgst->args.argv[ftssl_dgst->args.iarg][ft_strlen(ftssl_dgst->args.argv[ftssl_dgst->args.iarg]) - 1] == '\n')
			ftssl_dgst->args.argv[ftssl_dgst->args.iarg][ft_strlen(ftssl_dgst->args.argv[ftssl_dgst->args.iarg]) - 1] = '\0';
	ft_putstr(ftssl_dgst->cmd_arg);
	ft_putchar('\"');
	ft_putstr(") = ");
	ft_putendl(ftssl_dgst->md);
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output(t_ftssl_dgst *ftssl_dgst)
{
	int i;

	i = -1;
	if (ftssl_dgst->cmd_arg != NULL)
	{
		while (ftssl_dgst->cmd_name[++i] != '\0')
			ft_putchar(ft_toupper(ftssl_dgst->cmd_name[i]));
		ft_putstr(" (");
	}
	ft_putstr(ftssl_dgst->cmd_arg);
	if (ftssl_dgst->cmd_arg != NULL)
		ft_putstr(") = ");
	ft_putendl(ftssl_dgst->md);
	return (EXIT_SUCCESS);
}