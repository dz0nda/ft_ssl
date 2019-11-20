/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_file.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 09:53:28 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 09:55:00 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

static int  ft_dgst_update_file(t_dgst *dgst, const char *filename, unsigned int outp)
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

char		*ft_dgst_file(int cmd_key, char *filename, int outp,
		char *md)
{
	int		fd;
	t_dgst	dgst;

	fd = 0;
	ft_memset(&dgst, 0, sizeof(dgst));
	ft_dgst_init(&dgst, cmd_key);
	ft_dgst_update_file(&dgst, filename, outp);
	ft_dgst_pad(&dgst.ctx);
	if (dgst.ctx.iblock == dgst.ctx.mbs)
	{
		dgst.dist.transform(&dgst.ctx);
		dgst.ctx.iblock = 0;
		ft_memset(&dgst.ctx.block, 0, sizeof(dgst.ctx.block));
	}
	ft_dgst_finalize(&dgst.ctx);
	dgst.dist.transform(&dgst.ctx);
	ft_dgst_result(&dgst.ctx, md);
	return (md);
}
