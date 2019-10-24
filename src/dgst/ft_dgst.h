#ifndef FT_DGST_H
# define FT_DGST_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# include "../../lib/libft/libft.h"
# include "../ssl_utils/ft_ssl_utils.h"

# define FT_MD5_LENGHTMOD 0xFFFFFFFFFFFFFFFF
# define FT_MD5_MOD_ILENGTH_BITS 0xFFFFFFFFFFFFFFFF     // 2^64 
# define FT_MODBYTE    64
# define FT_MODBITS    512
# define FT_BYTE        8

typedef enum    s_dgst_enum
{
  FT_MD5_MBS = 64,          // Message block size in bytes
  FT_MD5_HS = 16,           // Hash size in bytes     
  FT_MD5_HSB = 128,          // Hash size in bits 

  FT_SHA1_MBS = 64,
  FT_SHA1_HS = 20,
  FT_SHA1_HBS = 160,

  FT_SHA256_MBS = 64,
  FT_SHA256_HS = 32,
  FT_SHA256_HBS = 256
}               t_dgst_e;

typedef struct  s_md5_context
{
  uint32_t		state[FT_MD5_HS/4];
  uint8_t       block[FT_MD5_MBS];
}				t_md5_ctx;

typedef struct	s_sha1_context
{
  uint32_t		state[FT_SHA1_HS/4];
  uint8_t       block[FT_SHA1_MBS];
}				        t_sha1_ctx;

typedef struct	s_sha256_context
{
  uint32_t		state[FT_SHA256_HS/4];
  uint8_t       block[FT_SHA256_MBS];
}				t_sha256_ctx;

int             ft_md5(const unsigned char *d, unsigned long n, unsigned char *md);
int			    ft_md5_init(t_md5_ctx *ctx);
int		        ft_md5_update(t_md5_ctx *ctx, const void *data, unsigned long len);
int             ft_md5_final(t_md5_ctx *ctx, unsigned char *md);

int             ft_sha1(const unsigned char *d, unsigned long n, unsigned char *md);
int			    ft_sha1_init(t_sha1_ctx *ctx);
int				ft_sha1_update(t_sha1_ctx *ctx, const void *data, unsigned long len);
int             ft_sha1_final(t_sha1_ctx *ctx, unsigned char *md);

uint32_t	    ft_sha1_sigma0a(uint32_t word);
uint32_t        ft_sha1_sigma1a(uint32_t word);
uint32_t        ft_sha1_sigma0b(uint32_t word);
uint32_t		ft_sha1_sigma1b(uint32_t word);

int             ft_sha256(const unsigned char *d, unsigned long n, unsigned char *md);
int             ft_sha256_init(t_sha256_ctx *ctx);
int				ft_sha256_update(t_sha256_ctx *ctx, const void *data, unsigned long len);
int             ft_sha256_final(t_sha256_ctx *ctx, unsigned char *md);

uint32_t        ft_sha256_sigma0a(uint32_t word);
uint32_t        ft_sha256_sigma1a(uint32_t word);
uint32_t        ft_sha256_sigma0b(uint32_t word);
uint32_t        ft_sha256_sigma1b(uint32_t word);

#endif
