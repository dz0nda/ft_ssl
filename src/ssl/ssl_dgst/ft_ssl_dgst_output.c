/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/18 13:43:34 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int				ft_ssl_dgst_output_q(t_ftssl_dgst *ftssl_dgst)
{
	ft_putendl(ftssl_dgst->md);
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output_r(t_ftssl_dgst *ftssl_dgst)
{
	ft_putstr(ftssl_dgst->md);
	if (ftssl_dgst->cmd_arg != NULL)
		ft_putchar(' ');
	if (ftssl_dgst->inpt_key == FT_DGST_FILE)
		ft_putstr(ftssl_dgst->cmd_arg);
	else if (ftssl_dgst->inpt_key == FT_DGST_STRING)
	{
		ft_putchar('\"');
		ft_putstr(ftssl_dgst->cmd_arg);
		ft_putstr("\"");
	}
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output_string(t_ftssl_dgst *ftssl_dgst)
{
	int i;

	i = -1;
	while (ftssl_dgst->cmd_name[++i] != '\0')
		ft_putchar(ft_toupper(ftssl_dgst->cmd_name[i]));
	ft_putstr(" (");
	ft_putchar('\"');
	ft_putstr(ftssl_dgst->cmd_arg);
	ft_putchar('\"');
	ft_putstr(") = ");
	ft_putendl(ftssl_dgst->md);
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output_default(t_ftssl_dgst *ftssl_dgst)
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