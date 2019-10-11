#ifndef FT_SSL_UTILS_H
# define FT_SSL_UTILS_H

# include <ctype.h>
# include <stdio.h>
# include <stdint.h>

uint32_t    ft_shift_right(uint32_t word, uint32_t bits);
uint32_t    ft_rotate_right(uint32_t word, uint32_t bits);
uint32_t    ft_rotate_left(uint32_t word, uint32_t bits);

size_t		ft_get_size_aligned(size_t offset, size_t align);

void        hexdump(void *mem, unsigned int len);

#endif
