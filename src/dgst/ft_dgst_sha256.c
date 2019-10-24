#include "ft_dgst.h"
static void			ft_sha256_padding_show(char *dpad)
{
	int i;

	i = -1;
	printf("Padding show: \n");
	printf("'%s'\n", dpad);
}

char		*ft_sha256_padding(const unsigned char *d, unsigned long n)
{
	size_t	i;
	size_t	ibits;
	char	*dpad;

	i = ft_strlen((const char *)d);
	ibits = i * 8;
	if ((dpad = ft_strnew(n)) == NULL)
		return (NULL);
	ft_strcpy(dpad, (const void *)d);
	dpad[i] = 0x80;
	while (++i < (n - FT_BYTE))
		dpad[i] = 0;
	while (--n > i)
	{
		dpad[n] = ibits % 255;
		ibits /= 255;
	}
	// dpad[n + 8] = 24;
	// while (i < n)
	// {
	// 	dpad[i++] = ibits % 255;
	// 	ibits /= 255;
	// }
	hexdump(dpad, n + 8);
	ft_sha256_padding_show(dpad);
	return (dpad);
}

int 		ft_sha256(const unsigned char *d, unsigned long n, unsigned char *md)
{
	char					*dpad;
	unsigned long		nalign;
	t_sha256_ctx	ctx;

	dpad = NULL;
	nalign = ft_get_size_aligned((n + FT_BYTE), FT_MODBYTE);
	ft_sha256_init(&ctx);
	if ((dpad = ft_sha256_padding(d, nalign)) == NULL)
		return (EXIT_FAILURE);
	// hexdump(dpad, nalign);
	ft_sha256_update(&ctx, (const void *)dpad, nalign);
	ft_sha256_final(&ctx, md);
	// ft_strdel(&dpad);
	return (EXIT_SUCCESS);
}
