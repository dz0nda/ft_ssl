/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512256.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/03 13:05:37 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dgst.h"

int			ft_sha512224_init(t_dgst_ctx *ctx, unsigned int msg_len)
{
	ctx->hs = FT_SHA512224_HS;
	ctx->mbs = FT_SHA512224_MBS;
	ctx->endian = FT_SHA512224_ENDIAN;
	ctx->sts = FT_SHA512224_STATE;
	ctx->x = FT_DGST_X64;
	ctx->state.x_64[0] = 0x8C3D37C819544DA2;
	ctx->state.x_64[1] = 0x73E1996689DCD4D6;
	ctx->state.x_64[2] = 0x1DFAB7AE32FF9C82;
	ctx->state.x_64[3] = 0x679DD514582F9FCF;
	ctx->state.x_64[4] = 0x0F6D2B697BD44DA8;
	ctx->state.x_64[5] = 0x77E36F7304C48942;
	ctx->state.x_64[6] = 0x3F9D85A86A1D36C8;
	ctx->state.x_64[7] = 0x1112E6AD91D692A1;
	ctx->len.x_64 = msg_len * 8;
	ft_memrev(&ctx->len.x_64, sizeof(ctx->len.x_64));
	ctx->padding = ft_align_bits(ctx->len.x_64 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}

int			ft_sha512256_init(t_dgst_ctx *ctx, unsigned int msg_len)
{
	ctx->hs = FT_SHA512256_HS;
	ctx->mbs = FT_SHA512256_MBS;
	ctx->endian = FT_SHA512256_ENDIAN;
	ctx->sts = FT_SHA512256_STATE;
	ctx->x = FT_DGST_X64;
	ctx->state.x_64[0] = 0x22312194FC2BF72C;
	ctx->state.x_64[1] = 0x9F555FA3C84C64C2;
	ctx->state.x_64[2] = 0x2393B86B6F53B151;
	ctx->state.x_64[3] = 0x963877195940EABD;
	ctx->state.x_64[4] = 0x96283EE2A88EFFE3;
	ctx->state.x_64[5] = 0xBE5E1E2553863992;
	ctx->state.x_64[6] = 0x2B0199FC2C85B8AA;
	ctx->state.x_64[7] = 0x0EB72DDC81C52CA2;
	ctx->len.x_64 = msg_len * 8;
	ft_memrev(&ctx->len.x_64, sizeof(ctx->len.x_64));
	ctx->padding = ft_align_bits(ctx->len.x_64 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}

int			ft_sha512256_pre_process(t_dgst_ctx *ctx, uint8_t *msg,
	unsigned int msg_len)
{
	return (ft_sha512_pre_process(ctx, msg, msg_len));
}

int			ft_sha512256transform(t_dgst_ctx *ctx)
{
	return (ft_sha512_transform(ctx));
}

char		*ft_sha512256_final(t_dgst_ctx *ctx, char *cmd_dgst)
{
	return (ft_sha512_final(ctx, cmd_dgst));
}
