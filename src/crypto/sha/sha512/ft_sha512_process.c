/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:08:37 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_hash.h"

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

int			ft_sha512_process(uint64_t	state[8], uint64_t words[80])
{
	int				i;
	uint64_t	sigma[2];

	i = -1;
	ft_memset(sigma, 0, sizeof(sigma));
	while (++i < 80)
	{
		sigma[0] = ft_sha512_sigma0(state, words[i], i);
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
	return (EXIT_SUCCESS);
}

int				ft_sha512_transform(t_dgst_ctx *ctx)
{
	uint64_t	state[8];
	uint64_t	w[80];
	uint64_t	s[2];
	int			i;

	i = -1;
	ft_memcpy(state, ctx->state.x_64, sizeof(state));
	ft_sha512_process_words(ctx->block, w);
	ft_sha512_process(state, w);
	// while (++i < 80)
	// {
		// if (i < 16)
		// 	w[i] = ft_swap_uint64(&m[i]);
		// else if (i < 80)
		// 	w[i] = w[i - 16] + ft_sha512_wsigma0(w[i - 15]) + w[i - 7] + ft_sha512_wsigma1(w[i - 2]);
		// s[0] = ft_sha512_sigma0(state, w[i], i);
		// s[1] = ft_sha512_sigma1(state);
		// ft_sha512_swap_state(state, s);
	// }
	i = -1;
	while (++i < 8)
		ctx->state.x_64[i] += state[i];
	ctx->iblock = 0;
	ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}
