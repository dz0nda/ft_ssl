/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_string.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 09:55:35 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 10:00:55 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

static int	ft_dgst_update_string(t_dgst *dgst, const char *arg, unsigned int arg_len)
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