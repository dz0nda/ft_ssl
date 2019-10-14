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
  FTMD5_MB_Size = 64,
  FTMD5HashSize = 16,
  FTMD5HashSizeBits = 128
}       t_md5enum;

typedef struct	s_ft_md5_context
{
  uint32_t		hash[FTMD5HashSize/4];
  uint8_t     block[FTMD5_MB_Size];
}				t_ftmd5ctx;

unsigned char   *ft_md5(const unsigned char *d, unsigned long n, unsigned char *md);
char			      *ft_md5_padding(const unsigned char *d, unsigned long n);
int				      ft_md5_update(t_ftmd5ctx *ctx, const void *data, unsigned long len);
void			      ft_md5_final(t_ftmd5ctx *ctx, unsigned char *md);

#endif
