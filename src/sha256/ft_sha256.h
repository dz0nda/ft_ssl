#ifndef FT_SHA256_H
# define FT_SHA256_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# include "../../lib/libft/libft.h"

# define FT_MD5_LENGHTMOD 0xFFFFFFFFFFFFFFFF
# define FT_MD5_MOD_ILENGTH_BITS 0xFFFFFFFFFFFFFFFF     // 2^64 
# define FT_SHA256_MODBYTE    64
# define FT_SHA256_MODBITS    512
# define FT_SHA256_BYTE        8

typedef struct	s_ft_sha256_context
{
  uint32_t		state[8];
}				        t_ft_sha256_ctx;

unsigned char		*ft_sha256(const unsigned char *d, unsigned long n, unsigned char *md);
char		*ft_sha256_padding(const unsigned char *d, unsigned long n);
size_t		ft_get_size_aligned(size_t offset, size_t align);

#endif

// 68b3 29da
// 9893 e340
// 99c7 d8ad
// 5cb9 c940