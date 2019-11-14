/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_pad.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 12:01:09 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 08:12:17 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

size_t		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

int			ft_dgst_pad(t_dgst_ctx *ctx)
{
	int i;
	int pad;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + 8, ctx->len_mbs);
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - 8))
	{
		if (ctx->iblock == ctx->len_mbs)
			break ;
		ctx->block[ctx->iblock++] = 0;
	}
	return (EXIT_SUCCESS);
}
