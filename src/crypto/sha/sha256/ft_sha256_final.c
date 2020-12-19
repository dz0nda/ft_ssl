/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 21:39:09 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

static unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

int			ft_sha256_pad(t_dgst_ctx *ctx)
{
	unsigned int	i;
	unsigned int pad;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + 8, FT_SHA256_MBS);
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - 8))
	{
		if (ctx->iblock == ctx->mbs) 
			ft_sha256_transform(ctx);
		ctx->block[ctx->iblock++] = 0;
	}

	// ft_memset(&ctx->block[ctx->iblock], 0, (ctx->mbs - ctx->x) - ctx->iblock);
	// ctx->iblock += (ctx->mbs - ctx->x) - ctx->iblock;
	return (EXIT_SUCCESS);
}

int			ft_sha256_add_length(t_dgst_ctx *ctx)
{
	int				i;
	uint64_t 	ibits_x32;

	i = -1;
	ibits_x32 = ctx->idata * 8;
	ft_memrev(&ibits_x32, sizeof(ibits_x32));
	ft_memcpy(&ctx->block[ctx->iblock], &ibits_x32, sizeof(ibits_x32));
	ft_sha256_transform(ctx);
	while (++i < ctx->sts)
		ft_swap_uint32(&ctx->state.x_32[i]);
	return (EXIT_SUCCESS);
}

int			ft_sha256_final(t_dgst_ctx *ctx)
{
	unsigned int	i;
	unsigned int pad;
	uint64_t 	ibits_x32;

	// i = ctx->iblock;
	// pad = ft_get_size_aligned(ctx->iblock + ctx->x, ctx->mbs);
	ibits_x32 = ctx->idata * 8;
	// ctx->block[ctx->iblock++] = 0x80;
	// // printf("pad: %d\n", pad);
	// // printf("iblock: %d\n",  ctx->iblock);
	// while (++i < (pad - ctx->x) && ctx->iblock != ctx->mbs)
	// 	ctx->block[ctx->iblock++] = 0;
	// // ft_memset(&ctx->block[ctx->iblock], 0, pad - ctx->iblock);
	// if (ctx->iblock == ctx->mbs) 
	// 	ft_sha256_transform(ctx);
	// ft_memset(&ctx->block[ctx->iblock], 0, (ctx->mbs - ctx->x) - ctx->iblock);
	// ctx->iblock += (ctx->mbs - ctx->x) - ctx->iblock;
	ft_sha256_pad(ctx);
	ft_sha256_add_length(ctx);
	// ft_memrev(&ibits_x32, sizeof(ibits_x32));
	// ft_memcpy(&ctx->block[ctx->iblock], &ibits_x32, sizeof(ibits_x32));
	// ft_sha256_transform(ctx);
	// i = -1;
	// while (++i < ctx->sts)
	// 	ft_swap_uint32(&ctx->state.x_32[i]);
	return (EXIT_SUCCESS);
}
