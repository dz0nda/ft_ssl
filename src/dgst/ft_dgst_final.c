#include "ft_dgst.h"

static size_t	ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

int				ft_md5_final(t_dgst_ctx *ctx)
{
	int i;
	int n;
	uint64_t ibits;
	
	i = ctx->len_block;
	n = ft_get_size_aligned(ctx->len_block + 8, 64);
	ibits = ctx->len_input * 8;
	ctx->block[ctx->iblock] = 0x80;
	while (++ctx->iblock < (n - 8))
		ctx->block[ctx->iblock] = 0;
	if (ctx->endian == FT_DGST_ENDIAN_LITTLE)
		ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
		// while (ctx->len_block < n)
		// {
			
		// 	// ctx->block[ctx->len_block++] = ibits % 256;
		// 	// ibits /= 256;
		// }
	else
	{
		ft_memrev(&ibits, sizeof(ibits));
		ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
		// i = ctx->len_block;
		// ctx->len_block = n;
		// while (--n > i)
		// {
		// 	ctx->block[n] = ibits % 256;
		// 	ibits /= 256;
		// }
	}

	printf("\n== Final hexdump == \n");
	hexdump(ctx->block, n);
	return (EXIT_SUCCESS);
}


int			ft_dgst_final(t_dgst_ctx *ctx)
{
	int i;
	int n;
	uint64_t ibits;
	
	i = ctx->len_block;
	n = ft_get_size_aligned(ctx->iblock + 8, 64);
	ibits = ctx->len_input * 8;
	ctx->block[ctx->iblock] = 0x80;
	while (++ctx->iblock < (n - 8))
		ctx->block[ctx->iblock] = 0;
	if (ctx->endian == FT_DGST_ENDIAN_LITTLE)
		ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
		// while (ctx->len_block < n)
		// {
			
		// 	// ctx->block[ctx->len_block++] = ibits % 256;
		// 	// ibits /= 256;
		// }
	else
	{
		ft_memrev(&ibits, sizeof(ibits));
		ft_memcpy(&ctx->block[ctx->iblock], &ibits, sizeof(ibits));
		// i = ctx->len_block;
		// ctx->len_block = n;
		// while (--n > i)
		// {
		// 	ctx->block[n] = ibits % 256;
		// 	ibits /= 256;
		// }
	}

	printf("\n== Final hexdump == \n");
	hexdump(ctx->block, n);
	return (EXIT_SUCCESS);
}
