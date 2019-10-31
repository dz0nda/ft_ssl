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


# define FT_DGST_LITTLE_ENDIAN 0
# define FT_DGST_BIG_ENDIAN 1

typedef enum    s_digest_enum
{
  FT_MD5_MBS = 64,          // Message block size in bytes
  FT_MD5_HS = 16,           // Hash size in bytes     
  FT_MD5_HSB = 128,          // Hash size in bits 
  FT_MD5_ENDIAN = FT_DGST_LITTLE_ENDIAN,

  FT_SHA1_MBS = 64,
  FT_SHA1_HS = 20,
  FT_SHA1_HBS = 160,
  FT_SHA1_ENDIAN = FT_DGST_BIG_ENDIAN,

  FT_SHA256_MBS = 64,
  FT_SHA256_HS = 32,
  FT_SHA256_HBS = 256,
  FT_SHA256_ENDIAN = FT_DGST_BIG_ENDIAN,
}               t_dgst_e;

typedef struct  s_md5_context
{
  int         cmd_key;
  int         len_hs;
  int         len_mbs;
  int         endian;
  int         len_state;
  uint32_t		  state[FT_MD5_HS/4];
  uint8_t       block[FT_MD5_MBS];
}				t_md5_ctx;

typedef struct	s_sha1_context
{
  int         cmd_key;
  int         len_hs;
  int         len_mbs;
  int         endian;
  int         len_state;
  uint32_t		  state[FT_SHA1_HS/4];
  uint8_t       block[FT_SHA1_MBS];
}				        t_sha1_ctx;

typedef struct	s_sha256_context
{
  int         cmd_key;
  int         len_hs;
  int         len_mbs;
  int         endian;
  int         len_state;
  uint32_t		  state[FT_SHA256_HS/4];
  uint8_t       block[FT_SHA256_MBS];
}				t_sha256_ctx;

typedef struct  s_digest_context
{
    int         len_hs;
    int         len_mbs;
    int         endian;
    int         len_state;
    int         len_input;
    int         len_block;
    uint32_t    *state;
    uint8_t     *block;
}               t_dgst_ctx;

typedef union   s_digest_context_union
{
  t_md5_ctx     md5ctx;
  t_sha1_ctx    sha1ctx;
  t_sha256_ctx  sha256;
  // int   (*ft_md5)(t_md5_ctx *ctx);
  // int   (*ft_sha1)(t_sha1_ctx *ctx);
  // int   (*ft_sha256)(t_sha256_ctx *ctx);
}               t_dgst_ctx_u;


// Unified functions

int			ft_dgst_init_md5_sha1(t_dgst_ctx *ctx);


int             ft_md5(const unsigned char *d, unsigned long n, unsigned char *md);
int			    ft_md5_init(t_md5_ctx *ctx);
int		        ft_md5_update(t_md5_ctx *ctx, const void *data, unsigned long len);
int             ft_md5_final(t_md5_ctx *ctx, unsigned char *md);
void			ft_md5_update_process(uint32_t abcd[4], uint32_t *m, int j);
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
