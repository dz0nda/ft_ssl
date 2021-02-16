/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/03 13:05:37 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dgst.h"

int			ft_sha224_init(t_dgst_ctx *ctx, unsigned int msg_len)
{
	ctx->hs = FT_SHA224_HS;
	ctx->mbs = FT_SHA224_MBS;
	ctx->endian = FT_DGST_ENDIAN_BIG;
	ctx->sts = FT_SHA224_STATE;
	ctx->x = FT_DGST_X32;
	ctx->state.x_32[0] = 0xc1059ed8;
	ctx->state.x_32[1] = 0x367cd507;
	ctx->state.x_32[2] = 0x3070dd17;
	ctx->state.x_32[3] = 0xf70e5939;
	ctx->state.x_32[4] = 0xffc00b31;
	ctx->state.x_32[5] = 0x68581511;
	ctx->state.x_32[6] = 0x64f98fa7;
	ctx->state.x_32[7] = 0xbefa4fa4;
	ctx->len.x_32 = msg_len * 8;
	ft_memrev(&ctx->len.x_32, sizeof(ctx->len.x_32));
	ctx->padding = ft_align_bits(ctx->len.x_32 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}

int			ft_sha224_pre_process(t_dgst_ctx *ctx, uint8_t *msg,
	unsigned int msg_len)
{
	return (ft_sha256_pre_process(ctx, msg, msg_len));
}

int			ft_sha224_transform(t_dgst_ctx *ctx)
{
	return (ft_sha256_transform(ctx));
}

char		*ft_sha224_final(t_dgst_ctx *ctx, char *cmd_dgst)
{
	return (ft_sha256_final(ctx, cmd_dgst));
}
