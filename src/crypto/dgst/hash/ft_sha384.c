/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha384.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/19 23:01:32 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

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

int				ft_sha384_pre_process(t_dgst_ctx *ctx, uint8_t *msg, unsigned int msg_len)
{
  return (ft_sha512_pre_process(ctx, msg, msg_len));
}

int				ft_sha384_transform(t_dgst_ctx *ctx)
{
	return (ft_sha512_transform(ctx));
}

char		*ft_sha384_final(t_dgst_ctx *ctx, char *cmd_dgst)
{
	return (ft_sha512_final(ctx, cmd_dgst));
}