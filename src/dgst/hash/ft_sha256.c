/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/29 13:00:11 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_dgst.h"

int			ft_sha256_init(t_dgst_ctx *ctx)
{
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


int			ft_sha256_maj(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

int			ft_sha256_ch(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ ((~x) & z));
}

// static void		ft_sha256_transform_s(uint32_t state[8], uint32_t s[2], uint32_t w, int i)
// {
//     // const uint32_t k[64] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
// 		// 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
// 		// 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
// 		// 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
// 		// 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
// 		// 0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
// 		// 0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
// 		// 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };
// 	uint32_t ch;
// 	uint32_t maj;

// 	// s[0] = FT_DGST_ROTR_X32(state[4], 6) ^ FT_DGST_ROTR_X32(state[4], 11) ^ FT_DGST_ROTR_X32(state[4], 25);
// 	// ch = ft_sha256_ch(state[4], state[5], state[6]);
// 	// ch = (state[4] & state[5]) ^ ((~state[4]) & state[6]);
// 	s[0] = state[7] + (FT_DGST_ROTR_X32(state[4], 6) ^ FT_DGST_ROTR_X32(state[4], 11) ^ FT_DGST_ROTR_X32(state[4], 25)) + ft_sha256_ch(state[4], state[5], state[6]) + k[i] + w;
// 	// s[1] = FT_DGST_ROTR_X32(state[0], 2) ^ FT_DGST_ROTR_X32(state[0], 13) ^ FT_DGST_ROTR_X32(state[0], 22);
// 	// maj = ft_sha256_maj(state[0], state[1], state[2]);
// 	// maj = (state[0] & state[1]) ^ (state[0] & state[2]) ^ (state[1] & state[2]);
// 	s[1] = (FT_DGST_ROTR_X32(state[0], 2) ^ FT_DGST_ROTR_X32(state[0], 13) ^ FT_DGST_ROTR_X32(state[0], 22)) + ft_sha256_maj(state[0], state[1], state[2]);
// }

   const uint32_t k[64] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };


static void		ft_sha256_transform_word(uint32_t *w, const void *data)
{
	int i;
	uint32_t	*m;
	uint32_t 	s0;
	uint32_t 	s1;

	i = -1;
	m = (uint32_t *)data;
	while (++i < 16)
		w[i] = ft_swap_uint(m[i], sizeof(m[i]));
	while (i < 64)
	{
		s0 = FT_DGST_ROTR_X32(w[i - 15], 7) ^ FT_DGST_ROTR_X32(w[i - 15], 18) ^ FT_DGST_SHFR(w[i - 15], 3);
		s1 = FT_DGST_ROTR_X32(w[i - 2], 17) ^ FT_DGST_ROTR_X32(w[i - 2], 19) ^ FT_DGST_SHFR(w[i - 2], 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
	if (FT_DGST_DEBUG)
		ft_dgst_update_words_debug(w, 64);
}

int			ft_sha256_transform(t_dgst_ctx *ctx)
{
	unsigned int			i;
	uint32_t	state[8];
	uint32_t	w[64];
	uint32_t  *m;
	uint32_t	s[2];
	uint32_t 	s0;
	uint32_t 	s1;
	
	i = -1;
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	// ft_sha256_transform_word(w, ctx->block);
	m = (uint32_t *)ctx->block;
	while (++i < 64)
	{
		// ft_sha256_transform_s(state, s, w[i], i);
		if (i < 16)
			w[i] = ft_swap_uint(m[i], sizeof(m[i]));
		else if (i < 64)
		{
			s0 = FT_DGST_ROTR_X32(w[i - 15], 7) ^ FT_DGST_ROTR_X32(w[i - 15], 18) ^ FT_DGST_SHFR(w[i - 15], 3);
			s1 = FT_DGST_ROTR_X32(w[i - 2], 17) ^ FT_DGST_ROTR_X32(w[i - 2], 19) ^ FT_DGST_SHFR(w[i - 2], 10);
			w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		}
		s[0] = state[7] + (FT_DGST_ROTR_X32(state[4], 6) ^ FT_DGST_ROTR_X32(state[4], 11) ^ FT_DGST_ROTR_X32(state[4], 25)) + ft_sha256_ch(state[4], state[5], state[6]) + k[i] + w[i];
		s[1] = (FT_DGST_ROTR_X32(state[0], 2) ^ FT_DGST_ROTR_X32(state[0], 13) ^ FT_DGST_ROTR_X32(state[0], 22)) + ft_sha256_maj(state[0], state[1], state[2]);
		state[7] = state[6];
		state[6] = state[5];
		state[5] = state[4];
		state[4] = state[3] + s[0];
		state[3] = state[2];
		state[2] = state[1];
		state[1] = state[0];
		state[0] = s[0] + s[1];
	}
	i = -1;
	while (++i < 8)
		ctx->state.x_32[i] += state[i];
	ctx->iblock = 0;
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}
