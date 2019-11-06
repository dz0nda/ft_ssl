/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_md5.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 23:07:42 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 04:11:23 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

int			ft_md5_init(t_dgst_ctx *ctx)
{
	ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
	return (EXIT_SUCCESS);
}

static void     ft_md5_transform_fg(uint32_t fg[2], int i, int b, int c, int d)
{
	if (i < 16)
	{
		fg[0] = (b & c) | ((~b) & d);
		fg[1] = i;
	}
	else if (i < 32)
	{
		fg[0] = (d & b) | ((~d) & c);
		fg[1] = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		fg[0] = b ^ c ^ d;
		fg[1] = (3 * i + 5) % 16;	
	}
	else
	{
		fg[0] = c ^ (b | (~d));
		fg[1] = (7 * i) % 16;
	}
}

static void     ft_md5_transform_ks(uint32_t ks[2], int i)
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
	const uint32_t s[64] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17,
		22, 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20, 4, 11, 16,
		23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23, 6, 10, 15, 21,  6, 10, 15,
		21,  6, 10, 15, 21,  6, 10, 15, 21 };

	ks[0] = k[i];
	ks[1] = s[i];
}

int     		ft_md5_transform(t_dgst_ctx *ctx)
{
	int	i;
	uint32_t 	ks[2];
	uint32_t 	fg[2];
	uint32_t	state[4];
    uint32_t	w[16];

	i = -1;
	ft_memset(ks, 0, sizeof(ks));
	ft_memset(fg, 0, sizeof(fg));
    ft_memcpy(state, ctx->state, sizeof(state));
    ft_memcpy(w, ctx->block, sizeof(w));    // w = (uint32_t *)data;
	while (++i < 64)
	{
		ft_md5_transform_ks(ks, i);
		ft_md5_transform_fg(fg, i, state[1], state[2], state[3]);
		fg[0] = fg[0] + state[0] + ks[0] + w[fg[1]];
		state[0] = state[3];
		state[3] = state[2];
		state[2] = state[1];
		state[1] = state[1] + ft_rotate_left(fg[0], ks[1]);
	}
    i = -1;
    while (++i < ctx->len_state)
        ctx->state[i] += state[i];
	return (EXIT_SUCCESS);
}

int			ft_md5_final(t_dgst_ctx *ctx)
{
	int i;
	int pad;
	uint64_t ibits;
	
	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + 8, 64);
	ibits = ctx->idata * 8;
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - 8))
	{
		if (ctx->iblock == ctx->len_mbs)
		{
			ft_md5_transform(ctx);
			ctx->iblock = 0;
			ft_memset(ctx->block,0, sizeof(ctx->iblock));
		}
		ctx->block[ctx->iblock++] = 0;
	}
	ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
	ft_md5_transform(ctx);
	// printf("\n== Final hexdump == \n");
	// hexdump(ctx->block, pad);
	return (EXIT_SUCCESS);
}

