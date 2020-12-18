/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:07:42 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/04 01:06:55 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_sha.h"

int			ft_md5_init(t_dgst_ctx *ctx)
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
	return (EXIT_SUCCESS);
}

static uint32_t     ft_md5_hash_f(int i, int b, int c, int d)
{
	if (i < 16)
		return (b & c) | ((~b) & d);
	else if (i < 32)
		return (d & b) | ((~d) & c);
	else if (i < 48)
		return b ^ c ^ d;
	return c ^ (b | (~d));
}

static uint32_t     ft_md5_hash_g(int i)
{
	if (i < 16)
		return (i);
	else if (i < 32)
		return (5 * i + 1) % 16;
	else if (i < 48)
		return (3 * i + 5) % 16;
	return (7 * i) % 16;
}

static uint32_t     ft_md5_hash_k(int i)
{
	const uint32_t k[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 
		0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340, 0x265e5a51,
		0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6, 0xc33707d6, 
		0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 0xfffa3942,
		0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 
		0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
		0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82,
		0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };

	return k[i];
}

static uint32_t     ft_md5_hash_s(int i)
{
	const uint32_t s[64] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17,
		22, 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20, 4, 11, 16,
		23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23, 6, 10, 15, 21,  6, 10, 15,
		21,  6, 10, 15, 21,  6, 10, 15, 21 };

	return s[i];
}

int     		ft_md5_transform(t_dgst_ctx *ctx)
{
	unsigned int	i;
	uint32_t f;
	uint32_t	state[FT_MD5_STATE];
	uint32_t	w[16];

	i = -1;
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	ft_memcpy(w, ctx->block, sizeof(w));
	while (++i < FT_MD5_MBS)
	{
		f = ft_md5_hash_f(i, state[1], state[2], state[3]) + state[0] + ft_md5_hash_k(i) + w[ft_md5_hash_g(i)];
		state[0] = state[3];
		state[3] = state[2];
		state[2] = state[1];
		state[1] = state[1] + ft_rotl_uint32(f, ft_md5_hash_s(i));
	}
	i = -1;
	while (++i < ctx->sts)
		ctx->state.x_32[i] += state[i];
	ctx->iblock = 0;
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}
static unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}
int		ft_md5_final(t_dgst_ctx *ctx)
{
		unsigned int	i;
		unsigned int 	pad;
		uint64_t 			ibits;

		i = ctx->iblock;
		pad = ft_get_size_aligned(ctx->iblock + ctx->x, FT_MD5_MBS);
		ibits = ctx->idata * 8;
		ctx->block[ctx->iblock++] = 0x80;
		while (++i < (pad - ctx->x) && ctx->iblock != FT_MD5_MBS)
			ctx->block[ctx->iblock++] = 0;
		if (ctx->iblock == FT_MD5_MBS)
			ft_md5_transform(ctx);
		ft_memset(&ctx->block[ctx->iblock], 0, (FT_MD5_MBS - ctx->x) - ctx->iblock);
		ctx->iblock += (FT_MD5_MBS - ctx->x) - ctx->iblock;
		ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
		ft_md5_transform(ctx);
		return (EXIT_SUCCESS);
}