/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_update_md5.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 00:34:58 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 00:34:59 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

int				ft_sha1_update(t_dgst_ctx *ctx, const void *data, int len)
{
	unsigned char *ucdata;

	ucdata = (unsigned char *)data;
	while (ctx->idata < len)
	{
		if (ctx->iblock == ctx->len_mbs)
		{
			ft_md5_transform(ctx);
			ctx->iblock = 0;
			ft_memset(ctx->iblock, 0, sizeof(ctx->iblock));
		}
	}
	return (EXIT_SUCCESS);
}

int				ft_md5_update(t_dgst_ctx *ctx, const void *data, int len)
{
	unsigned char *ucdata;

	ucdata = (unsigned char *)data;
 	while (ctx->idata < len)
	{
		ctx->block[ctx->iblock++] = ucdata[ctx->idata++];
		if (ctx->iblock == ctx->len_mbs)
		{
			ft_md5_transform(ctx);
			ctx->iblock = 0;
			ft_memset(ctx->iblock, 0, sizeof(ctx->iblock));
		}
	}
	return (EXIT_SUCCESS);
}

// void		ft_md5_transform(uint32_t *state, const void *data)
// {
// 	int	i;
// 	uint32_t 	ks[2];
// 	uint32_t 	fg[2];
// 	uint32_t	*w;

// 	i = -1;
// 	ft_memset(ks, 0, sizeof(ks));
// 	ft_memset(fg, 0, sizeof(fg));
// 	w = (uint32_t *)data;
// 	if (FT_DGST_DEBUG)
// 		ft_putstr("\n == Operations == \n");
// 	while (++i < 64)
// 	{
// 		ft_md5_process_ks(ks, i);
// 		ft_md5_process_fg(fg, i, state[1], state[2], state[3]);
// 		fg[0] = fg[0] + state[0] + ks[0] + w[fg[1]];
// 		state[0] = state[3];
// 		state[3] = state[2];
// 		state[2] = state[1];
// 		state[1] = state[1] + ft_rotate_left(fg[0], ks[1]);
// 		if (FT_DGST_DEBUG)
// 			ft_dgst_update_process_debug(state, i, 4);
// 	}
// }

// int				ft_dgst_update_md5(t_dgst_ctx *ctx)
// {
// 	int 		i;
// 	int			j;
// 	uint32_t	*w;
// 	uint32_t	state[4];

//     i = 0;
// 	j = -1;
// 	w = NULL;
// 	ft_memset(state, 0, sizeof(state));
//  	while (i < ctx->len_block)
// 	{
// 		w = (uint32_t *)((char *)ctx->block + i);
// 		if (FT_DGST_DEBUG)
// 			ft_dgst_update_words_debug(w, 16);
// 		ft_memcpy(state, ctx->state, sizeof(state));
// 		ft_md5_transform_old(state, w);
// 		j = -1;
// 		while (++j < ctx->len_state)
//         	ctx->state[j] += state[j];
// 		if (FT_DGST_DEBUG)
// 			ft_dgst_state_debug(ctx->state, ctx->len_state);
// 		i += ctx->len_mbs;
// 	}
// 	return (EXIT_SUCCESS);
// }
