#include "ft_md5.h"

//! Byte swap unsigned int
uint32_t swap_uint32( uint32_t val )
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

uint64_t swap_uint64( uint64_t val )
{
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
    return (val << 32) | (val >> 32);
}

char		*ft_md5_padding(const unsigned char *d, unsigned long n)
{
	size_t	i;
	uint64_t	ibits;
	char	*dpad;

	i = ft_strlen((const char *)d);
	ibits = i * 8;
	hexdump(&ibits, i * 8);

	uint64_t libits = swap_uint64(ibits);
	hexdump(&libits, i * 8);
	if ((dpad = ft_strnew(n)) == NULL)
		return (NULL);
	ft_strcpy(dpad, (const void *)d);
	dpad[i] = 0x80;
	while (++i < (n - FT_MD5_BYTE))
		dpad[i] = 0;
	// while (--n > i)
	// {
	// 	dpad[n] = ibits % 255;
	// 	ibits /= 255;
	// }
	while (i < n)
	{
		dpad[i++] = ibits % 256;
		ibits /= 256;
	}
	// int j = 0;sssss
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
