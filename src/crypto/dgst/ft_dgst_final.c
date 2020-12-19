/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgst_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:34:09 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 18:43:01 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dgst.h"

char        *ft_dgst_result(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int		i;
	unsigned int		j;
	char	s[6];
	uint8_t	*p;
	int nb = 0;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < ctx->sts)
	{
		p = (ctx->x == FT_DGST_X64) ? (uint8_t *)&ctx->state.x_64[i] : (uint8_t *)&ctx->state.x_32[i];
		j = -1;
		while (++j < (ctx->x / 2))
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(cmd_dgst, s);
			nb++;
			if (nb == ctx->hs)
				break;
		}
		if (nb == ctx->hs)
			break;
	}
	return (cmd_dgst);
}