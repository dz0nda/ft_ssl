/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_parse.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/10 15:44:55 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 04:45:14 by dzonda      ###    #+. /#+    ###.fr     */
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
	struct stat st;

	inpt = &ftssl_dgst->inpt;
	ctx = &ftssl_dgst->ctx;
	outp = &ftssl_dgst->outp;
	ft_memset(&st, 0, sizeof(st));
	// if (inpt->i == inpt->argc)
	// {
	// 	// outp->outp_dist = ft_ssl_dgst_output_q;
	// 	ft_ssl_dgst_exec(ftssl_dgst);
	// }
	while (inpt->i < inpt->argc)
	{
		ctx->cmd_arg_len = 0;
		ctx->cmd_arg = inpt->argv[inpt->i];
		lstat(ctx->cmd_arg , &st);
		if(S_ISREG(st.st_mode))
			ft_ssl_dgst_exec(ftssl_dgst);
		else
			ft_ssl_dgst_error_file(ctx->cmd_name, ctx->cmd_arg);
		ft_memset(&st, 0, sizeof(st));
		inpt->i++;
	}
	return (EXIT_SUCCESS);
}
