/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_addlen.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 09:14:56 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 16:58:17 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

int			ft_dgst_addlength_32(t_dgst_ctx *ctx)
{
	uint64_t ibits;
	
	ibits = ctx->idata * 8;
	if (ctx->endian == FT_DGST_ENDIAN_BIG)
		ft_memrev(&ibits, sizeof(ibits));
	ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
	return (EXIT_SUCCESS);
}

int			ft_dgst_addlength_64(t_dgst_ctx *ctx)
{
	__uint128_t ibits;
	
	ibits = ctx->idata * 8;
	if (ctx->endian == FT_DGST_ENDIAN_BIG)
		ft_memrev(&ibits, sizeof(ibits));
	ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
	return (EXIT_SUCCESS);
}
