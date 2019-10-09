#include "ft_sha256.h"

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
	while (i < n)
	{
		dpad[i++] = ibits % 255;
		ibits /= 255;
	}
	return (dpad);
}
