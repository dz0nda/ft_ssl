/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:11:52 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/04 01:24:12 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_sha.h"

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

static uint32_t     ft_sha1_hash_f(int j, int b, int c, int d)
{
	if (j < 20)
		return (b & c) | ((~b) & d);
	else if (j < 40)
		return b ^ c ^ d;
	else if (j < 60)
		return (b & c) | (b & d) | (c & d);
	return b ^ c ^ d;
}

static uint32_t     ft_sha1_hash_k(int j)
{
	if (j < 20)
		return 0x5A827999;
	else if (j < 40)
		return 0x6ED9EBA1;
	else if (j < 60)
		return 0x8F1BBCDC;
	return 0xCA62C1D6;
}

static void     ft_sha1_transform_word(uint32_t *w, const void *data)
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
	ft_sha1_transform_word(w, ctx->block);
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
	ctx->iblock = 0;
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}
static unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}
int			ft_sha1_final(t_dgst_ctx *ctx)
{
	unsigned int	i;
	unsigned int pad;
	uint64_t 	ibits_x32;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + ctx->x, ctx->mbs);
	ibits_x32 = ctx->idata * 8;
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - ctx->x) && ctx->iblock != ctx->mbs)
		ctx->block[ctx->iblock++] = 0;
	if (ctx->iblock == ctx->mbs)
		ft_sha1_transform(ctx);
	ft_memset(&ctx->block[ctx->iblock], 0, (ctx->mbs - ctx->x) - ctx->iblock);
	ctx->iblock += (ctx->mbs - ctx->x) - ctx->iblock;
	ft_memrev(&ibits_x32, sizeof(ibits_x32));
	ft_memcpy(&ctx->block[ctx->iblock], &ibits_x32, sizeof(ibits_x32));
	ft_sha1_transform(ctx);
	i = -1;
	while (++i < ctx->sts)
		ft_swap_uint32(&ctx->state.x_32[i]);
	return (EXIT_SUCCESS);
}
