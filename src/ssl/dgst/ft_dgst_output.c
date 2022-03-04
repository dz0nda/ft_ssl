/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/04 10:12:09 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dgst.h"

int		ft_ssl_dgst_output_string(t_ftssl_dgst *ctx, char *arg, char *md)
{
	int i;

	i = -1;
	if (ctx->opt.reverse == 1)
	{
		ft_putstr(md);
		if (arg != NULL)
			ft_putchar(' ');
		ft_putchar('\"');
		ft_putstr(arg);
		ft_putendl("\"");
	}
	else
	{
		ft_putstr(ctx->distrib.name_upper);
		ft_putstr(" (\"");
		ft_putstr(arg);
		ft_putstr("\") = ");
		ft_putendl(md);
	}
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_output_file(t_ftssl_dgst *ctx, char *arg, char *md)
{
	int i;

	i = -1;
	if (ctx->opt.reverse == 1)
	{
		ft_putstr(md);
		ft_putchar(' ');
		ft_putendl(arg);
	}
	else
	{
		ft_putstr(ctx->distrib.name_upper);
		ft_putstr(" (");
		ft_putstr(arg);
		ft_putstr(") = ");
		ft_putendl(md);
	}
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_output_default(t_ftssl_dgst *ctx, char *arg, char *md)
{
	(void)ctx;
	(void)arg;
	ft_putendl(md);
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_output(int out_key, t_ftssl_dgst *ctx, char *arg)
{
	static t_ftssl_dgst_out_d	outp[FTSSL_DGST_OUTP] = {
		{ FTSSL_DGST_OUTP_DEFAULT, ft_ssl_dgst_output_default },
		{ FTSSL_DGST_OUTP_QUIET, ft_ssl_dgst_output_default },
		{ FTSSL_DGST_OUTP_STRING, ft_ssl_dgst_output_string },
		{ FTSSL_DGST_OUTP_FILE, ft_ssl_dgst_output_file }
	};
	char						*s;
	int							length;

	s = NULL;
	length = 0;
	if (out_key == FTSSL_DGST_OUTP_STRING && (s = ft_strdup(arg)))
		length = ft_strlen(arg);
	else if (out_key != FTSSL_DGST_OUTP_STRING)
		length = ft_get_input(arg, &s);
	ft_bzero(ctx->md, sizeof(ctx->md));
	ft_udgst(ctx->distrib.key, (uint8_t *)s, length, ctx->md);
	(ctx->opt.output_print == 1) ? ft_putstr(s) : 0;
	(ctx->opt.output == FTSSL_DGST_OUTP_QUIET) ?
		outp[FTSSL_DGST_OUTP_QUIET].outp_dist(ctx, arg, ctx->md) :
		outp[out_key].outp_dist(ctx, arg, ctx->md);
	ft_strdel(&s);
	return (EXIT_SUCCESS);
}
