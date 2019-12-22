/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_update.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 19:36:38 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 19:47:16 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

int     ft_dgst_update_file(t_dgst *dgst, const char *filename, unsigned int outp)
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

int	    ft_dgst_update_string(t_dgst *dgst, const char *arg, unsigned int arg_len)
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