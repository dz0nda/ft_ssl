/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:11:52 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:11:09 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

int			ft_sha1_init(t_dgst_ctx *ctx)
{
	ctx->hs = FT_SHA1_HS;
	ctx->mbs = FT_SHA1_MBS;
	ctx->endian = FT_DGST_ENDIAN_BIG;
	ctx->sts = FT_SHA1_STATE;
	ctx->x = FT_DGST_X32;
	ctx->state.x_32[0] = 0x67452301;
	ctx->state.x_32[1] = 0xefcdab89;
	ctx->state.x_32[2] = 0x98badcfe;
	ctx->state.x_32[3] = 0x10325476;
	ctx->state.x_32[4] = 0xc3d2e1f0;
	return (EXIT_SUCCESS);
}
