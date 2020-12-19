/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:07:42 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:16:27 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

int     		ft_md5_transform(t_dgst_ctx *ctx)
{
	unsigned int	i;
	uint32_t f;
	uint32_t	state[FT_MD5_STATE];
	uint32_t	w[16];

	i = -1;
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	ft_memcpy(w, ctx->block, sizeof(w));
	while (++i < FT_MD5_MBS)
	{
		f = ft_md5_hash_f(i, state[1], state[2], state[3]) + state[0] + ft_md5_hash_k(i) + w[ft_md5_hash_g(i)];
		state[0] = state[3];
		state[3] = state[2];
		state[2] = state[1];
		state[1] = state[1] + ft_rotl_uint32(f, ft_md5_hash_s(i));
	}
	i = -1;
	while (++i < ctx->sts)
		ctx->state.x_32[i] += state[i];
	ctx->iblock = 0;
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}
