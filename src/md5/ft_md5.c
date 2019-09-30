#include "ft_md5.h"

static int			ft_md5_init(t_ft_md5_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_ft_md5_ctx));
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xefcdab89;
	ctx->state[2] = 0x98badcfe;
	ctx->state[3] = 0x10325476;
	return (EXIT_SUCCESS);
}

unsigned char		*ft_md5(const unsigned char *d, unsigned long n, unsigned char *md)
{
	char			*dpad;
	unsigned long	nalign;
	t_ft_md5_ctx	ctx;

	dpad = NULL;
	nalign = ft_get_size_aligned((n + FT_MD5_BYTE), FT_MD5_MODBYTE);
	ft_md5_init(&ctx);
	if ((dpad = ft_md5_padding(d, nalign)) == NULL)
		return (NULL);
	ft_md5_update(&ctx, (const void *)dpad, nalign);
	ft_md5_final(&ctx, md);
	ft_strdel(&dpad);
	return (md);
}
