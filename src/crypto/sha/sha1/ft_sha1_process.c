/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:11:52 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:11:44 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

static void     ft_sha1_transform_word(uint32_t *w, const void *data)
{
    int i;
    uint32_t    rotator;
    uint32_t	*m;

    i = -1;
    rotator = 0;
    m = (uint32_t *)data;
    while (++i < 16)
        w[i] = ft_swap_uint32(&m[i]);
    while (i < 80)
    {
        rotator = (w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16]);
        w[i] = ft_rotl_uint32(rotator, 1);
        i++;
    }
}

int				ft_sha1_transform(t_dgst_ctx *ctx)
{
	unsigned int      i;
    uint32_t state[FT_SHA1_STATE];
    uint32_t w[80];
    uint32_t tmp;

	i = -1;
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	ft_sha1_transform_word(w, ctx->block);
	while (++i < 80)
	{
		tmp = ft_rotl_uint32(state[0], 5) + ft_sha1_hash_f(i, state[1], state[2], state[3]) + state[4] + ft_sha1_hash_k(i) + w[i];
		state[4] = state[3];
		state[3] = state[2];
		state[2] = ft_rotl_uint32(state[1], 30);
		state[1] = state[0];
		state[0] = tmp;
	}
	i = -1;
	while (++i < FT_SHA1_STATE)
			ctx->state.x_32[i] += state[i];
	ctx->iblock = 0;
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}
