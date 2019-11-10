/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_parse.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/10 15:44:55 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 17:59:50 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_parse_opt(t_ftssl_dgst *ftssl_dgst)
{
	t_ftssl_dgst_inpt *inpt;

	inpt = &ftssl_dgst->inpt;
	while (inpt->i < inpt->argc)
	{
		if (*inpt->argv[inpt->i] != '-' || inpt->argv[inpt->i][1] == '\0')
			break;
		if (ft_ssl_dgst_opt(ftssl_dgst, inpt->argv[inpt->i] + 1) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_parse_arg(t_ftssl_dgst *ftssl_dgst)
{
	t_ftssl_dgst_inpt *inpt;
	t_ftssl_dgst_ctx *ctx;
	t_ftssl_dgst_outp *outp;

	inpt = &ftssl_dgst->inpt;
	ctx = &ftssl_dgst->ctx;
	outp = &ftssl_dgst->outp;
	if (inpt->i == inpt->argc)
	{
		outp->outp_dist = ft_ssl_dgst_output_q;
		ft_ssl_dgst_parse_options_p(ftssl_dgst, 0);
	}
	while (inpt->i < inpt->argc)
	{
		ctx->cmd_arg_len = 0;
		ctx->cmd_arg = inpt->argv[inpt->i];
		outp->outp_dist(ftssl_dgst);
		inpt->i++;
	}
	return (EXIT_SUCCESS);
}
