/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgst_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:36:38 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/29 16:00:47 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_dgst.h"

int 	ft_dgst_input(t_dgst *dgst, uint8_t *msg, unsigned int msg_len)
{
	int	i;
	t_dgst_ctx *ctx;

	i = -1;
	ctx = &dgst->ctx;
	while (++i < msg_len)
	{
		dgst->ctx.block[dgst->ctx.iblock++] = msg[i];
		ctx->idata++;
		if (dgst->ctx.iblock == dgst->ctx.mbs)
			dgst->dist.transform(&dgst->ctx);
	}
	return EXIT_SUCCESS;
}

int     ft_dgst_input_file(t_dgst *dgst, const char *filename, unsigned int outp)
{
	int fd;
	char buf[4096];
	int  nbuf = 0;

	fd = 0;
	ft_memset(buf, 0, sizeof(buf));
	if (filename != NULL && (fd = open(filename, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	while ((nbuf = read(fd, buf, dgst->ctx.mbs)) > 0)
	{
		ft_dgst_input(dgst, buf, nbuf);
		if (outp == FT_SSL_TRUE)
			ft_putstr(buf);
		ft_memset(buf, 0, sizeof(buf));
	}
	if (filename != NULL)
		close(fd);
	return (EXIT_SUCCESS);
}