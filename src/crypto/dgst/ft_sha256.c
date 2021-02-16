/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/03 13:05:37 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dgst.h"

int			ft_sha256_init(t_dgst_ctx *ctx, unsigned int msg_len)
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
	ctx->len.x_32 = msg_len * 8;
	ft_memrev(&ctx->len.x_32, sizeof(ctx->len.x_32));
	ctx->padding = ft_align_bits(ctx->len.x_32 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}

int			ft_sha256_pre_process(t_dgst_ctx *ctx, uint8_t *msg,
	unsigned int msg_len)
{
	int				i;
	unsigned int	pad;

	pad = ft_align_bits(msg_len + ctx->x + 1, ctx->mbs);
	ctx->msg_len = pad;
	ctx->msg = (uint8_t *)ft_memalloc(ctx->msg_len);
	ft_memmove(ctx->msg, msg, msg_len);
	ctx->msg[msg_len] = 0x80;
	i = msg_len;
	while (++i < (pad - ctx->x))
		ctx->msg[i] = 0;
	ft_memcpy(&ctx->msg[i], &ctx->len.x_32, sizeof(ctx->len.x_32));
	return (EXIT_SUCCESS);
}

int			ft_sha256_process_words(uint8_t block[FT_SHA512_MBS],
	uint32_t w[64])
{
	int		i;

	i = -1;
	while (++i < 64)
	{
		if (i < 16)
			w[i] = ft_swap_uint32((uint32_t *)&block[i * 4]);
		else if (i < 64)
			w[i] = w[i - 16] + ft_sha256_wsigma0(w[i - 15]) + w[i - 7]
					+ ft_sha256_wsigma1(w[i - 2]);
	}
	return (EXIT_SUCCESS);
}

int			ft_sha256_transform(t_dgst_ctx *ctx)
{
	unsigned int	i;
	uint32_t		state[8];
	uint32_t		w[64];
	uint32_t		sigma[2];

	i = -1;
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	ft_sha256_process_words(ctx->block, w);
	while (++i < 64)
	{
		sigma[0] = ft_sha256_sigma0(state, w[i], i);
		sigma[1] = ft_sha256_sigma1(state);
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
		ctx->state.x_32[i] += state[i];
	return (EXIT_SUCCESS);
}

char		*ft_sha256_final(t_dgst_ctx *ctx, char *cmd_dgst)
{
	int		i;
	int		j;
	char	s[4];
	uint8_t	*p;

	i = -1;
	while (++i < ctx->sts)
	{
		j = -1;
		ft_swap_uint32(&ctx->state.x_32[i]);
		p = (uint8_t *)&ctx->state.x_32[i];
		while (++j < 4)
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(cmd_dgst, s);
		}
	}
	return (cmd_dgst);
}
