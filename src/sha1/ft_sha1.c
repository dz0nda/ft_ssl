#include "ft_sha1.h"
#include <stdio.h>

static void			ft_sha1_init_show(t_sha1_ctx *ctx)
{
	int i;

	i = -1;
	printf("Init show: \n");
	while (++i < 5)
		printf("hash[%d] = %u ", i, ctx->state[i]);
	printf("\n");
}

static int			ft_sha1_init(t_sha1_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_sha1_ctx));
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xEFCDAB89;
	ctx->state[2] = 0x98BADCFE;
	ctx->state[3] = 0x10325476;
	ctx->state[4] = 0xC3D2E1F0;
	return (EXIT_SUCCESS);
}

int			ft_sha1(const unsigned char *d, unsigned long n, unsigned char *md)
{
	char					*dpad;
	unsigned long		nalign;
	t_sha1_ctx	ctx;

	dpad = NULL;
	nalign = ft_get_size_aligned((n + FT_SHA1_BYTE), FT_SHA1_MODBYTE);
	ft_sha1_init(&ctx);
	ft_sha1_init_show(&ctx);
	if ((dpad = ft_sha1_padding(d, nalign)) == NULL)
		return (NULL);
	ft_sha1_update(&ctx, (const void *)dpad, nalign);
	ft_sha1_final(&ctx, md);
	// ft_strdel(&dpad);
	return (md);
}
