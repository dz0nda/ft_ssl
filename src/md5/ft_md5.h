#ifndef FT_MD5_H
# define FT_MD5_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# include "../../lib/libft/libft.h"

# define FT_MD5_LENGHTMOD 0xFFFFFFFFFFFFFFFF
# define FT_MD5_PADMOD    64
# define FT_MD5_BYTE      8

typedef struct  s_ft_md5_context
{
  uint32_t      total;
  uint32_t      state[4];
  unsigned char buffer[64];
}               t_ft_md5_ctx;

unsigned char   *ft_md5(const unsigned char *d, unsigned long n, unsigned char *md);
int             ft_md5_init(t_ft_md5_ctx *ctx);
char            *ft_md5_padding(const unsigned char *d, unsigned long n);
int   ft_md5_update(t_ft_md5_ctx *ctx, const void *data, unsigned long len);
#endif