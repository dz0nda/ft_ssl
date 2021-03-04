/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:11:52 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/04 11:27:57 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

int				ft_sha1_init(t_sha1_ctx *ctx)
{
	ctx->hs = FT_SHA1_HS;
	ctx->mbs = FT_SHA1_MBS;
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xefcdab89;
	ctx->state[2] = 0x98badcfe;
	ctx->state[3] = 0x10325476;
	ctx->state[4] = 0xc3d2e1f0;
	return (EXIT_SUCCESS);
}

int				ft_sha1_pre_process(t_sha1_ctx *ctx, uint8_t *msg,
	unsigned int msg_len)
{
	int				i;
	int				pad;
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

static void		ft_sha1_process_hash(t_sha1_ctx *ctx, uint32_t state[5],
	uint32_t w[80])
{
	int			i;
	uint32_t	rotator;
	uint32_t	*m;
	uint32_t	tmp;

	i = -1;
	rotator = 0;
	m = (uint32_t *)ctx->block;
	while (++i < 80)
	{
		if (i < 16)
			w[i] = ft_swap_uint32(&m[i]);
		else
			w[i] = ft_rotl_uint32((w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16]),
				1);
		tmp = ft_rotl_uint32(state[0], 5)
			+ ft_sha1_hash_f(i, state[1], state[2], state[3])
			+ state[4] + ft_sha1_hash_k(i) + w[i];
		state[4] = state[3];
		state[3] = state[2];
		state[2] = ft_rotl_uint32(state[1], 30);
		state[1] = state[0];
		state[0] = tmp;
	}
}

int				ft_sha1_transform(t_sha1_ctx *ctx)
{
	unsigned int	i;
	uint32_t		state[FT_SHA1_STATE];
	uint32_t		w[80];
	uint8_t			*data;

	data = &ctx->msg[0];
	while (ctx->msg_len--)
	{
		ctx->block[ctx->iblock++] = *data++;
		if (ctx->iblock == ctx->mbs)
		{
			i = -1;
			ft_memcpy(state, ctx->state, sizeof(state));
			ft_sha1_process_hash(ctx, state, w);
			i = -1;
			while (++i < FT_SHA1_STATE)
				ctx->state[i] += state[i];
			ctx->iblock = 0;
			ft_memset(ctx->block, 0, sizeof(ctx->block));
		}
	}
	return (EXIT_SUCCESS);
}

char			*ft_sha1_final(t_sha1_ctx *ctx, char *cmd_dgst)
{
	int		i;
	int		j;
	uint8_t	*p;

	i = -1;
	while (++i < FT_SHA1_STATE)
	{
		j = -1;
		ft_swap_uint32(&ctx->state[i]);
		p = (uint8_t *)&ctx->state[i];
		while (++j < 4)
			ft_itoa(p[j], &cmd_dgst[ft_strlen(cmd_dgst)], 16);
	}
	return (cmd_dgst);
}
