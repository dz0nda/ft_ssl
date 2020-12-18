/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/04 01:27:01 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_sha.h"

int			ft_sha512_init(t_dgst_ctx *ctx)
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
	return (EXIT_SUCCESS);
}

int			ft_sha512224_init(t_dgst_ctx *ctx)
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
	return (EXIT_SUCCESS);
}

int			ft_sha512256_init(t_dgst_ctx *ctx)
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
	return (EXIT_SUCCESS);
}

uint64_t 		ft_sha512_wsigma0(uint64_t word)
{
	return ft_rotr_uint64(word, 1) ^ ft_rotr_uint64(word, 8) ^ ft_shiftr_uint64(word, 7);
}

uint64_t 		ft_sha512_wsigma1(uint64_t word)
{
	return ft_rotr_uint64(word, 19) ^ ft_rotr_uint64(word, 61) ^ ft_shiftr_uint64(word, 6);
}

uint64_t 		ft_sha512_sigma0(uint64_t state[8], uint64_t w, int i)
{
	const uint64_t k[80] = { 0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538,
		0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe,
		0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
		0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
		0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab,
		0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
		0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed,
		0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
		0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
		0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
		0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373,
		0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
		0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c,
		0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6,
		0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
		0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817 };
	uint64_t 	sigma;
	uint64_t	ch;

	sigma = ft_rotr_uint64(state[4], 14) ^ ft_rotr_uint64(state[4], 18) ^ ft_rotr_uint64(state[4], 41);
	ch = (state[4] & state[5]) ^ ((~state[4]) & state[6]);

	return state[7] + sigma + ch + k[i] + w;
}

uint64_t 		ft_sha512_sigma1(uint64_t state[8])
{
	uint64_t 	sigma;
	uint64_t	maj;

	sigma = ft_rotr_uint64(state[0], 28) ^ ft_rotr_uint64(state[0], 34) ^ ft_rotr_uint64(state[0], 39);
	maj = (state[0] & state[1]) ^ (state[0] & state[2]) ^ (state[1] & state[2]);
	return sigma + maj;
}

void	 		ft_sha512_swap_state(uint64_t	state[8],	uint64_t	sigma[2])
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


int				ft_sha512_transform(t_dgst_ctx *ctx)
{
	uint64_t	state[8];
	uint64_t	w[80];
	uint64_t	s[2];
	uint64_t	*m;
	int			i;

	i = -1;
	ft_memcpy(state, ctx->state.x_64, sizeof(state));
	m = (uint64_t *)ctx->block;
	while (++i < 80)
	{
		if (i < 16)
			w[i] = ft_swap_uint64(&m[i]);
		else if (i < 80)
			w[i] = w[i - 16] + ft_sha512_wsigma0(w[i - 15]) + w[i - 7] + ft_sha512_wsigma1(w[i - 2]);
		s[0] = ft_sha512_sigma0(state, w[i], i);
		s[1] = ft_sha512_sigma1(state);
		ft_sha512_swap_state(state, s);
	}
	i = -1;
	while (++i < 8)
		ctx->state.x_64[i] += state[i];
	ctx->iblock = 0;
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}
static unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}
int			ft_sha512_final(t_dgst_ctx *ctx)
{
	unsigned int	i;
	unsigned int pad;
	__uint128_t 	ibits_x64;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + ctx->x, ctx->mbs);
	ibits_x64 = ctx->idata * 8;
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - ctx->x) && ctx->iblock != ctx->mbs)
		ctx->block[ctx->iblock++] = 0;
	if (ctx->iblock == ctx->mbs)
		ft_sha512_transform(ctx);
	ft_memset(&ctx->block[ctx->iblock], 0, (ctx->mbs - ctx->x) - ctx->iblock);
	ctx->iblock += (ctx->mbs - ctx->x) - ctx->iblock;
	ft_memrev(&ibits_x64, sizeof(ibits_x64));
	ft_memcpy(&ctx->block[ctx->iblock], &ibits_x64, sizeof(ibits_x64));
	ft_sha512_transform(ctx);
	i = -1;
	while (++i < ctx->sts)
		ft_swap_uint64(&ctx->state.x_64[i]);
	return (EXIT_SUCCESS);
}