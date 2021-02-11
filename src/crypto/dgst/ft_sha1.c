/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:11:52 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/11 18:21:47 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dgst.h"

int			ft_sha1_init(t_dgst_ctx *ctx, unsigned int msg_len)
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
	ctx->len.x_32 = msg_len * 8;
	ft_memrev(&ctx->len.x_32, sizeof(ctx->len.x_32));
	ctx->padding = ft_align_bits(ctx->len.x_32 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}

static void     ft_sha1_process_words(uint32_t *w, const void *data)
{
    int i;
    uint32_t    rotator;
    uint32_t	*m;

    i = -1;
    rotator = 0;
    m = (uint32_t *)data;
    while (++i < 16)
        w[i] = ft_swap_uint32(&m[i]);
    while (i < 80)
    {
        rotator = (w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16]);
        w[i] = ft_rotl_uint32(rotator, 1);
        i++;
    }
}

int				ft_sha1_transform(t_dgst_ctx *ctx)
{
	unsigned int      i;
	uint32_t state[FT_SHA1_STATE];
	uint32_t w[80];
	uint32_t tmp;

	i = -1;
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	ft_sha1_process_words(w, ctx->block);
	while (++i < 80)
	{
		tmp = ft_rotl_uint32(state[0], 5) + ft_sha1_hash_f(i, state[1], state[2], state[3]) + state[4] + ft_sha1_hash_k(i) + w[i];
		state[4] = state[3];
		state[3] = state[2];
		state[2] = ft_rotl_uint32(state[1], 30);
		state[1] = state[0];
		state[0] = tmp;
	}
	i = -1;
	while (++i < FT_SHA1_STATE)
			ctx->state.x_32[i] += state[i];
	return (EXIT_SUCCESS);
}
