#include "ft_sha256.h"

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
	while (++i < (n - FT_SHA256_BYTE))
		dpad[i] = 0;
	while (--n > i)
	{
		dpad[n] = ibits % 255;
		ibits /= 255;
	}
	// while (i < n)
	// {
	// 	dpad[i++] = ibits % 255;
	// 	ibits /= 255;
	// }
	ft_sha256_padding_show(dpad);
	return (dpad);
}
