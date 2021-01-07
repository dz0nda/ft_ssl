/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:07:42 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/22 19:53:08 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

int			ft_md5_init(t_dgst_ctx *ctx, unsigned int msg_len)
{
	ctx->hs = FT_MD5_HS;
	ctx->mbs = FT_MD5_MBS;
	ctx->endian = FT_DGST_ENDIAN_LITTLE;
	ctx->sts = FT_MD5_STATE;
	ctx->x = FT_DGST_X32;
	ctx->state.x_32[0] = 0x67452301;
	ctx->state.x_32[1] = 0xefcdab89;
	ctx->state.x_32[2] = 0x98badcfe;
	ctx->state.x_32[3] = 0x10325476;
	ctx->len.x_32 = msg_len * 8;
	ctx->padding = ft_get_size_aligned(ctx->len.x_32 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}
