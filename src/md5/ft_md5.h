#ifndef FT_MD5_H
# define FT_MD5_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# include "../../lib/libft/libft.h"
# include "../ssl_utils/ft_ssl_utils.h"

# define FT_MD5_LENGHTMOD 0xFFFFFFFFFFFFFFFF
# define FT_MD5_MOD_ILENGTH_BITS 0xFFFFFFFFFFFFFFFF     // 2^64 
# define FT_MD5_MODBYTE    64
# define FT_MD5_MODBITS    512
# define FT_MD5_BYTE        8

typedef enum    s_md5_enum
{
  FT_MD5_MBS = 64,          // Message block size in bytes
  FT_MD5_HS = 16,           // Hash size in bytes     
  FT_MD5_HSB = 128          // Hash size in bits 
}               t_md5_e;

typedef struct	s_md5_context
{
  uint32_t		state[FT_MD5_HS/4];
  uint8_t     block[FT_MD5_MBS];
}				        t_md5_ctx;

int     ft_md5(const unsigned char *d, unsigned long n, unsigned char *md);
char	  *ft_md5_padding(const unsigned char *d, unsigned long n);
int		  ft_md5_update(t_md5_ctx *ctx, const void *data, unsigned long len);
int     ft_md5_final(t_md5_ctx *ctx, unsigned char *md);

#endif
