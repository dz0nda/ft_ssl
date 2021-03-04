/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/03 11:12:36 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

int			ft_sha256_init(t_sha256_ctx *ctx, unsigned int msg_len)
{
	ctx->hs = FT_SHA256_HS;
	ctx->mbs = FT_SHA256_MBS;
	ctx->state_len = FT_SHA256_STATE;
	ctx->state[0] = 0x6a09e667;
	ctx->state[1] = 0xbb67ae85;
	ctx->state[2] = 0x3c6ef372;
	ctx->state[3] = 0xa54ff53a;
	ctx->state[4] = 0x510e527f;
	ctx->state[5] = 0x9b05688c;
	ctx->state[6] = 0x1f83d9ab;
	ctx->state[7] = 0x5be0cd19;
	return (EXIT_SUCCESS);
}

int			ft_sha256_pre_process(t_sha256_ctx *ctx, uint8_t *msg,
	unsigned int msg_len)
{
	int				i;
	unsigned int	pad;
	uint64_t		length;

	pad = ft_align_bits(msg_len + 8 + 1, ctx->mbs);
	ctx->msg_len = pad;
	ctx->msg = (uint8_t *)ft_memalloc(ctx->msg_len);
	ft_memmove(ctx->msg, msg, msg_len);
	ctx->msg[msg_len] = 0x80;
	i = msg_len;
	while (++i < (pad - FT_DGST_X32))
		ctx->msg[i] = 0;
	length = msg_len * 8;
	ft_memrev(&length, sizeof(length));
	ft_memcpy(&ctx->msg[i], &length, sizeof(length));
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

int			ft_sha256_transform(t_sha256_ctx *ctx)
{
	unsigned int	i;
	uint32_t		state[8];
	uint32_t		w[64];
	uint32_t		sigma[2];
	uint8_t			*data;

	data = &ctx->msg[0];
	while (ctx->msg_len--)
	{
		ctx->block[ctx->iblock++] = *data++;
		if (ctx->iblock == ctx->mbs)
		{
			i = -1;
			ft_memcpy(state, ctx->state, sizeof(state));
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
				ctx->state[i] += state[i];
			ctx->iblock = 0;
			ft_memset(ctx->block, 0, sizeof(ctx->block));
		}
	}
	ft_memdel((void *)&ctx->msg);
	return (EXIT_SUCCESS);
}

char		*ft_sha256_final(t_sha256_ctx *ctx, char *cmd_dgst)
{
	int		i;
	int		j;
	char	s[4];
	uint8_t	*p;

	i = -1;
	ft_bzero(cmd_dgst, ctx->hs);
	while (++i < ctx->state_len)
	{
		j = -1;
		ft_swap_uint32(&ctx->state[i]);
		p = (uint8_t *)&ctx->state[i];
		while (++j < 4)
			ft_itoa(p[j], &cmd_dgst[ft_strlen(cmd_dgst)], 16);
	}
	return (cmd_dgst);
}
