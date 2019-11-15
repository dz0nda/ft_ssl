/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:07:28 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 09:33:57 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

size_t		ft_get_size_aligned(size_t offset, size_t align)
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
	dgst.dist.init(&dgst.ctx);
	if (filename != NULL && (fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while ((dgst.ctx.iblock = read(fd, dgst.ctx.block, dgst.ctx.len_mbs)) ==
			dgst.ctx.len_mbs)
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

char		*ft_dgst_string(int cmd_key, char *cmd_arg, int cmd_arg_len,
		char *cmd_dgst)
{
	t_dgst	dgst;

	ft_memset(&dgst, 0, sizeof(dgst));
	ft_dgst_init(&dgst, cmd_key);
	dgst.dist.init(&dgst.ctx);
	while (dgst.ctx.idata < cmd_arg_len)
	{
		dgst.ctx.block[dgst.ctx.iblock++] = cmd_arg[dgst.ctx.idata++];
		if (dgst.ctx.iblock == dgst.ctx.len_mbs)
		{
			dgst.dist.transform(&dgst.ctx);
			dgst.ctx.iblock = 0;
		}
	}
	dgst.dist.final(&dgst.ctx);
	dgst.dist.result(&dgst.ctx, cmd_dgst);
	return(cmd_dgst);
}
