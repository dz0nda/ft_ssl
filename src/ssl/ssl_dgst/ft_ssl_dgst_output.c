/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/04 15:28:32 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int				ft_ssl_dgst_output_string(t_ftssl_dgst *ftssl_dgst)
{
	int i;

	i = -1;
	if (ftssl_dgst->flag_r == 1)
	{
			ft_putstr(ftssl_dgst->md);
			if (ftssl_dgst->cmd_arg != NULL)
				ft_putchar(' ');
			ft_putchar('\"');
			ft_putstr(ftssl_dgst->cmd_arg);
			ft_putendl("\"");
	}
	else
	{
		while (ftssl_dgst->dist.name[++i] != '\0')
			ft_putchar(ft_toupper(ftssl_dgst->dist.name[i]));
		ft_putstr(" (");
		ft_putchar('\"');
		ft_putstr(ftssl_dgst->cmd_arg);
		ft_putchar('\"');
		ft_putstr(") = ");
		ft_putendl(ftssl_dgst->md);
	}
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output_file(t_ftssl_dgst *ftssl_dgst)
{
	int i;

	i = -1;
	if (ftssl_dgst->flag_r == 1)
	{
		ft_putstr(ftssl_dgst->md);
		ft_putchar(' ');
		ft_putendl(ftssl_dgst->cmd_arg);
	}
	else
	{
		while (ftssl_dgst->dist.name[++i] != '\0')
			ft_putchar(ft_toupper(ftssl_dgst->dist.name[i]));
		ft_putstr(" (");
		ft_putstr(ftssl_dgst->cmd_arg);
		ft_putstr(") = ");
		ft_putendl(ftssl_dgst->md);
	}
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output_default(t_ftssl_dgst *ftssl_dgst)
{
	ft_putendl(ftssl_dgst->md);
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output(t_ftssl_dgst *ftssl_dgst)
{
	static t_ftssl_dgst_outp_d	outp[FTSSL_DGST_OUTP] = {
		{ FTSSL_DGST_OUTP_DEFAULT, 	ft_ssl_dgst_output_default   },
		{ FTSSL_DGST_OUTP_QUIET, 		ft_ssl_dgst_output_default   },
		{ FTSSL_DGST_OUTP_STRING, 	ft_ssl_dgst_output_string },
		{ FTSSL_DGST_OUTP_FILE, 		ft_ssl_dgst_output_file }
	};

	return (outp[ftssl_dgst->outp_key].outp_dist(ftssl_dgst));
}