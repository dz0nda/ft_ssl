/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/11 18:43:17 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ssl_dgst.h"

int     ft_ssl_dgst_dist(int argc, char *argv[], t_ftssl_dgst *ftssl_dgst)
{
		static t_ftssl_dgst_dist	g_ftssl_dgst_dist[FT_DGST_VERSION] = {
			{ FT_MD5, "md5", ft_md5_init, ft_sha256_pre_process, ft_md5_transform,
				ft_md5_final },
			{ FT_SHA1, "sha1", ft_sha1_init, ft_sha256_pre_process, ft_sha1_transform,
				ft_sha256_final },
			{ FT_SHA224, "sha224", ft_sha224_init, ft_sha256_pre_process,
				ft_sha256_transform, 	ft_sha256_final },
			{ FT_SHA256, "sha256", ft_sha256_init, ft_sha256_pre_process,
				ft_sha256_transform,	ft_sha256_final },
			{ FT_SHA384, "sha384", ft_sha384_init, ft_sha512_pre_process,
				ft_sha512_transform, 	ft_sha512_final },
			{ FT_SHA512, "sha512", ft_sha512_init, ft_sha512_pre_process,
			ft_sha512_transform, ft_sha512_final },
			{ FT_SHA512224, "sha512224", ft_sha512224_init, ft_sha512_pre_process,
				ft_sha512_transform, 	ft_sha512_final },
			{ FT_SHA512256, "sha512256", ft_sha512256_init, ft_sha512_pre_process,
			ft_sha512_transform, 	ft_sha512_final }
		};
    int cmd_key;

    cmd_key = -1;
    if (argc != -42 && ft_strequ(argv[0], ""))
        return (FT_SSL_DGST_NOT_FOUND);
    while (++cmd_key < FT_DGST_VERSION)
    {
        if (argc == -42)
            ft_putendl_fd(g_ftssl_dgst_dist[cmd_key].name, STDERR_FILENO);
        else if (ft_strequ(argv[0], g_ftssl_dgst_dist[cmd_key].name))
        {
            // ftssl_dgst->dist.key = cmd_key;
            // ftssl_dgst->dist.name = g_ftssl_dgst_dist[cmd_key].dist_name;
            ftssl_dgst->dist = g_ftssl_dgst_dist[cmd_key];
            // ftssl_dgst->args.argc = argc - 1;
	        	// ftssl_dgst->args.argv = argv + 1;
            return (cmd_key);
        }
    }
    return (FT_SSL_DGST_NOT_FOUND);
}
// t_ftssl_dgst_dist   g_ftssl_dgst_dist[FT_DGST_VERSION] = {
//     { "md5", 	    FT_MD5      },
//     { "sha1", 	    FT_SHA1     },
//     { "sha224",     FT_SHA224   },
//     { "sha256",     FT_SHA256   },
//     { "sha384",     FT_SHA384   },
//     { "sha512",     FT_SHA512   },
//     { "sha512224",  FT_SHA512224 },
//     { "sha512256",  FT_SHA512256 }
// };

// t_ftssl_dgst_dist   g_ftssl_dgst_dist[FT_DGST_VERSION] = {
// 	{ FT_MD5, 			"md5", ft_md5_init, ft_sha256_pre_process, ft_md5_transform, 		ft_md5_final },
// 	{ FT_SHA1, 			"sha1", ft_sha1_init, ft_sha256_pre_process, 			ft_sha1_transform, 		ft_sha256_final },
// 	{ FT_SHA224, 		"sha224", ft_sha224_init,ft_sha256_pre_process, 		ft_sha256_transform, 	ft_sha256_final },
// 	{ FT_SHA256, 		"sha256", ft_sha256_init, ft_sha256_pre_process, 		ft_sha256_transform,	ft_sha256_final },
// 	{ FT_SHA384, 		"sha384", ft_sha384_init, ft_sha512_pre_process,		ft_sha512_transform, 	ft_sha512_final },
// 	{ FT_SHA512, 		"sha512", ft_sha512_init, ft_sha512_pre_process,			ft_sha512_transform, 	ft_sha512_final },
// 	{ FT_SHA512224, "sha512224", ft_sha512224_init, ft_sha512_pre_process, 	ft_sha512_transform, 	ft_sha512_final },
// 	{ FT_SHA512256, "sha512256", ft_sha512256_init, ft_sha512_pre_process,	ft_sha512_transform, 	ft_sha512_final }
// };



// static t_hash_dist		ft_hash_init(int hash_key)
// {
// 	static t_hash_dist hash[FT_DGST_VERSION] = {
// 		{ FT_MD5, 			ft_md5_init, 				ft_md5_transform, 		ft_md5_final },
// 		{ FT_SHA1, 			ft_sha1_init, 			ft_sha1_transform, 		ft_sha256_final },
// 		{ FT_SHA224, 		ft_sha224_init, 		ft_sha256_transform, 	ft_sha256_final },
// 		{ FT_SHA256, 		ft_sha256_init, 		ft_sha256_transform,	ft_sha256_final },
// 		{ FT_SHA384, 		ft_sha384_init, 		ft_sha512_transform, 	ft_sha512_final },
// 		{ FT_SHA512, 		ft_sha512_init,			ft_sha512_transform, 	ft_sha512_final },
// 		{ FT_SHA512224, ft_sha512224_init, 	ft_sha512_transform, 	ft_sha512_final },
// 		{ FT_SHA512256, ft_sha512256_init, 	ft_sha512_transform, 	ft_sha512_final }
// 	};

// 	return (hash[hash_key]);
// }

// int				ft_hash_pad(t_dgst_ctx *ctx, uint8_t *msg, unsigned int msg_len)
// {
// 	int i;
// 	unsigned int 	pad;

// 	pad = ft_align_bits(msg_len + ctx->x + 1, ctx->mbs);
// 	// printf("pad: %d\n", pad);
// 	ctx->msg_len = pad;
// 	// printf("msg_len: %d\n", ctx->msg_len);
// 	ctx->msg = (uint8_t *)ft_memalloc(ctx->msg_len);
// 	ft_memmove(ctx->msg, msg, msg_len);
// 	ctx->msg[msg_len] = 0x80;
// 	i = msg_len;
// 	while (++i < (pad - ctx->x))
// 		ctx->msg[i] = 0;
// 	// printf("i: %d\n", i);
// 	ctx->x == FT_DGST_X64 ?
// 		ft_memcpy(&ctx->msg[i], &ctx->len.x_64, sizeof(ctx->len.x_64)) :
// 		ft_memcpy(&ctx->msg[i], &ctx->len.x_32, sizeof(ctx->len.x_32));
// 	return (EXIT_SUCCESS);
// }

char     *ft_ssl_dgst_dist_execute(uint8_t *msg, unsigned int msg_len, char *md, t_ftssl_dgst *ftssl_dgst)
{
	t_dgst_ctx 	ctx;
	int i;
	uint8_t *data;

	ft_memset(&ctx, 0, sizeof(ctx));
	i = -1;
	// hash = ft_hash_init(hash_key);
	// hash.init(&ctx, msg_len);
	ftssl_dgst->dist.init(&ctx, msg_len);
	ftssl_dgst->dist.pre_process(&ctx, msg, msg_len);
	data = &ctx.msg[0];
	while (ctx.msg_len--)
	{
		ctx.block[ctx.iblock++] = *data++;
		if (ctx.iblock == ctx.mbs)
		{
			// hash.hash(&ctx);
			ftssl_dgst->dist.hash(&ctx);
			ctx.iblock = 0;
			ft_memset(ctx.block, 0, sizeof(ctx.block));
		}
	}
	ft_memdel((void *)&ctx.msg);
	// hash.final(&ctx, md);
	ftssl_dgst->dist.final(&ctx, md);
	return (md);
}