/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/19 23:01:44 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

int			ft_sha512_init(t_dgst_ctx *ctx, unsigned int msg_len)
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
	ctx->len.x_64 = msg_len * 8;
	ft_memrev(&ctx->len.x_64, sizeof(ctx->len.x_64));
	ctx->padding = ft_get_size_aligned(ctx->len.x_64 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}

int			ft_sha512_pre_process(t_dgst_ctx *ctx, uint8_t *msg, unsigned int msg_len)
{
	int i;
	unsigned int 	pad;

	pad = ft_get_size_aligned(msg_len + ctx->x + 1, ctx->mbs);
	ctx->msg_len = pad;
	ctx->msg = (uint8_t *)ft_memalloc(ctx->msg_len);
	ft_memmove(ctx->msg, msg, msg_len);
	ctx->msg[msg_len] = 0x80;
	i = msg_len;
	while (++i < (pad - ctx->x))
		ctx->msg[i] = 0;
  ft_memcpy(&ctx->msg[i], &ctx->len.x_64, sizeof(ctx->len.x_64));
  return (EXIT_SUCCESS);
}

int 		ft_sha512_process_words(uint8_t block[FT_SHA512_MBS], uint64_t w[80])
{
	int i;

	i = -1;
	while (++i < 80)
	{
		if (i < 16)
			w[i] = ft_swap_uint64((uint64_t *)&block[i * 8]);
		else if (i < 80)
			w[i] = w[i - 16] + ft_sha512_wsigma0(w[i - 15]) + w[i - 7] + ft_sha512_wsigma1(w[i - 2]);
	}
	return (EXIT_SUCCESS);
}

int				ft_sha512_transform(t_dgst_ctx *ctx)
{
	uint64_t	state[8];
	uint64_t	w[80];
	uint64_t	sigma[2];
	int			i;

	i = -1;
	ft_memset(sigma, 0, sizeof(sigma));
	ft_memcpy(state, ctx->state.x_64, sizeof(state));
	ft_sha512_process_words(ctx->block, w);
	while (++i < 80)
	{
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
	i = -1;
	while (++i < 8)
		ctx->state.x_64[i] += state[i];
	return (EXIT_SUCCESS);
}

char		*ft_sha512_final(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int		i;
	unsigned int		j;
	char	s[6];
	uint8_t	*p;

	i = -1;
	while (++i < ctx->sts)
	{
		ft_swap_uint64(&ctx->state.x_64[i]);
		p = (uint8_t *)&ctx->state.x_64[i];
		j = -1;
		while (++j < (ctx->x / 2))
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(cmd_dgst, s);
		}
	}
	return (cmd_dgst);
}