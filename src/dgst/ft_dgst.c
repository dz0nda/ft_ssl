/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:07:28 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 16:17:20 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

int		ft_dgst_init(t_dgst *dgst, int cmd_key)
{
	const t_dgst dgst_dist[FT_DGST_DIST] = {
        { 
            FT_MD5, 
            { FT_MD5_HS, FT_MD5_MBS, FT_DGST_ENDIAN_LITTLE, FT_MD5_STATE },
            { ft_md5_init, ft_md5_transform, ft_md5_final, ft_dgst_result32 }
        },
        {
            FT_SHA1,
            { FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_ENDIAN_BIG, FT_SHA1_STATE },
            { ft_sha1_init, ft_sha1_transform, ft_sha1_final, ft_dgst_result32 }
        },
        {
            FT_SHA256,
            { FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_ENDIAN_BIG, FT_SHA256_STATE },
            { ft_sha256_init, ft_sha256_transform, ft_sha1_final, ft_dgst_result32}
        },
        {
            FT_SHA384,
            { FT_SHA384_HS, FT_SHA384_MBS, FT_DGST_ENDIAN_BIG, FT_SHA384_STATE },
            { ft_sha384_init, ft_sha512_transform, ft_sha512_final, ft_dgst_result64 }
        },
        {
            FT_SHA512,
            { FT_SHA512_HS, FT_SHA512_MBS, FT_DGST_ENDIAN_BIG, FT_SHA512_STATE },
            { ft_sha512_init, ft_sha512_transform, ft_sha512_final, ft_dgst_result64 }
        } 
    };
    int i;

    i = -1;
	while (++i < FT_DGST_DIST)
		if (cmd_key == dgst_dist[i].dist_enum)
			break;
    if (i == FT_DGST_DIST)
        printf("not found\n");
	ft_memcpy(dgst, &dgst_dist[i], sizeof(*dgst));
    return (EXIT_SUCCESS);
}

int		ft_dgst_string(t_dgst *dgst, char *data, size_t len)
{
	t_dgst_dist *dist;
	t_dgst_ctx 	*ctx;

	dist = &dgst->dist;
	ctx = &dgst->ctx;
	while (ctx->idata < len)
	{
		ctx->block[ctx->iblock++] = data[ctx->idata++];
		if (ctx->iblock == ctx->len_mbs)
		{
			dist->transform(ctx);
			ctx->iblock = 0;
		}
	}
    return (EXIT_SUCCESS);
}


int		ft_dgst_file(t_dgst *dgst, char *filename)
{
	t_dgst_dist *dist;
	t_dgst_ctx 	*ctx;
	int fd;

	dist = &dgst->dist;
	ctx = &dgst->ctx;
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

char     *ft_dgst(int cmd_key, char *cmd_arg, int cmd_arg_len, char *cmd_dgst)
{
    t_dgst  dgst;

    ft_memset(&dgst, 0, sizeof(dgst));
    ft_dgst_init(&dgst, cmd_key);
    // if (dgst.dist.init == NULL)
    //     printf("not\n");
    dgst.dist.init(&dgst.ctx);
    if (cmd_arg_len == 0)
        ft_dgst_file(&dgst, cmd_arg);
    else
        ft_dgst_string(&dgst, cmd_arg, cmd_arg_len);
    dgst.dist.final(&dgst.ctx);
    dgst.dist.result(&dgst.ctx, cmd_dgst);
    return (cmd_dgst);
}

// int		ft_ssl_dgst_mdsha_init(t_dgst *dgst)
// {
// 	ft_memset(&dgst->dist.ctx.state, 0, sizeof(dgst->dist.ctx.state));
// 	ft_memset(dgst->dist.ctx.block, 0, sizeof(dgst->dist.ctx.block));
// 	ft_memset(dgst->dist.ctx.dgst, 0, sizeof(dgst->dist.ctx.dgst));
// 	dgst->dist.init(&dgst->dist.ctx);
// }

// int		ft_ssl_dgst_mdsha_update(t_dgst *dgst, char *data, size_t len)
// {
	
// }



// int     ft_ssl_dgst_mdsha_2(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *cmd_dgst)
// {
// 	t_ftssl_dgst_ctx ctx;
	
// 	ft_memset(&ctx, 0, sizeof(ctx));
// 	ft_ssl_dgst_init_ctx(&ctx, cmd_name);
// 	ctx.dgst_dist.init(&ctx.dgst_ctx);
// 	if (cmd_arg_len == 0)
// 		ft_ssl_dgst_mdsha_update_file(dgst, data);
// 	else
// 		ft_ssl_dgst_mdsha_update_string(dgst, data, len);
	
//     return (EXIT_SUCCESS);
// }

// int		ft_ssl_dgst_mdsha(t_dgst *dgst, char *data, size_t len)
// {
// 	int i;
// 	t_dgst_dist *dist;
// 	t_dgst_ctx 	*ctx;

// 	i = -1;
// 	dist = &dgst->dist;
// 	ctx = &dgst->dist.ctx;

// 	dist->init(ctx);
// 	if (len == 0)
// 		ft_ssl_dgst_mdsha_update_file(dgst, data);
// 	else
// 		ft_ssl_dgst_mdsha_update_string(dgst, data, len);
// 	dist->final(ctx);
// 	dgst->output(dgst, data, len);
// }