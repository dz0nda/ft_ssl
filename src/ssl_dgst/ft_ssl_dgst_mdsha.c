/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_mdsha.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 04:42:44 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 21:36:28 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_mdsha_file(t_dgst *dgst, char *filename)
{
	int i, fd;
	char c[2];
	t_dgst_dist *dist;
	t_dgst_ctx 	*ctx;

	i = -1;
	ft_bzero(c, sizeof(c));
	dist = &dgst->dist;
	ctx = &dgst->ctx;
	if (filename == NULL)
		fd = 0;
	else if (access(filename, F_OK) == -1 || (fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	// ctx->state = (uint32_t *)ft_memalloc(sizeof(uint32_t) * ctx->len_state);
	// ctx->block = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (ctx->len_mbs * 2));
	ft_memset(ctx->state, 0, sizeof(ctx->state));
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	dist->init(ctx);
	while ((ctx->iblock = read(fd, ctx->block, ctx->len_mbs)) == ctx->len_mbs)
	{
		ctx->len_input += ctx->iblock;
		dist->transform(ctx);
		ft_memset(ctx->block, 0, sizeof(ctx->block));
	}
	ctx->len_input += ctx->iblock;
	dist->final(ctx);
    ft_dgst_result(ctx);
	ft_ssl_dgst_output(dgst);
	// dgst->output(dgst);
    return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_mdsha_string(t_dgst *dgst, char *data, size_t len)
{
	int i;
	t_dgst_dist *dist;
	t_dgst_ctx 	*ctx;

	i = -1;
	dist = &dgst->dist;
	ctx = &dgst->ctx;
	// ctx->state = (uint32_t *)ft_memalloc(sizeof(uint32_t) * ctx->len_state);
	// ctx->block = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (ctx->len_mbs * 2));
	ft_memset(ctx->state, 0, sizeof(ctx->state));
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	ctx->len_input = len;
	dist->init(ctx);
	while (ctx->idata < len)
	{
		ctx->block[ctx->iblock++] = data[ctx->idata++];
		if (ctx->iblock == ctx->len_mbs)
		{
			dist->transform(ctx);
			ctx->iblock = 0;
		}
	}
	dist->final(ctx);
    ft_dgst_result(ctx);
	// dgst->output(dgst);
	return (EXIT_SUCCESS);
}
