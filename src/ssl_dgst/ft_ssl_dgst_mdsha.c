/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_mdsha.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 04:42:44 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 21:51:31 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_mdsha_update_file(t_dgst *dgst, char *filename)
{
	t_dgst_dist *dist;
	t_dgst_ctx 	*ctx;
	int fd;

	dist = &dgst->dist;
	ctx = &dist->ctx;
	if (filename == NULL)
		fd = 0;
	else if (access(filename, F_OK) == -1 || (fd = open(filename, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	while ((ctx->iblock = read(fd, ctx->block, ctx->len_mbs)) == ctx->len_mbs)
	{
		ctx->idata += ctx->iblock;
		dist->transform(ctx);
		ft_memset(ctx->block, 0, sizeof(ctx->block));
	}
	ctx->idata += ctx->iblock;
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_mdsha_update_string(t_dgst *dgst, char *data, size_t len)
{
	t_dgst_dist *dist;
	t_dgst_ctx 	*ctx;

	dist = &dgst->dist;
	ctx = &dist->ctx;
	while (ctx->idata < len)
	{
		ctx->block[ctx->iblock++] = data[ctx->idata++];
		if (ctx->iblock == ctx->len_mbs)
		{
			dist->transform(ctx);
			ctx->iblock = 0;
		}
	}
}

int		ft_ssl_dgst_mdsha_init(t_dgst *dgst)
{
	ft_memset(&dgst->dist.ctx.state, 0, sizeof(dgst->dist.ctx.state));
	ft_memset(dgst->dist.ctx.block, 0, sizeof(dgst->dist.ctx.block));
	ft_memset(dgst->dist.ctx.dgst, 0, sizeof(dgst->dist.ctx.dgst));
	dgst->dist.init(&dgst->dist.ctx);
}

int		ft_ssl_dgst_mdsha_update(t_dgst *dgst, char *data, size_t len)
{
	
}

int		ft_ssl_dgst_init_ctx(t_ftssl_dgst_ctx *ftssl_dgst_ctx, const char *cmd_name)
{
	const t_ftssl_dgst_dist_t dist[FT_DGST_DIST] = {
        { 
            FT_MD5, "md5", 
            { { FT_MD5_HS, FT_MD5_MBS, FT_DGST_ENDIAN_LITTLE, FT_MD5_STATE },
            ft_md5_init, ft_md5_transform, ft_md5_final }
        },
        {
            FT_SHA1, "sha1",
            { { FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_ENDIAN_BIG, FT_SHA1_STATE },
            ft_sha1_init, ft_sha1_transform, ft_sha1_final }
        },
        {
            FT_SHA256, "sha256",
            { { FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_ENDIAN_BIG, FT_SHA256_STATE },
            ft_sha256_init, ft_sha256_transform, ft_sha1_final }
        },
        {
            FT_SHA384, "sha384",
            { { FT_SHA384_HS, FT_SHA384_MBS, FT_DGST_ENDIAN_BIG, FT_SHA384_STATE },
            ft_sha384_init, ft_sha512_transform, ft_sha512_final }
        },
        {
            FT_SHA512, "sha512",
            { { FT_SHA512_HS, FT_SHA512_MBS, FT_DGST_ENDIAN_BIG, FT_SHA512_STATE },
            ft_sha512_init, ft_sha512_transform, ft_sha512_final }
        } 
    };
    int i;

    i = -1;
	while (++i < FT_DGST_DIST && cmd_name != NULL)
		if (ft_strcmp(dist[i].cmd_name, cmd_name) == 0)
			break;
	ft_memcpy(&ftssl_dgst_ctx, &dist[i].cmd_ctx, sizeof(ftssl_dgst_ctx));
    return (EXIT_SUCCESS);
}

int     ft_ssl_dgst_mdsha_2(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *cmd_dgst)
{
	t_ftssl_dgst_ctx ctx;
	
	ft_memset(&ctx, 0, sizeof(ctx));
	ft_ssl_dgst_init_ctx(&ctx, cmd_name);
	ctx.dgst_dist.init(&ctx.dgst_ctx);
	if (cmd_arg_len == 0)
		ft_ssl_dgst_mdsha_update_file(dgst, data);
	else
		ft_ssl_dgst_mdsha_update_string(dgst, data, len);
	
    return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_mdsha(t_dgst *dgst, char *data, size_t len)
{
	int i;
	t_dgst_dist *dist;
	t_dgst_ctx 	*ctx;

	i = -1;
	dist = &dgst->dist;
	ctx = &dgst->dist.ctx;

	dist->init(ctx);
	if (len == 0)
		ft_ssl_dgst_mdsha_update_file(dgst, data);
	else
		ft_ssl_dgst_mdsha_update_string(dgst, data, len);
	dist->final(ctx);
	dgst->output(dgst, data, len);
}