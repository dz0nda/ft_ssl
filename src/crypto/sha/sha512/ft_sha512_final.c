/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:01:08 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

static unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

int			ft_sha512_pad(t_dgst_ctx *ctx)
{
	unsigned int	i;
	unsigned int pad;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + 16, FT_SHA512_MBS);
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - 16))
	{
		if (ctx->iblock == ctx->mbs) 
			ft_sha512_transform(ctx);
		ctx->block[ctx->iblock++] = 0;
	}
	return (EXIT_SUCCESS);
}

int			ft_sha512_add_length(t_dgst_ctx *ctx)
{
	int				i;
	__uint128_t 	ibits_x64;

	i = -1;
	ibits_x64 = ctx->idata * 8;
	ft_memrev(&ibits_x64, sizeof(ibits_x64));
	ft_memcpy(&ctx->block[ctx->iblock], &ibits_x64, sizeof(ibits_x64));
	ft_sha512_transform(ctx);
	while (++i < ctx->sts)
		ft_swap_uint64(&ctx->state.x_64[i]);
	return (EXIT_SUCCESS);
}

int			ft_sha512_final(t_dgst_ctx *ctx)
{
	// unsigned int	i;
	// unsigned int pad;
	// __uint128_t 	ibits_x64;

	ft_sha512_pad(ctx);
	ft_sha512_add_length(ctx);
	// i = ctx->iblock;
	// pad = ft_get_size_aligned(ctx->iblock + ctx->x, ctx->mbs);
	// ibits_x64 = ctx->idata * 8;
	// ctx->block[ctx->iblock++] = 0x80;
	// while (++i < (pad - ctx->x) && ctx->iblock != ctx->mbs)
	// 	ctx->block[ctx->iblock++] = 0;
	// // ft_memset(&ctx->block[ctx->iblock], 0, pad - ctx->iblock);
	// if (ctx->iblock == ctx->mbs)
	// 	ft_sha512_transform(ctx);
	// ft_memset(&ctx->block[ctx->iblock], 0, (ctx->mbs - ctx->x) - ctx->iblock);
	// ctx->iblock += (ctx->mbs - ctx->x) - ctx->iblock;
	// ft_memrev(&ibits_x64, sizeof(ibits_x64));
	// ft_memcpy(&ctx->block[ctx->iblock], &ibits_x64, sizeof(ibits_x64));
	// ft_sha512_transform(ctx);
	// i = -1;
	// while (++i < ctx->sts)
	// 	ft_swap_uint64(&ctx->state.x_64[i]);
	return (EXIT_SUCCESS);
}