/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:07:42 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 17:16:19 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"



int 	ft_md5_input(t_md5_ctx *ctx, uint8_t *data, unsigned int data_length)
{
	int	i;

	i = -1;
	while (++i < data_length)
	{
		ctx->block[ctx->iblock++] = data[i];
		ctx->idata++;
		if (ctx->iblock == FT_MD5_MESSAGE_BLOCK_SIZE)
			// hash(&dgst->ctx);
	}
	return EXIT_SUCCESS;
}