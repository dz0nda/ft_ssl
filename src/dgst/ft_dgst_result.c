/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_result.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 16:06:25 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 16:03:52 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

char		    *ft_dgst_result_x32(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int i;
	int		j;
	char	s[3];
	uint8_t	*p;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < ctx->sts)
	{
		j = -1;
        if (ctx->endian == FT_DGST_ENDIAN_BIG)
		    ctx->state.x_32[i] = ft_swap_uint(ctx->state.x_32[i], sizeof(ctx->state.x_32[i]));
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

char        *ft_dgst_result_x64(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int		i;
	int		j;
	char	s[6];
	uint8_t	*p;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < ctx->sts)
	{
		j = -1;
        if (ctx->endian == FT_DGST_ENDIAN_BIG)
		    ctx->state.x_64[i] = ft_swap_uint(ctx->state.x_64[i], sizeof(ctx->state.x_64[i])); 
		p = (uint8_t *)&ctx->state.x_64[i];
		while (++j < 8)
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(cmd_dgst, s);
		}
	}
	return (cmd_dgst);
}