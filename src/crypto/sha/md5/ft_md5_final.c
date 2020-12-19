/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:07:42 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:26:53 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

static unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

int		ft_md5_pad(t_dgst_ctx *ctx)
{
	unsigned int	i;
	unsigned int 	pad;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + ctx->x, FT_MD5_MBS);
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - ctx->x) && ctx->iblock != FT_MD5_MBS)
		ctx->block[ctx->iblock++] = 0;
	// if (ctx->iblock != FT_MD5_MBS)
	// 	ft_memset(&ctx->block[ctx->iblock], 0, pad - i);
	if (ctx->iblock == FT_MD5_MBS)
		ft_md5_transform(ctx);
	ft_memset(&ctx->block[ctx->iblock], 0, (FT_MD5_MBS - ctx->x) - ctx->iblock);
	ctx->iblock += (FT_MD5_MBS - ctx->x) - ctx->iblock;
	return (EXIT_SUCCESS);

}

int		ft_md5_add_length(t_dgst_ctx *ctx)
{
	uint64_t 			ibits;

	ibits = ctx->idata * 8;
	ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
	ft_md5_transform(ctx);
	return (EXIT_SUCCESS);
}

int		ft_md5_final(t_dgst_ctx *ctx)
{
	ft_md5_pad(ctx);
	ft_md5_add_length(ctx);
		// unsigned int	i;
		// unsigned int 	pad;
		// uint64_t 			ibits;

		// i = ctx->iblock;
		// pad = ft_get_size_aligned(ctx->iblock + ctx->x, FT_MD5_MBS);
		// ibits = ctx->idata * 8;
		// ctx->block[ctx->iblock++] = 0x80;
		// while (++i < (pad - ctx->x) && ctx->iblock != FT_MD5_MBS)
		// 	ctx->block[ctx->iblock++] = 0;
		// // if (ctx->iblock != FT_MD5_MBS)
		// // 	ft_memset(&ctx->block[ctx->iblock], 0, pad - i);
		// if (ctx->iblock == FT_MD5_MBS)
		// 	ft_md5_transform(ctx);
		// ft_memset(&ctx->block[ctx->iblock], 0, (FT_MD5_MBS - ctx->x) - ctx->iblock);
		// ctx->iblock += (FT_MD5_MBS - ctx->x) - ctx->iblock;
		// ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
		// ft_md5_transform(ctx);
		return (EXIT_SUCCESS);
}