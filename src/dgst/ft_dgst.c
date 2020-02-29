/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:07:28 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/29 21:51:56 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_dgst.h"

char	*ft_dgst(int dgst_key, char *arg, int arg_type, char *md, int outp)
{
	t_dgst	dgst;

	ft_memset(&dgst, 0, sizeof(dgst));
	ft_dgst_init(&dgst, dgst_key);
	if (arg_type == FT_DGST_STRING)
		ft_dgst_input(&dgst, (uint8_t *)arg, ft_strlen(arg));
	else
		ft_dgst_input_file(&dgst, arg, outp);
	ft_dgst_pad(&dgst);
	ft_dgst_finalize(&dgst);
	// ft_dgst_pad(&dgst);
	// if (dgst.ctx.x == FT_DGST_X64)
	// 	ft_dgst_finalize_x64(&dgst);
	// else
	// 	ft_dgst_finalize_x32(&dgst);
		ft_dgst_result(&dgst.ctx, md);
	return (md);
}