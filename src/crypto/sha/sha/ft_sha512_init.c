/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/22 19:58:31 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

int			ft_sha512_init(t_dgst_ctx *ctx, unsigned int msg_len)
{
	ctx->hs = FT_SHA512_HS;
	ctx->mbs = FT_SHA512_MBS;
	ctx->endian = FT_DGST_ENDIAN_BIG;
	ctx->sts = FT_SHA512_STATE;
	ctx->x = FT_DGST_X64;
	ctx->state.x_64[0] = 0x6a09e667f3bcc908;
	ctx->state.x_64[1] = 0xbb67ae8584caa73b;
	ctx->state.x_64[2] = 0x3c6ef372fe94f82b;
	ctx->state.x_64[3] = 0xa54ff53a5f1d36f1;
	ctx->state.x_64[4] = 0x510e527fade682d1;
	ctx->state.x_64[5] = 0x9b05688c2b3e6c1f;
	ctx->state.x_64[6] = 0x1f83d9abfb41bd6b;
	ctx->state.x_64[7] = 0x5be0cd19137e2179;
	ctx->len.x_64 = msg_len * 8;
	ft_memrev(&ctx->len.x_64, sizeof(ctx->len.x_64));
	ctx->padding = ft_get_size_aligned(ctx->len.x_64 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}

int			ft_sha384_init(t_dgst_ctx *ctx, unsigned int msg_len)
{
  ctx->hs = FT_SHA384_HS;
	ctx->mbs = FT_SHA384_MBS;
	ctx->endian = FT_DGST_ENDIAN_BIG;
	ctx->sts = FT_SHA384_STATE;
  ctx->x = FT_DGST_X64;
  ctx->state.x_64[0] = 0xcbbb9d5dc1059ed8;
  ctx->state.x_64[1] = 0x629a292a367cd507;
  ctx->state.x_64[2] = 0x9159015a3070dd17;
  ctx->state.x_64[3] = 0x152fecd8f70e5939;
  ctx->state.x_64[4] = 0x67332667ffc00b31;
  ctx->state.x_64[5] = 0x8eb44a8768581511;
  ctx->state.x_64[6] = 0xdb0c2e0d64f98fa7;
  ctx->state.x_64[7] = 0x47b5481dbefa4fa4;
	ctx->len.x_64 = msg_len * 8;
	ft_memrev(&ctx->len.x_64, sizeof(ctx->len.x_64));
	ctx->padding = ft_get_size_aligned(ctx->len.x_64 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}

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
	ctx->padding = ft_get_size_aligned(ctx->len.x_64 + ctx->x, ctx->mbs) - ctx->x;
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
	ctx->padding = ft_get_size_aligned(ctx->len.x_64 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}
