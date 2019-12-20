/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:07:28 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 17:33:42 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

int			ft_dgst_pad(t_dgst_ctx *ctx)
{
	unsigned int i;
	unsigned int pad;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + ctx->x, ctx->mbs);
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - ctx->x))
	{
		if (ctx->iblock == ctx->mbs)
			break ;
		ctx->block[ctx->iblock++] = 0;
	}
	return (EXIT_SUCCESS);
}

int			ft_dgst_finalize(t_dgst_ctx *ctx)
{
	uint64_t 	ibits_x32;
	__uint128_t	ibits_x64;

	while (ctx->iblock < ctx->mbs - ctx->x)
		ctx->block[ctx->iblock++] = 0;
	if (ctx->x == FT_DGST_X64)
	{
		ibits_x64 = ctx->idata * 8;
		if (ctx->endian == FT_DGST_ENDIAN_BIG)
			ft_memrev(&ibits_x64, sizeof(ibits_x64));
		ft_memcpy(&ctx->block[ctx->iblock], &ibits_x64, sizeof(ibits_x64));
		// ft_sha512_transform(ctx);
	}
	else
	{
		ibits_x32 = ctx->idata * 8;
		if (ctx->endian == FT_DGST_ENDIAN_BIG)
			ft_memrev(&ibits_x32, sizeof(ibits_x32));
		ft_memcpy(&ctx->block[ctx->iblock], &ibits_x32, sizeof(ibits_x32));
		// ft_sha256_transform(ctx);
	}
	return (EXIT_SUCCESS);
}

char        *ft_dgst_result(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int		i;
	unsigned int		j;
	char	s[6];
	uint8_t	*p;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < ctx->sts)
	{
		j = -1;
        if (ctx->x == FT_DGST_X64 && ctx->endian == FT_DGST_ENDIAN_BIG)
		    ctx->state.x_64[i] = ft_swap_uint(ctx->state.x_64[i], sizeof(ctx->state.x_64[i])); 
		else if (ctx->x == FT_DGST_X32 && ctx->endian == FT_DGST_ENDIAN_BIG)
			ctx->state.x_32[i] = ft_swap_uint(ctx->state.x_32[i], sizeof(ctx->state.x_32[i]));
		p = (ctx->x == FT_DGST_X64) ? (uint8_t *)&ctx->state.x_64[i] : (uint8_t *)&ctx->state.x_32[i];
		while (++j < (ctx->x / 2))
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(cmd_dgst, s);
		}
	}
	return (cmd_dgst);
}
