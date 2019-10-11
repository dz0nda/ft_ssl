#include "ft_ssl_utils.h"

uint32_t		ft_rotate_left(uint32_t word, uint32_t bits)
{
	return ((word << bits) | (word >> (32 - bits)));
}

uint32_t		ft_rotate_right(uint32_t word, uint32_t bits)
{
	return ((word >> bits) | (word << (32 - bits)));
}

uint32_t		ft_shift_right(uint32_t word, uint32_t bits)
{
	return (word >> bits);
}
