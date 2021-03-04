/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udgst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/04 11:13:13 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_udgst.h"

char	*ft_udgst_final(t_udgst *ctx, char *md)
{
	if (ctx->key < FT_SHA1)
		return (ft_md5_final((t_md5_ctx *)&ctx->ctx, md));
	else if (ctx->key < FT_SHA224)
		return (ft_sha1_final((t_sha1_ctx *)&ctx->ctx, md));
	else if (ctx->key < FT_SHA384)
		return (ft_sha256_final((t_sha256_ctx *)&ctx->ctx, md));
	else if (ctx->key < FT_DGST_VERSION)
		return (ft_sha512_final((t_sha512_ctx *)&ctx->ctx, md));
	return (NULL);
}

int		ft_udgst_process(t_udgst *ctx)
{
	if (ctx->key < FT_SHA1)
		return (ft_md5_transform((t_md5_ctx *)&ctx->ctx));
	else if (ctx->key < FT_SHA224)
		return (ft_sha1_transform((t_sha1_ctx *)&ctx->ctx));
	else if (ctx->key < FT_SHA384)
		return (ft_sha256_transform((t_sha256_ctx *)&ctx->ctx));
	else if (ctx->key < FT_DGST_VERSION)
		return (ft_sha512_transform((t_sha512_ctx *)&ctx->ctx));
	return (EXIT_FAILURE);
}

int		ft_udgst_pad(t_udgst *ctx, uint8_t *msg, unsigned int msg_len)
{
	if (ctx->key < FT_SHA1)
		return (ft_md5_pad((t_md5_ctx *)&ctx->ctx, msg, msg_len));
	else if (ctx->key < FT_SHA224)
		return (ft_sha1_pre_process((t_sha1_ctx *)&ctx->ctx, msg, msg_len));
	else if (ctx->key < FT_SHA384)
		return (ft_sha256_pre_process((t_sha256_ctx *)&ctx->ctx, msg, msg_len));
	else if (ctx->key < FT_DGST_VERSION)
		return (ft_sha512_pre_process((t_sha512_ctx *)&ctx->ctx, msg, msg_len));
	return (EXIT_FAILURE);
}

int		ft_udgst_init(t_udgst *ctx)
{
	if (ctx->key == FT_MD5)
		return (ft_md5_init((t_md5_ctx *)&ctx->ctx));
	else if (ctx->key == FT_SHA1)
		return (ft_sha1_init((t_sha1_ctx *)&ctx->ctx));
	else if (ctx->key == FT_SHA224)
		return (ft_sha224_init((t_sha256_ctx *)&ctx->ctx));
	else if (ctx->key == FT_SHA256)
		return (ft_sha256_init((t_sha256_ctx *)&ctx->ctx));
	else if (ctx->key == FT_SHA384)
		return (ft_sha384_init((t_sha512_ctx *)&ctx->ctx));
	else if (ctx->key == FT_SHA512)
		return (ft_sha512_init((t_sha512_ctx *)&ctx->ctx));
	else if (ctx->key == FT_SHA512224)
		return (ft_sha512224_init((t_sha512_ctx *)&ctx->ctx));
	else if (ctx->key == FT_SHA512256)
		return (ft_sha512256_init((t_sha512_ctx *)&ctx->ctx));
	return (EXIT_FAILURE);
}

char	*ft_udgst(int key, uint8_t *msg, unsigned int msg_len, char *md)
{
	t_udgst		ctx;

	ft_memset(&ctx, 0, sizeof(ctx));
	ctx.key = key;
	ft_udgst_init(&ctx);
	ft_udgst_pad(&ctx, msg, msg_len);
	ft_udgst_process(&ctx);
	ft_udgst_final(&ctx, md);
	return (md);
}
