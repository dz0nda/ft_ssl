/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:07:42 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/19 23:00:54 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

int			ft_md5_init(t_dgst_ctx *ctx, unsigned int msg_len)
{
	ctx->hs = FT_MD5_HS;
	ctx->mbs = FT_MD5_MBS;
	ctx->endian = FT_DGST_ENDIAN_LITTLE;
	ctx->sts = FT_MD5_STATE;
	ctx->x = FT_DGST_X32;
	ctx->state.x_32[0] = 0x67452301;
	ctx->state.x_32[1] = 0xefcdab89;
	ctx->state.x_32[2] = 0x98badcfe;
	ctx->state.x_32[3] = 0x10325476;
	ctx->len.x_32 = msg_len * 8;
	ctx->padding = ft_get_size_aligned(ctx->len.x_32 + ctx->x, ctx->mbs) - ctx->x;
	return (EXIT_SUCCESS);
}

int     		ft_md5_process(uint32_t	state[8], uint32_t words[16])
{
	unsigned int	i;
	uint32_t sigma;

	i = -1;
	sigma = 0;
	while (++i < 64)
	{
		sigma = ft_md5_hash_f(i, state[1], state[2], state[3]) + state[0] + ft_md5_hash_k(i) + words[ft_md5_hash_g(i)];
		state[0] = state[3];
		state[3] = state[2];
		state[2] = state[1];
		state[1] = state[1] + ft_rotl_uint32(sigma, ft_md5_hash_s(i));
	}
	return (EXIT_SUCCESS);
}

int     		ft_md5_transform(t_dgst_ctx *ctx)
{
	unsigned int	i;
	uint32_t f;
	uint32_t	state[FT_MD5_STATE];
	uint32_t	w[16];

	i = -1;
	// while (++i < FT_MD5_MBS)
	// 	printf("[%d] %x\n", i, ctx->block[i]);
	// printf("\n");
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	// ft_dgst_update_process_debug(state, -42, FT_MD5_STATE);
	ft_memcpy(w, ctx->block, sizeof(w));
	ft_md5_process(state, w);
	// while (++i < FT_MD5_MBS)
	// {
	// 	f = ft_md5_hash_f(i, state[1], state[2], state[3]) + state[0] + ft_md5_hash_k(i) + w[ft_md5_hash_g(i)];
	// 	state[0] = state[3];
	// 	state[3] = state[2];
	// 	state[2] = state[1];
	// 	state[1] = state[1] + ft_rotl_uint32(f, ft_md5_hash_s(i));
	// }
	i = -1;
	while (++i < ctx->sts)
		ctx->state.x_32[i] += state[i];
	// ft_dgst_update_process_debug(state, -42, FT_MD5_STATE);
	ctx->iblock = 0;
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}

char		*ft_md5_final(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int		i;
	unsigned int		j;
	char	s[6];
	uint8_t	*p;
	int nb = 0;

	i = -1;
	while (++i < ctx->sts)
	{
		p = (uint8_t *)&ctx->state.x_32[i];
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
