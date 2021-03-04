/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:07:42 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/04 11:12:41 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

int			ft_md5_init(t_md5_ctx *ctx)
{
	ctx->hs = FT_MD5_HS;
	ctx->mbs = FT_MD5_MESSAGE_BLOCK_SIZE;
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xefcdab89;
	ctx->state[2] = 0x98badcfe;
	ctx->state[3] = 0x10325476;
	return (EXIT_SUCCESS);
}

int			ft_md5_pad(t_md5_ctx *ctx, uint8_t *msg, unsigned int msg_len)
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
	while (++i < (pad - 8))
		ctx->msg[i] = 0;
	length = msg_len * 8;
	ft_memcpy(&ctx->msg[i], &length, sizeof(length));
	return (EXIT_SUCCESS);
}

int			ft_md5_process(uint32_t state[8], uint32_t words[80])
{
	unsigned int	i;
	uint32_t		sigma;

	i = -1;
	sigma = 0;
	while (++i < 64)
	{
		sigma = ft_md5_hash_f(i, state[1], state[2], state[3]) + state[0]
			+ ft_md5_hash_k(i) + words[ft_md5_hash_g(i)];
		state[0] = state[3];
		state[3] = state[2];
		state[2] = state[1];
		state[1] = state[1] + ft_rotl_uint32(sigma, ft_md5_hash_s(i));
	}
	return (EXIT_SUCCESS);
}

int			ft_md5_transform(t_md5_ctx *ctx)
{
	unsigned int	i;
	uint32_t		state[FT_MD5_STATE];
	uint8_t			*data;

	data = &ctx->msg[0];
	while (ctx->msg_len--)
	{
		ctx->block[ctx->iblock++] = *data++;
		if (ctx->iblock == FT_MD5_MESSAGE_BLOCK_SIZE)
		{
			ft_memcpy(state, ctx->state, sizeof(state));
			ft_memcpy(ctx->words, ctx->block, sizeof(ctx->words));
			ft_md5_process(state, ctx->words);
			i = -1;
			while (++i < FT_MD5_STATE)
				ctx->state[i] += state[i];
			ctx->iblock = 0;
			ft_memset(ctx->block, 0, sizeof(ctx->block));
		}
	}
	ft_memdel((void *)&ctx->msg);
	return (EXIT_SUCCESS);
}

char		*ft_md5_final(t_md5_ctx *ctx, char *cmd_dgst)
{
	unsigned int	i;
	unsigned int	j;
	uint8_t			*p;

	i = -1;
	while (++i < FT_MD5_STATE)
	{
		p = (uint8_t *)&ctx->state[i];
		j = -1;
		while (++j < 4)
			ft_itoa(p[j], &cmd_dgst[ft_strlen(cmd_dgst)], 16);
	}
	return (cmd_dgst);
}
