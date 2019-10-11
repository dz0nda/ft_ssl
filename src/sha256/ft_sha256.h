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

typedef enum    s_sha256_enum
{
  T_SHA256_MBS = 64,
  T_SHA256_HS = 32,
  T_SHA256_HBS = 256
}               t_sha256enum;

typedef struct	s_sha256_context
{
  uint32_t		hash[8];
}				        t_sha256_ctx;

unsigned char	    *ft_sha256(const unsigned char *d, unsigned long n, unsigned char *md);
char		          *ft_sha256_padding(const unsigned char *d, unsigned long n);
size_t		        ft_get_size_aligned(size_t offset, size_t align);
int				        ft_sha256_update(t_sha256_ctx *ctx, const void *data, unsigned long len);
void				      ft_sha256_final(t_sha256_ctx *ctx, unsigned char *md);

uint32_t		      ft_sha256_sigma0a(uint32_t word);
uint32_t		      ft_sha256_sigma1a(uint32_t word);
uint32_t		      ft_sha256_sigma0b(uint32_t word);
uint32_t		      ft_sha256_sigma1b(uint32_t word);

uint32_t		      ft_shift_right(uint32_t word, uint32_t bits);
uint32_t		      ft_rotate_right(uint32_t word, uint32_t bits);
uint32_t		      ft_rotate_left(uint32_t word, uint32_t bits);

#endif

// 68b3 29da
// 9893 e340
// 99c7 d8ad
// 5cb9 c940