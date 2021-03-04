/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/23 23:09:01 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

int			ft_sha224_init(t_sha256_ctx *ctx, unsigned int msg_len)
{
	ctx->hs = FT_SHA224_HS;
	ctx->mbs = FT_SHA224_MBS;
	ctx->state_len = FT_SHA224_STATE;
	ctx->state[0] = 0xc1059ed8;
	ctx->state[1] = 0x367cd507;
	ctx->state[2] = 0x3070dd17;
	ctx->state[3] = 0xf70e5939;
	ctx->state[4] = 0xffc00b31;
	ctx->state[5] = 0x68581511;
	ctx->state[6] = 0x64f98fa7;
	ctx->state[7] = 0xbefa4fa4;
	return (EXIT_SUCCESS);
}

int			ft_sha224_pre_process(t_sha256_ctx *ctx, uint8_t *msg,
	unsigned int msg_len)
{
	return (ft_sha256_pre_process(ctx, msg, msg_len));
}

int			ft_sha224_transform(t_sha256_ctx *ctx)
{
	return (ft_sha256_transform(ctx));
}

char		*ft_sha224_final(t_sha256_ctx *ctx, char *cmd_dgst)
{
	return (ft_sha256_final(ctx, cmd_dgst));
}
