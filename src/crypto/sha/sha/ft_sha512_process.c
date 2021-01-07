/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/07 16:43:04 by dzonda           ###   ########lyon.fr   */
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
	uint64_t	sigma[2];
	int			i;

	i = -1;
	ft_memset(sigma, 0, sizeof(sigma));
	ft_memcpy(state, ctx->state.x_64, sizeof(state));
	ft_sha512_process_words(ctx->block, w);
	while (++i < 80)
	{
		sigma[0] = ft_sha512_sigma0(state, w[i], i);
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
	i = -1;
	while (++i < 8)
		ctx->state.x_64[i] += state[i];
	// ctx->iblock = 0;
	// ft_memset(ctx->block, 0, sizeof(ctx->block));
	return (EXIT_SUCCESS);
}

char		*ft_sha512_final(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int		i;
	unsigned int		j;
	char	s[6];
	uint8_t	*p;
	int nb = 0;

	i = -1;

	// ft_sha512_pad(ctx);
	// ft_sha512_add_length(ctx);
	while (++i < ctx->sts)
	{
		// printf("here");
		ft_swap_uint64(&ctx->state.x_64[i]);
		p = (uint8_t *)&ctx->state.x_64[i];
		j = -1;
		while (++j < (ctx->x / 2))
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(cmd_dgst, s);
			// nb++;
			// if (nb == ctx->hs)
			// 	return (cmd_dgst);
		}
	}
	return (cmd_dgst);
}