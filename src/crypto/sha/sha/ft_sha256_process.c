/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/07 16:22:05 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

int 		ft_sha256_process_words(uint8_t block[FT_SHA512_MBS], uint32_t w[64])
{
	int i;

	i = -1;
	while (++i < 64)
	{
		if (i < 16)
			w[i] = ft_swap_uint32((uint32_t *)&block[i * 4]);
		else if (i < 64)
			w[i] = w[i - 16] + ft_sha256_wsigma0(w[i - 15]) + w[i - 7] + ft_sha256_wsigma1(w[i - 2]);
	}
	return (EXIT_SUCCESS);
}

int			ft_sha256_process(uint32_t	state[8], uint32_t words[64])
{
	int				i;
	uint32_t	sigma[2];

	i = -1;
	ft_memset(sigma, 0, sizeof(sigma));
	while (++i < 64)
	{
		sigma[0] = ft_sha256_sigma0(state, words[i], i);
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
	return (EXIT_SUCCESS);
}

int			ft_sha256_transform(t_dgst_ctx *ctx)
{
	unsigned int			i;
	uint32_t	state[8];
	uint32_t	sigma[2];
	uint32_t	w[64];
	
	i = -1;
	ft_memcpy(state, ctx->state.x_32, sizeof(state));
	// ft_memset(sigma, 0, sizeof(sigma));
	ft_sha256_process_words(ctx->block, w);
	// ft_sha256_process(state, w);
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
	// ctx->iblock = 0;
	// ft_memset(ctx->block, 0, sizeof(ctx->block));
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
