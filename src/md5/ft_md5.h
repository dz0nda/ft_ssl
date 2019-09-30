#ifndef FT_MD5_H
# define FT_MD5_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# include "../../lib/libft/libft.h"

# define FT_MD5_LENGHTMOD 0xFFFFFFFFFFFFFFFF
# define FT_MD5_MOD_ILENGTH_BITS 0xFFFFFFFFFFFFFFFF     // 2^64 
# define FT_MD5_MODBYTE    64
# define FT_MD5_MODBITS    512
# define FT_MD5_BYTE        8

typedef struct  s_ft_md5_context
{
  uint32_t      state[4];
}               t_ft_md5_ctx;

unsigned char   *ft_md5(const unsigned char *d, unsigned long n, unsigned char *md);
size_t			ft_get_size_aligned(size_t offset, size_t align);
void			ft_md5_puthexa(uint32_t nb);

char            *ft_md5_padding(const unsigned char *d, unsigned long n);
int               ft_md5_update(t_ft_md5_ctx *ctx, const void *data, unsigned long len);
void  ft_md5_final(t_ft_md5_ctx *ctx, unsigned char *md);
#endif