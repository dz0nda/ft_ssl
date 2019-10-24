#include "ft_dgst.h"

static void			ft_sha1_padding_show(char *dpad)
{
	int i;

	i = -1;
	printf("Padding show: \n");
	printf("'%s'\n", dpad);
}

char		*ft_sha1_padding(const unsigned char *d, unsigned long n)
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
    // ibits = swap_uint64(ibits);

	// {
	// 	dpad[i++] = ibits % 256;
	// 	ibits /= 256;
	// }
    // ibits = swap_uint64(ibits);
	// dpad[i++] = ibits >> 56;
	// dpad[i++] = ibits >> 48; 
	// dpad[i++] = ibits >> 40; 
	// dpad[i++] = ibits >> 32; 
	// dpad[i++] = ibits >> 24; 
	// dpad[i++] = ibits >> 16; 
	// dpad[i++] = ibits >> 8; 
	// dpad[i] = ibits;
	while (--n > i)
	{
		dpad[n] = ibits % 255;
		ibits /= 255;
	}
	hexdump(dpad, n + 8);
	ft_sha1_padding_show(dpad);
	return (dpad);
}


static void			ft_sha1_init_show(t_sha1_ctx *ctx)
{
	int i;

	i = -1;
	printf("Init show: \n");
	while (++i < 5)
		printf("hash[%d] = %u ", i, ctx->state[i]);
	printf("\n");
}

int			ft_sha1(const unsigned char *d, unsigned long n, unsigned char *md)
{
	char					*dpad;
	unsigned long		nalign;
	t_sha1_ctx	ctx;

	dpad = NULL;
	nalign = ft_get_size_aligned((n + FT_BYTE), FT_MODBYTE);
	ft_sha1_init(&ctx);
	ft_sha1_init_show(&ctx);
	if ((dpad = ft_sha1_padding(d, nalign)) == NULL)
		return (NULL);
	ft_sha1_update(&ctx, (const void *)dpad, nalign);
	ft_sha1_final(&ctx, md);
	// ft_strdel(&dpad);
	return (md);
}
