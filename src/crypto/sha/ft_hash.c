/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:11:52 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/07 16:20:47 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

/*
 * Function:  ft_hash_init 
 * --------------------
 *
 *  hash_key: number of the hash version (can cause segfault if not exist)
 *
 *  returns: a t_hash_dist struct with functions pointer
 */

static t_hash_dist		ft_hash_init(int hash_key)
{
	static t_hash_dist hash[FT_HASH_VERSION] = {
		{ FT_MD5, ft_md5_init, ft_md5_transform, ft_md5_final },
		{ FT_SHA1, ft_sha1_init, ft_sha1_transform, ft_sha256_final },
		{ FT_SHA224, ft_sha224_init, ft_sha256_transform, ft_sha256_final },
		{ FT_SHA256, ft_sha256_init, ft_sha256_transform, ft_sha256_final },
		{ FT_SHA384, ft_sha384_init, ft_sha512_transform, ft_sha512_final },
		{ FT_SHA512, ft_sha512_init, ft_sha512_transform, ft_sha512_final },
		{ FT_SHA512224, ft_sha512224_init, ft_sha512_transform, ft_sha512_final },
		{ FT_SHA512256, ft_sha512256_init, ft_sha512_transform, ft_sha512_final }
	};

	return (hash[hash_key]);
}

int				ft_hash_update(t_dgst_ctx *ctx, t_hash_dist hash, char c)
{
	ctx->block[ctx->iblock++] = c;
	// printf(".%c.", c);
	// printf("%c\n", ctx->block[ctx->iblock]);
	if (ctx->iblock == ctx->mbs)
	{
		// printf("hash\n");
		hash.hash(ctx);
	}
	return (EXIT_SUCCESS);
}

int				ft_hash_update_2(t_dgst_ctx *ctx, t_hash_dist hash, uint8_t *msg, unsigned int msg_len)
{
	int i;
	unsigned int 	pad;

	while (msg_len--)
	{
		// printf("msg: %x\n", *msg);
		ctx->block[ctx->iblock++] = *msg++;
		if (ctx->iblock == ctx->mbs)
			hash.hash(ctx);
	}
	// ctx->block[ctx->iblock++] = 0x80;
	// if (ctx->iblock == ctx->mbs)
	// 	hash.hash(ctx);
	// i = ctx->iblock;
	// pad = ft_get_size_aligned(ctx->iblock + ctx->x, ctx->mbs);
	// printf("pad: %d\n", pad);
	// while (i++ < (pad - ctx->x))
	// {
	// 	ctx->block[ctx->iblock++] = 0;
	// 	if (ctx->iblock == ctx->mbs)
	// 		hash.hash(ctx);
	// }
	// printf("i: %d\n", i);
	// ctx->x == FT_DGST_X64 ?
	// 	ft_memcpy(&ctx->block[ctx->iblock], &ctx->len.x_64, sizeof(ctx->len.x_64)) :
	// 	ft_memcpy(&ctx->block[ctx->iblock], &ctx->len.x_32, sizeof(ctx->len.x_32));
	// hash.hash(ctx);
	return (EXIT_SUCCESS);
}

int				ft_hash_pad(t_dgst_ctx *ctx, t_hash_dist hash, uint8_t *msg, unsigned int msg_len)
{
	int i;
	unsigned int 	pad;

	pad = ft_get_size_aligned(msg_len + ctx->x + 1, ctx->mbs);
	// printf("pad: %d\n", pad);
	ctx->msg_len = pad;
	// printf("msg_len: %d\n", ctx->msg_len);
	ctx->msg = (uint8_t *)ft_memalloc(ctx->msg_len);
	ft_memmove(ctx->msg, msg, msg_len);
	ctx->msg[msg_len] = 0x80;
	i = msg_len;
	while (++i < (pad - ctx->x))
		ctx->msg[i] = 0;
	// printf("i: %d\n", i);
	ctx->x == FT_DGST_X64 ?
		ft_memcpy(&ctx->msg[i], &ctx->len.x_64, sizeof(ctx->len.x_64)) :
		ft_memcpy(&ctx->msg[i], &ctx->len.x_32, sizeof(ctx->len.x_32));
	return (EXIT_SUCCESS);
}

char			*ft_hash(int hash_key, uint8_t *msg, unsigned int msg_len, char *md)
{
	t_hash_dist hash;
	t_dgst_ctx 	ctx;
	int i;
	unsigned int 	pad;
	uint8_t *data;

	ft_memset(&hash, 0, sizeof(hash));
	ft_memset(&ctx, 0, sizeof(ctx));
	i = -1;
	hash = ft_hash_init(hash_key);
	hash.init(&ctx, msg_len);
	// printf("msglen: %d\n", ctx.iblock);
	ft_hash_pad(&ctx, hash, msg, msg_len);
	// ft_hash_update_2(&ctx, hash, msg, msg_len);
	// ft_hash_update_2(&ctx, hash, ctx.msg, ctx.msg_len);
	
	data = &ctx.msg[0];
	while (ctx.msg_len--)
	{
		// printf("msg: %x\n", *msg);
		ctx.block[ctx.iblock++] = *data++;
		if (ctx.iblock == ctx.mbs)
		{
			hash.hash(&ctx);
			ctx.iblock = 0;
			ft_memset(ctx.block, 0, sizeof(ctx.block));
		}
	}
	ft_memdel((void *)&ctx.msg);
	hash.final(&ctx, md);
	return (md);
}