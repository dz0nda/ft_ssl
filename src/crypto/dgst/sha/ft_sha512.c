/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/23 23:36:36 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

int		ft_sha512_init(t_sha512_ctx *ctx, unsigned int msg_len)
{
	ctx->hs = FT_SHA512_HS;
	ctx->mbs = FT_SHA512_MBS;
	ctx->state_len = FT_SHA512_STATE;
	// ctx->endian = FT_DGST_ENDIAN_BIG;
	// FT_SHA512_STATE = FT_SHA512_STATE;
	// FT_DGST_X64 = FT_DGST_X64;
	ctx->state[0] = 0x6a09e667f3bcc908;
	ctx->state[1] = 0xbb67ae8584caa73b;
	ctx->state[2] = 0x3c6ef372fe94f82b;
	ctx->state[3] = 0xa54ff53a5f1d36f1;
	ctx->state[4] = 0x510e527fade682d1;
	ctx->state[5] = 0x9b05688c2b3e6c1f;
	ctx->state[6] = 0x1f83d9abfb41bd6b;
	ctx->state[7] = 0x5be0cd19137e2179;
	// ctx->len.x_64 = msg_len * 8;
	// ft_memrev(&ctx->len.x_64, sizeof(ctx->len.x_64));
	// ctx->padding = ft_align_bits(ctx->len.x_64 + FT_DGST_X64, ctx->mbs) - FT_DGST_X64;
	return (EXIT_SUCCESS);
}

int		ft_sha512_pre_process(t_sha512_ctx *ctx, uint8_t *msg,
	unsigned int msg_len)
{
	int				i;
	unsigned int	pad;
	__uint128_t length;

	pad = ft_align_bits(msg_len + FT_DGST_X64 + 1, ctx->mbs);
	ctx->msg_len = pad;
	ctx->msg = (uint8_t *)ft_memalloc(ctx->msg_len);
	ft_memmove(ctx->msg, msg, msg_len);
	ctx->msg[msg_len] = 0x80;
	i = msg_len;
	while (++i < (pad - FT_DGST_X64))
		ctx->msg[i] = 0;
	length = msg_len * 8;
	ft_memrev(&length, sizeof(length));
	ft_memcpy(&ctx->msg[i], &length, sizeof(length));
	return (EXIT_SUCCESS);
}

// int		ft_sha512_process_words(uint8_t block[FT_SHA512_MBS], uint64_t w[80])
// {
// 	int i;

// 	i = -1;
// 	while (++i < 80)
// 	{
// 		if (i < 16)
// 			w[i] = ft_swap_uint64((uint64_t *)&block[i * 8]);
// 		else if (i < 80)
// 			w[i] = w[i - 16] + ft_sha512_wsigma0(w[i - 15]) + w[i - 7]
// 					+ ft_sha512_wsigma1(w[i - 2]);
// 	}
// 	return (EXIT_SUCCESS);
// }

int		ft_sha512_process_hash(t_sha512_ctx *ctx, uint64_t state[8], uint64_t	w[80])
{
	int i;
	// uint64_t	w[80];
	uint64_t	sigma[2];
	// uint64_t	state[8];

	i = -1;
	// ft_memcpy(state, ctx->state, sizeof(state));
	while (++i < 80)
	{
		if (i < 16)
			w[i] = ft_swap_uint64((uint64_t *)&ctx->block[i * 8]);
		else if (i < 80)
			w[i] = w[i - 16] + ft_sha512_wsigma0(w[i - 15]) + w[i - 7]
					+ ft_sha512_wsigma1(w[i - 2]);
		sigma[0] = ft_sha512_sigma0(state, w[i], i);
		sigma[1] = ft_sha512_sigma1(state);
		state[7] = state[6];
		state[6] = state[5];
		state[5] = state[4];
		state[4] = state[3] + sigma[0];
		state[3] = state[2];
		state[2] = state[1];
		state[1] = state[0];
		state[0] = sigma[0] + sigma[1];
	}
	return (EXIT_SUCCESS);
}

int		ft_sha512_transform(t_sha512_ctx *ctx)
{
	uint64_t	state[8];
	uint64_t	w[80];
	// uint64_t	sigma[2];
	int			i;
	uint8_t			*data;

	data = &ctx->msg[0];
	while (ctx->msg_len--)
	{
		ctx->block[ctx->iblock++] = *data++;
		if (ctx->iblock == ctx->mbs)
		{
			i = -1;
	// ft_memset(sigma, 0, sizeof(sigma));
			ft_memcpy(state, ctx->state, sizeof(state));
			// while (++i < 80)
			 ft_sha512_process_hash(ctx, state, w);
			i = -1;
			while (++i < 8)
				ctx->state[i] += state[i];
			ctx->iblock = 0;
			ft_memset(ctx->block, 0, sizeof(ctx->block));
		}
	}
	ft_memdel((void *)&ctx->msg);
	// ft_sha512_process_words(ctx->block, w);
	// while (++i < 80)
	// {
	// 	sigma[0] = ft_sha512_sigma0(state, w[i], i);
	// 	sigma[1] = ft_sha512_sigma1(state);
	// 	state[7] = state[6];
	// 	state[6] = state[5];
	// 	state[5] = state[4];
	// 	state[4] = state[3] + sigma[0];
	// 	state[3] = state[2];
	// 	state[2] = state[1];
	// 	state[1] = state[0];
	// 	state[0] = sigma[0] + sigma[1];
	// }
	// i = -1;
	// while (++i < 8)
	// 	ctx->state[i] += state[i];
	return (EXIT_SUCCESS);
}

char	*ft_sha512_final(t_sha512_ctx *ctx, char *cmd_dgst)
{
	int	i;
	int	j;
	// char			s[6];
	uint8_t			*p;

	i = -1;
	ft_bzero(cmd_dgst, ctx->hs);
	while (++i < ctx->state_len)
	{
		ft_swap_uint64(&ctx->state[i]);
		p = (uint8_t *)&ctx->state[i];
		j = -1;
		while (++j < 8)
			ft_itoa(p[j], &cmd_dgst[ft_strlen(cmd_dgst)], 16);
	}
	return (cmd_dgst);
}
