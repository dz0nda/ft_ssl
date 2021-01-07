/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:07:42 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/22 19:56:20 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

// static unsigned int		ft_get_size_aligned(size_t offset, size_t align)
// {
// 	return (offset + (align - (offset % align) % align));
// }

int		ft_md5_pad(t_dgst_ctx *ctx)
{
	unsigned int	i;
	unsigned int 	pad;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + ctx->x, FT_MD5_MBS);
	// printf("iblock: %d\n", i);
	// printf("pad: %d\n", pad);
	ctx->block[ctx->iblock++] = 0x80;
	while (ctx->iblock < (pad - ctx->x) && ctx->iblock != FT_MD5_MBS)
		ctx->block[ctx->iblock++] = 0;
	// printf("iblock: %d\n", i);
	// printf("pad: %d\n\n", pad);
	// if (ctx->iblock != FT_MD5_MBS)
	// 	ft_memset(&ctx->block[ctx->iblock], 0, pad - i);
	// if (ctx->iblock == FT_MD5_MBS)
	// 	ft_md5_transform(ctx);
	// ft_memset(&ctx->block[ctx->iblock], 0, (FT_MD5_MBS - ctx->x) - ctx->iblock);
	// ctx->iblock += (FT_MD5_MBS - ctx->x) - ctx->iblock;
	return (EXIT_SUCCESS);

}

int		ft_md5_add_length(t_dgst_ctx *ctx)
{
	uint64_t 			ibits;
	unsigned int 	pad;
	unsigned int	i;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock, FT_MD5_MBS);
	// ibits = ctx->idata * 8;
	// printf("iblock: %d\n", ctx->iblock);
	// printf("pad: %d\n", pad);
	// while (ctx->iblock < (pad - ctx->x))
	// 	ctx->block[ctx->iblock++] = 0;
	// printf("iblock: %d\n", ctx->iblock);
	// printf("pad: %d\n", pad);
	ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
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

	// ft_md5_pad(ctx);
	// if (ctx->iblock == FT_MD5_MBS)
	// 	ft_md5_transform(ctx);
	// ft_md5_add_length(ctx);
	// ft_md5_transform(ctx);
	while (++i < ctx->sts)
	{
		p = (uint8_t *)&ctx->state.x_32[i];
		j = -1;
		while (++j < (ctx->x / 2))
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(cmd_dgst, s);
			nb++;
			if (nb == ctx->hs)
				return (cmd_dgst);
		}
	}
	return (NULL);
}