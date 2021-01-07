/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:11:52 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/07 16:15:29 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

static void     ft_sha1_process_words(uint32_t *w, const void *data)
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
void    ft_dgst_update_process_debug(uint32_t *state, int i, int n)
{
    const char letter[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    int j;

    j = -1;
    printf("[i = %d] ", i);
    while (++j < n)
        printf("%c=%u ", letter[j], state[j]);
    printf("\n");
}

int			ft_sha1_process(uint32_t	state[5], uint32_t words[80])
{
		unsigned int      i;
    uint32_t tmp;

	i = -1;

	while (++i < 80)
	{
		tmp = ft_rotl_uint32(state[0], 5) + ft_sha1_hash_f(i, state[1], state[2], state[3]) + state[4] + ft_sha1_hash_k(i) + words[i];
		state[4] = state[3];
		state[3] = state[2];
		state[2] = ft_rotl_uint32(state[1], 30);
		state[1] = state[0];
		state[0] = tmp;
		// ft_dgst_update_process_debug(state, i, FT_SHA1_STATE);
	}
	return (EXIT_SUCCESS);
}

int				ft_sha1_transform(t_dgst_ctx *ctx)
{
	unsigned int      i;
    uint32_t state[FT_SHA1_STATE];
    uint32_t w[80];
    uint32_t tmp;

	i = -1;
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	// ft_dgst_update_process_debug(state, -42, FT_SHA1_STATE);
	ft_sha1_process_words(w, ctx->block);
	// ft_sha1_process(state, w);
	while (++i < 80)
	{
		tmp = ft_rotl_uint32(state[0], 5) + ft_sha1_hash_f(i, state[1], state[2], state[3]) + state[4] + ft_sha1_hash_k(i) + w[i];
		state[4] = state[3];
		state[3] = state[2];
		state[2] = ft_rotl_uint32(state[1], 30);
		state[1] = state[0];
		state[0] = tmp;
		// ft_dgst_update_process_debug(state, i, FT_SHA1_STATE);
	}
	i = -1;
	while (++i < FT_SHA1_STATE)
			ctx->state.x_32[i] += state[i];
	// ft_dgst_update_process_debug(ctx->state.x_32, -42, FT_SHA1_STATE);
	// ctx->iblock = 0;
	// ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}

char		*ft_sha1_final(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int		i;
	unsigned int		j;
	char	s[6];
	uint8_t	*p;
	int nb = 0;
	i = -1;

	// ft_sha1_pad(ctx);
	// ft_sha1_add_length(ctx);
	while (++i < ctx->sts)
	{
		ft_swap_uint32(&ctx->state.x_32[i]);
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
