#ifndef FT_SSL_UTILS_H
# define FT_SSL_UTILS_H

# include <ctype.h>
# include <stdio.h>
# include <stdint.h>

# include "../ssl/ft_ssl.h"

uint32_t    ft_shift_right(uint32_t word, uint32_t bits);
uint32_t    ft_rotate_right(uint32_t word, uint32_t bits);
uint32_t    ft_rotate_left(uint32_t word, uint32_t bits);

void		ft_init_show(t_ssl_ctx *ctx);

size_t		ft_get_size_aligned(size_t offset, size_t align);

uint32_t    swap_uint32( uint32_t val );
uint64_t    swap_uint64( uint64_t val );

void        hexdump(void *mem, unsigned int len);

#endif
