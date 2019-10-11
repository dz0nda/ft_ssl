#include "ft_sha256.h"

uint32_t		ft_sha256_sigma0a(uint32_t word)
{
	return (ft_rotate_right(word, 7) ^ ft_rotate_right(word, 18) ^ ft_shift_right(word, 3));
}

uint32_t		ft_sha256_sigma1a(uint32_t word)
{
	return (ft_rotate_right(word, 17) ^ ft_rotate_right(word, 19) ^ ft_shift_right(word, 10));
}

uint32_t		ft_sha256_sigma0b(uint32_t word)
{
	return (ft_rotate_right(word, 2) ^ ft_rotate_right(word, 13) ^ ft_rotate_right(word, 25));
}

uint32_t		ft_sha256_sigma1b(uint32_t word)
{
	return (ft_rotate_right(word, 6) ^ ft_rotate_right(word, 11) ^ ft_rotate_right(word, 25));
}