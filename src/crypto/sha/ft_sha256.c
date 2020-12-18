/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/04 01:29:55 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_sha.h"

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

int 		ft_sha256_wsigma0(uint32_t word)
{
	return (ft_rotr_uint32(word, 7) ^ ft_rotr_uint32(word, 18) ^ ft_shiftr_uint32(word, 3));
}

int 		ft_sha256_wsigma1(uint32_t word)
{
	return (ft_rotr_uint32(word, 17) ^ ft_rotr_uint32(word, 19) ^ ft_shiftr_uint32(word, 10));
}

int 		ft_sha256_sigma0(uint32_t state[8], uint32_t w, unsigned int i)
{
	const uint32_t k[64] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };
	uint32_t sigma;
	uint32_t ch;

	sigma = ft_rotr_uint32(state[4], 6) ^ ft_rotr_uint32(state[4], 11) ^ ft_rotr_uint32(state[4], 25);
	ch = (state[4] & state[5]) ^ ((~state[4]) & state[6]);

	return state[7] + sigma + ch + k[i] + w;
}

int 		ft_sha256_sigma1(uint32_t state[8])
{
	uint32_t sigma;
	uint32_t maj;

	sigma = ft_rotr_uint32(state[0], 2) ^ ft_rotr_uint32(state[0], 13) ^ ft_rotr_uint32(state[0], 22);
	maj = (state[0] & state[1]) ^ (state[0] & state[2]) ^ (state[1] & state[2]);

	return sigma + maj;
}

void	 		ft_sha256_swap_state(uint32_t	state[8],	uint32_t	sigma[2])
{
		state[7] = state[6];
		state[6] = state[5];
		state[5] = state[4];
		state[4] = state[3] + sigma[0];
		state[3] = state[2];
		state[2] = state[1];
		state[1] = state[0];
		state[0] = sigma[0] + sigma[1];
}

int			ft_sha256_transform(t_dgst_ctx *ctx)
{
	unsigned int			i;
	uint32_t	state[8];
	uint32_t	w[64];
	uint32_t	sigma[2];
	
	i = -1;
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	while (++i < 64)
	{
		if (i < 16)
			w[i] = ft_swap_uint32((uint32_t *)&ctx->block[i * 4]);
		else if (i < 64)
			w[i] = w[i - 16] + ft_sha256_wsigma0(w[i - 15]) + w[i - 7] + ft_sha256_wsigma1(w[i - 2]);
		sigma[0] = ft_sha256_sigma0(state, w[i], i);
		sigma[1] = ft_sha256_sigma1(state);
		ft_sha256_swap_state(state, sigma);
	}
	i = -1;
	while (++i < 8)
		ctx->state.x_32[i] += state[i];
	ctx->iblock = 0;
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}
static unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}
int			ft_sha256_final(t_dgst_ctx *ctx)
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
		ft_sha256_transform(ctx);
	ft_memset(&ctx->block[ctx->iblock], 0, (ctx->mbs - ctx->x) - ctx->iblock);
	ctx->iblock += (ctx->mbs - ctx->x) - ctx->iblock;
	ft_memrev(&ibits_x32, sizeof(ibits_x32));
	ft_memcpy(&ctx->block[ctx->iblock], &ibits_x32, sizeof(ibits_x32));
	ft_sha256_transform(ctx);
	i = -1;
	while (++i < ctx->sts)
		ft_swap_uint32(&ctx->state.x_32[i]);
	return (EXIT_SUCCESS);
}
