/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:11:52 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:11:35 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

static unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}
int			ft_sha1_final(t_dgst_ctx *ctx)
{
	unsigned int	i;
	unsigned int pad;
	uint64_t 	ibits_x32;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + ctx->x, ctx->mbs);
	ibits_x32 = ctx->idata * 8;
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - ctx->x) && ctx->iblock != ctx->mbs)
		ctx->block[ctx->iblock++] = 0;
	// ft_memset(&ctx->block[ctx->iblock], 0, pad - ctx->iblock);
	if (ctx->iblock == ctx->mbs)
		ft_sha1_transform(ctx);
	ft_memset(&ctx->block[ctx->iblock], 0, (ctx->mbs - ctx->x) - ctx->iblock);
	ctx->iblock += (ctx->mbs - ctx->x) - ctx->iblock;
	ft_memrev(&ibits_x32, sizeof(ibits_x32));
	ft_memcpy(&ctx->block[ctx->iblock], &ibits_x32, sizeof(ibits_x32));
	ft_sha1_transform(ctx);
	i = -1;
	while (++i < ctx->sts)
		ft_swap_uint32(&ctx->state.x_32[i]);
	return (EXIT_SUCCESS);
}
