/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgst_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:34:09 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/29 22:40:54 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dgst.h"

unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

int			ft_dgst_pad(t_dgst *dgst)
{
	unsigned int	i;
	unsigned int pad;

	i = dgst->ctx.iblock;
	pad = ft_get_size_aligned(dgst->ctx.iblock + dgst->ctx.x, dgst->ctx.mbs);
	dgst->ctx.block[dgst->ctx.iblock++] = 0x80;
	while (++i < (pad - dgst->ctx.x) && dgst->ctx.iblock != dgst->ctx.mbs)
		dgst->ctx.block[dgst->ctx.iblock++] = 0;
	if (dgst->ctx.iblock == dgst->ctx.mbs)
		dgst->dist.transform(&dgst->ctx);
	ft_memset(&dgst->ctx.block[dgst->ctx.iblock], 0, (dgst->ctx.mbs - dgst->ctx.x) - dgst->ctx.iblock);
	dgst->ctx.iblock += (dgst->ctx.mbs - dgst->ctx.x) - dgst->ctx.iblock;
	return (EXIT_SUCCESS);
}

int			ft_dgst_finalize(t_dgst *dgst)
{
	uint64_t 	ibits_x32;
	__uint128_t	ibits_x64;
	unsigned int		i;
	t_dgst_ctx *ctx = &dgst->ctx;

	i = -1;
	ibits_x32 = ctx->idata * 8;
	ibits_x64 = ctx->idata * 8;
	if (ctx->endian == FT_DGST_ENDIAN_BIG)
		(ctx->x == FT_DGST_X64) ? ft_memrev(&ibits_x64, sizeof(ibits_x64)) :
		ft_memrev(&ibits_x32, sizeof(ibits_x32));
	(ctx->x == FT_DGST_X64) ? ft_memcpy(&ctx->block[ctx->iblock], &ibits_x64, sizeof(ibits_x64)) :
	ft_memcpy(&ctx->block[ctx->iblock], &ibits_x32, sizeof(ibits_x32));
	dgst->dist.transform(&dgst->ctx);
	while (ctx->endian == FT_DGST_ENDIAN_BIG && ++i < ctx->sts)
		(ctx->x == FT_DGST_X64) ? ft_swap_uint64(&ctx->state.x_64[i]) : ft_swap_uint32(&ctx->state.x_32[i]); //ft_swap_uint32(ctx->state.x_32[i]);
	return (EXIT_SUCCESS);
}

char        *ft_dgst_result(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int		i;
	unsigned int		j;
	char	s[6];
	uint8_t	*p;
	int nb = 0;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < ctx->sts)
	{
		p = (ctx->x == FT_DGST_X64) ? (uint8_t *)&ctx->state.x_64[i] : (uint8_t *)&ctx->state.x_32[i];
		j = -1;
		while (++j < (ctx->x / 2))
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(cmd_dgst, s);
			nb++;
			if (nb == ctx->hs)
				break;
		}
		if (nb == ctx->hs)
			break;
	}
	return (cmd_dgst);
}