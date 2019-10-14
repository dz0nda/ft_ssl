#include "ft_md5.h"

static void			ft_md5_init_show(t_ftmd5ctx *ctx)
{
	int i;

	i = -1;
	printf("Init show: \n");
	while (++i < 4)
		printf("hash[%d] = %u ", i, ctx->hash[i]);
	printf("\n");
}

static int			ft_md5_init(t_ftmd5ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_ftmd5ctx));
	ctx->hash[0] = 0x67452301;
	ctx->hash[1] = 0xefcdab89;
	ctx->hash[2] = 0x98badcfe;
	ctx->hash[3] = 0x10325476;
	return (EXIT_SUCCESS);
}

unsigned char		*ft_md5(const unsigned char *d, unsigned long n, unsigned char *md)
{
	char			*dpad;
	unsigned long	nalign;
	t_ftmd5ctx	ctx;

	dpad = NULL;
	nalign = ft_get_size_aligned((n + FT_MD5_BYTE), FT_MD5_MODBYTE);
	ft_md5_init(&ctx);
	ft_md5_init_show(&ctx);
	if ((dpad = ft_md5_padding(d, nalign)) == NULL)
		return (NULL);
	ft_md5_update(&ctx, (const void *)dpad, nalign);
	ft_md5_final(&ctx, md);
	ft_strdel(&dpad);
	return (md);
}
