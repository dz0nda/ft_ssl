/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 21:39:09 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

int			ft_sha256_init(t_dgst_ctx *ctx)
{
	ctx->hs = FT_SHA256_HS;
	ctx->mbs = FT_SHA256_MBS;
	ctx->endian = FT_DGST_ENDIAN_BIG;
	ctx->sts = FT_SHA256_STATE;
	ctx->x = FT_DGST_X32;
	ctx->state.x_32[0] = 0x6a09e667;
	ctx->state.x_32[1] = 0xbb67ae85;
	ctx->state.x_32[2] = 0x3c6ef372;
	ctx->state.x_32[3] = 0xa54ff53a;
	ctx->state.x_32[4] = 0x510e527f;
	ctx->state.x_32[5] = 0x9b05688c;
	ctx->state.x_32[6] = 0x1f83d9ab;
	ctx->state.x_32[7] = 0x5be0cd19;
	return (EXIT_SUCCESS);
}

int			ft_sha224_init(t_dgst_ctx *ctx)
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
	return (EXIT_SUCCESS);
}
