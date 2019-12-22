/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:07:28 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 19:47:38 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

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

char 	*ft_dgst_string(int dist, char *arg, unsigned int arg_len, char *md)
{
	t_dgst	dgst;

	ft_memset(&dgst, 0, sizeof(dgst));
	ft_dgst_init(&dgst, dist);
	ft_dgst_update_string(&dgst, arg, arg_len);
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