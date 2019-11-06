#ifndef FT_DGST_H
# define FT_DGST_H

# include "../ft_ssl_global.h"

# define FT_DGST_DEBUG            1
# define FT_DGST_ENDIAN_LITTLE    0
# define FT_DGST_ENDIAN_BIG       1

/*
 *  
 *  Enum :
 *      MBS : Message Block Size
 *      HS  : Hash Size
 *      HSB : Hash Size in Bits
 *  
 *  Structure context :
 *      len_hs    : Hash size
 *      len_mbs   : Message block size
 *      endian    : Endian type (Big or Little)
 *      len_state : Length of array state
 *      len_input : Length total of input
 *      len_block : Length of block (max: 2 * len_mbs)
 *      state     : Array of variables processed
 *      block     : Data to be processed (len: 2 * len_mbs)
*/

typedef enum    s_digest_enum
{
  FT_MD5_MBS        = 64,
  FT_MD5_HS         = 16,                        
  FT_MD5_HSB        = 128,                   
  FT_MD5_ENDIAN     = FT_DGST_ENDIAN_LITTLE,
  FT_MD5_STATE      = FT_MD5_HS / 4,

  FT_SHA1_MBS       = 64,
  FT_SHA1_HS        = 20,
  FT_SHA1_HBS       = 160,
  FT_SHA1_ENDIAN    = FT_DGST_ENDIAN_BIG,
  FT_SHA1_STATE     = FT_SHA1_HS / 4,
  
  FT_SHA224_MBS     = 64,
  FT_SHA224_HS      = 28,
  FT_SHA224_HBS     = 224,
  FT_SHA224_ENDIAN  = FT_DGST_ENDIAN_BIG,
  FT_SHA224_STATE   = FT_SHA224_HS / 4,

  FT_SHA256_MBS     = 64,
  FT_SHA256_HS      = 32,
  FT_SHA256_HBS     = 256,
  FT_SHA256_ENDIAN  = FT_DGST_ENDIAN_BIG,
  FT_SHA256_STATE   = FT_SHA256_HS / 4,

  FT_SHA384_MBS     = 128,
  FT_SHA384_HS      = 48,
  FT_SHA384_HBS     = 384,
  FT_SHA384_ENDIAN  = FT_DGST_ENDIAN_BIG,
  FT_SHA384_STATE   = 8,

  FT_SHA512_MBS     = 128,
  FT_SHA512_HS      = 64,
  FT_SHA512_HBS     = 512,
  FT_SHA512_ENDIAN  = FT_DGST_ENDIAN_BIG,
  FT_SHA512_STATE   = FT_SHA512_HS / 8
}               t_dgst_e;

typedef struct  s_digest_context
{
    int         len_hs;
    int         len_mbs;
    int         endian;
    int         len_state;
    int         idata;
    int         iblock;
    uint32_t    state[FT_SHA512_STATE];
    uint64_t    state64[FT_SHA512_STATE];
    uint8_t     block[FT_SHA512_MBS];
    char        dgst[FT_SHA512_HS];
}               t_dgst_ctx;

typedef struct  s_digest_info
{
    int         cmd_key;
    int         cmd_hs;
    int         cmd_mbs;
    int         cmd_endian;
    int         len_state;
}               t_dgst_inf;

typedef struct  s_digest_test
{
  t_dgst_inf    inf;
  t_dgst_ctx    ctx;
}               t_dgst_test;

int			ft_md5_init(t_dgst_ctx *ctx);
int 		ft_md5_transform(t_dgst_ctx *ctx);
int			ft_md5_final(t_dgst_ctx *ctx);

int			ft_sha1_init(t_dgst_ctx *ctx);
int 		ft_sha1_transform(t_dgst_ctx *ctx);
int			ft_sha1_final(t_dgst_ctx *ctx);

int			ft_sha256_init(t_dgst_ctx *ctx);
int			ft_sha256_transform(t_dgst_ctx *ctx);
int			ft_sha256_final(t_dgst_ctx *ctx);

int			ft_sha512_init(t_dgst_ctx *ctx);
int			ft_sha512_transform(t_dgst_ctx *ctx);
int			ft_sha512_final(t_dgst_ctx *ctx);

int			ft_sha384_init(t_dgst_ctx *ctx);

int			ft_dgst_result(t_dgst_ctx *ctx);

uint32_t		ft_rotate_left(uint32_t word, uint32_t bits);
uint32_t		ft_rotate_right(uint32_t word, uint32_t bits);
uint32_t		ft_shift_right(uint32_t word, uint32_t bits);

uint64_t		ft_rotate_left64(uint64_t word, uint64_t bits);
uint64_t		ft_rotate_right64(uint64_t word, uint64_t bits);
uint64_t		ft_shift_right64(uint64_t word, uint64_t bits);

uint32_t    swap_uint32(uint32_t val);
uint64_t    swap_uint64(uint64_t val);
size_t	    ft_get_size_aligned(size_t offset, size_t align);
void        hexdump(void *mem, unsigned int len);

void      ft_dgst_update_words_debug(uint32_t *w, int n);
void      ft_dgst_update_process_debug(uint32_t *state, int i, int n);
void      ft_dgst_state_debug(uint32_t *state, int n);



#endif
