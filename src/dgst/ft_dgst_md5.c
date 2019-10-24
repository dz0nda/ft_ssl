#include "ft_dgst.h"

static void			ft_md5_padding_show(char *dpad)
{
	int i;

	i = -1;
	printf("Padding show: \n");
	printf("'%s'\n", dpad);
}

static char		*ft_md5_padding(const unsigned char *d, unsigned long n)
{
	size_t	i;
	uint64_t	ibits;
	char	*dpad;

	i = ft_strlen((const char *)d);
	ibits = i * 8;
	if ((dpad = ft_strnew(n)) == NULL)
		return (NULL);
	ft_strcpy(dpad, (const void *)d);
	dpad[i] = 0x80;
	while (++i < (n - FT_BYTE))
		dpad[i] = 0;
	while (i < n)
	{
		dpad[i++] = ibits % 256;
		ibits /= 256;
	}
	ft_md5_padding_show(dpad);
	hexdump(dpad, n);
	// while (--n > i)
	// {
	// 	dpad[n] = ibits % 255;
	// 	ibits /= 255;
	// }

	// int j = 0;
	// while (i < n)
	// {
	// 	dpad[i++] = libits >> j;
	// 	j += 8;
	// }
	// dpad[i++] = libits >> 56;
	// dpad[i++] = libits >> 48; 
	// dpad[i++] = libits >> 40; 
	// dpad[i++] = libits >> 32; 
	// dpad[i++] = libits >> 24; 
	// dpad[i++] = libits >> 16; 
	// dpad[i++] = libits >> 8; 
	// dpad[i] = libits;
	return (dpad);
}

static void			ft_md5_init_show(t_md5_ctx *ctx)
{
	int i;

	i = -1;
	printf("Init show: \n");
	while (++i < 4)
		printf("hash[%d] = %u ", i, ctx->state[i]);
	printf("\n");
}

int					ft_md5(const unsigned char *d, unsigned long n, unsigned char *md)
{
	char			*dpad;
	unsigned long	nalign;
	t_md5_ctx	ctx;

	dpad = NULL;
	nalign = ft_get_size_aligned((n + FT_BYTE), FT_MODBYTE);
	ft_md5_init(&ctx);
	// ft_init_show(&ctx);
	ft_md5_init_show(&ctx);
	if ((dpad = ft_md5_padding(d, nalign)) == NULL)
		return (NULL);
	ft_md5_update(&ctx, (const void *)dpad, nalign);
	ft_md5_final(&ctx, md);
	ft_strdel(&dpad);
	return (EXIT_SUCCESS);
}
