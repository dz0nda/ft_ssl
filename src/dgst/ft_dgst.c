/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:07:28 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 16:13:04 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

unsigned int		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

char		*ft_dgst_file(int cmd_key, char *filename, int outp,
		char *cmd_dgst)
{
	int		fd;
	t_dgst	dgst;

	fd = 0;
	ft_memset(&dgst, 0, sizeof(dgst));
	ft_dgst_init(&dgst, cmd_key);
	// dgst.dist.init(&dgst.ctx);
	if (filename != NULL && (fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while ((dgst.ctx.iblock = read(fd, dgst.ctx.block, dgst.ctx.mbs)) ==
			dgst.ctx.mbs)
	{
		dgst.ctx.idata += dgst.ctx.iblock;
		dgst.dist.transform(&dgst.ctx);
		if (outp == FT_SSL_TRUE)
			ft_putstr((const char *)dgst.ctx.block);
		ft_memset(dgst.ctx.block, 0, sizeof(dgst.ctx.block));
	}
	if (filename != NULL)
		close(fd);
	if (outp == FT_SSL_TRUE)
		ft_putstr((const char *)dgst.ctx.block);
	dgst.ctx.idata += dgst.ctx.iblock;
	dgst.dist.final(&dgst.ctx);
	dgst.dist.result(&dgst.ctx, cmd_dgst);
	return (cmd_dgst);
}

char		*ft_dgst_string(int cmd_key, char *cmd_arg, unsigned int cmd_arg_len,
		char *cmd_dgst)
{
	t_dgst	dgst;

	ft_memset(&dgst, 0, sizeof(dgst));
	ft_dgst_init(&dgst, cmd_key);
	// dgst.dist.init(&dgst.ctx);
	while (dgst.ctx.idata < cmd_arg_len)
	{
		dgst.ctx.block[dgst.ctx.iblock++] = cmd_arg[dgst.ctx.idata++];
		if (dgst.ctx.iblock == dgst.ctx.mbs)
		{
			dgst.dist.transform(&dgst.ctx);
			dgst.ctx.iblock = 0;
		}
	}
	dgst.dist.final(&dgst.ctx);
	dgst.dist.result(&dgst.ctx, cmd_dgst);
	return(cmd_dgst);
}

int		ft_dgst_update_file(t_dgst *dgst, const char *filename, unsigned int outp)
{
	int fd;

	fd = 0;
	if (filename != NULL && (fd = open(filename, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	while ((dgst->ctx.iblock = read(fd, dgst->ctx.block, dgst->ctx.mbs))
			== dgst->ctx.mbs)
	{
		dgst->ctx.idata += dgst->ctx.iblock;
		dgst->dist.transform(&dgst->ctx);
		if (outp == FT_SSL_TRUE)
			ft_putstr((const char *)dgst->ctx.block);
		ft_memset(dgst->ctx.block, 0, sizeof(dgst->ctx.block));
	}
	if (filename != NULL)
		close(fd);
	if (outp == FT_SSL_TRUE)
		ft_putstr((const char *)dgst->ctx.block);
	dgst->ctx.idata += dgst->ctx.iblock;
	return (EXIT_SUCCESS);
}

int		ft_dgst_update_string(t_dgst *dgst, const char *arg, unsigned int arg_len)
{
	while (dgst->ctx.idata < arg_len)
	{
		dgst->ctx.block[dgst->ctx.iblock++] = arg[dgst->ctx.idata++];
		if (dgst->ctx.iblock == dgst->ctx.mbs)
		{
			dgst->dist.transform(&dgst->ctx);
			dgst->ctx.iblock = 0;
		}
	}
	return (EXIT_SUCCESS);
}

int			ft_dgst_pad(t_dgst_ctx *ctx)
{
	unsigned int i;
	unsigned int pad;

	i = ctx->iblock;
	pad = ft_get_size_aligned(ctx->iblock + ctx->x, ctx->mbs);
	ctx->block[ctx->iblock++] = 0x80;
	while (++i < (pad - ctx->x))
	{
		if (ctx->iblock == ctx->mbs)
			break ;
		ctx->block[ctx->iblock++] = 0;
	}
	return (EXIT_SUCCESS);
}



char 	*ft_dgst(int dist, const char *arg, unsigned int arg_len, char *md)
{
	t_dgst	dgst;

	ft_memset(&dgst, 0, sizeof(dgst));
	ft_dgst_init(&dgst, dist);
	if (arg == NULL)
		ft_dgst_update_file(&dgst, arg, arg_len);
	else
		ft_dgst_update_string(&dgst, arg, arg_len);
	dgst.dist.final(&dgst.ctx);
	dgst.dist.result(&dgst.ctx, md);
	return (md);
}