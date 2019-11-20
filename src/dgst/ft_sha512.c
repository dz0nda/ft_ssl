/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sha512.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 08:19:12 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 08:43:18 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

int			ft_sha512_init(t_dgst_ctx *ctx)
{
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

static void		ft_sha512_transform_word(uint64_t *w, const void *data)
{
	int			i;
	uint64_t	*m;
	uint64_t	s0;
	uint64_t	s1;

	i = -1;
	m = (uint64_t *)data;
	while (++i < 16)
		w[i] = ft_swap_uint_x64(m[i]);
	while (i < 80)
	{
		s0 = FT_DGST_ROTR_X64(w[i - 15], 1) ^ FT_DGST_ROTR_X64(w[i - 15], 8) ^ FT_DGST_SHFR(w[i - 15], 7);
		s1 = FT_DGST_ROTR_X64(w[i - 2], 19) ^ FT_DGST_ROTR_X64(w[i - 2], 61) ^ FT_DGST_SHFR(w[i - 2], 6);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

static void		ft_sha512_transform_s(uint64_t state[8], uint64_t s[2], uint64_t w, int i)
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
	uint64_t ch;
	uint64_t maj;

	s[0] = FT_DGST_ROTR_X64(state[4], 14) ^ FT_DGST_ROTR_X64(state[4], 18) ^ FT_DGST_ROTR_X64(state[4], 41);
	ch = (state[4] & state[5]) ^ ((~state[4]) & state[6]);
	s[0] = state[7] + s[0] + ch + k[i] + w;
	s[1] = FT_DGST_ROTR_X64(state[0], 28) ^ FT_DGST_ROTR_X64(state[0], 34) ^ FT_DGST_ROTR_X64(state[0], 39);
	maj = (state[0] & state[1]) ^ (state[0] & state[2]) ^ (state[1] & state[2]);
	s[1] = s[1] + maj;
}

int				ft_sha512_transform(t_dgst_ctx *ctx)
{
	int			i;
	uint64_t	state[8];
	uint64_t	w[80];
	uint64_t	s[2];

	i = -1;
	ft_memcpy(state, ctx->state.x_64, sizeof(state));
	ft_sha512_transform_word(w, ctx->block);
	while (++i < 80)
	{
		ft_sha512_transform_s(state, s, w[i], i);
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
		ctx->state.x_64[i] += state[i];
	return (EXIT_SUCCESS);
}
