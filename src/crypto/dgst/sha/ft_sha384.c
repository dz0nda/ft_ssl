/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha384.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:19:12 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/04 14:15:43 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

int		ft_sha384_init(t_sha512_ctx *ctx)
{
	ctx->hash_size = FT_SHA384_HASH_SIZE;
	ctx->msg_block_size = FT_SHA384_MSG_BLOCK_SIZE;
	ctx->state_len = FT_SHA384_STATE;
	ctx->state[0] = 0xcbbb9d5dc1059ed8;
	ctx->state[1] = 0x629a292a367cd507;
	ctx->state[2] = 0x9159015a3070dd17;
	ctx->state[3] = 0x152fecd8f70e5939;
	ctx->state[4] = 0x67332667ffc00b31;
	ctx->state[5] = 0x8eb44a8768581511;
	ctx->state[6] = 0xdb0c2e0d64f98fa7;
	ctx->state[7] = 0x47b5481dbefa4fa4;
	return (EXIT_SUCCESS);
}

int		ft_sha384_pre_process(t_sha512_ctx *ctx, uint8_t *msg,
	unsigned int msg_len)
{
	return (ft_sha512_pre_process(ctx, msg, msg_len));
}

int		ft_sha384_transform(t_sha512_ctx *ctx)
{
	return (ft_sha512_process(ctx));
}

char	*ft_sha384_final(t_sha512_ctx *ctx, char *cmd_dgst)
{
	return (ft_sha512_final(ctx, cmd_dgst));
}
