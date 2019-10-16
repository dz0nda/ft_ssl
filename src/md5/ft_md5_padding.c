#include "ft_md5.h"

static void			ft_md5_padding_show(char *dpad)
{
	int i;

	i = -1;
	printf("Padding show: \n");
	printf("'%s'\n", dpad);
}

char		*ft_md5_padding(const unsigned char *d, unsigned long n)
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
	while (++i < (n - FT_MD5_BYTE))
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
