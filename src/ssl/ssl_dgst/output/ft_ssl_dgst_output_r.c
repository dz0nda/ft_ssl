/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_output_r.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:50:08 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/21 00:38:17 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_dgst.h"

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