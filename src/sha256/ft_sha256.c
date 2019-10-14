#include "ft_sha256.h"
#include <stdio.h>

static int			ft_sha256_init(t_sha256_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_sha256_ctx));
	ctx->hash[0] = 0x6a09e667;
	ctx->hash[1] = 0xbb67ae85;
	ctx->hash[2] = 0x3c6ef372;
	ctx->hash[3] = 0xa54ff53a;
	ctx->hash[4] = 0x510e527f;
	ctx->hash[5] = 0x9b05688c;
	ctx->hash[6] = 0x1f83d9ab;
	ctx->hash[7] = 0x5be0cd19;
	return (EXIT_SUCCESS);
}

unsigned char		*ft_sha256(const unsigned char *d, unsigned long n, unsigned char *md)
{
	char					*dpad;
	unsigned long		nalign;
	t_sha256_ctx	ctx;

	dpad = NULL;
	nalign = ft_get_size_aligned((n + FT_SHA256_BYTE), FT_SHA256_MODBYTE);
	ft_sha256_init(&ctx);
    printf("nalign = %d\n", nalign);
	if ((dpad = ft_sha256_padding(d, nalign)) == NULL)
		return (NULL);
	// hexdump(dpad, nalign);
	ft_sha256_update(&ctx, (const void *)dpad, nalign);
	ft_sha256_final(&ctx, md);
	// ft_strdel(&dpad);
	return (md);
}
