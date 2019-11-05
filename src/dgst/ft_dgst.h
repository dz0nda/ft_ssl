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
  FT_MD5_MBS =        64,
  FT_MD5_HS =         16,                        
  FT_MD5_HSB =        128,                   
  FT_MD5_ENDIAN =     FT_DGST_ENDIAN_LITTLE,
  FT_MD5_STATE =      FT_MD5_HS / 4,

  FT_SHA1_MBS =       64,
  FT_SHA1_HS =        20,
  FT_SHA1_HBS =       160,
  FT_SHA1_ENDIAN =    FT_DGST_ENDIAN_BIG,
  FT_SHA1_STATE =      FT_SHA1_HS / 4,

  FT_SHA256_MBS =     64,
  FT_SHA256_HS =      32,
  FT_SHA256_HBS =     256,
  FT_SHA256_ENDIAN =  FT_DGST_ENDIAN_BIG,
  FT_SHA256_STATE =   FT_SHA256_HS / 4
}               t_dgst_e;

typedef struct  s_digest_context
{
    int         len_hs;
    int         len_mbs;
    int         endian;
    int         len_state;
    int         len_input;
    int         idata;
    int         iblock;
    uint32_t    state[FT_SHA256_STATE];
    uint8_t     block[FT_SHA256_MBS];
    char        dgst[FT_SHA256_HS];
}               t_dgst_ctx;

int			ft_md5_init(t_dgst_ctx *ctx);
int 		ft_md5_transform(t_dgst_ctx *ctx);
int			ft_md5_final(t_dgst_ctx *ctx);

int			ft_sha1_init(t_dgst_ctx *ctx);
int 		ft_sha1_transform(t_dgst_ctx *ctx);
int			ft_sha1_final(t_dgst_ctx *ctx);

int			ft_sha256_init(t_dgst_ctx *ctx);
int			ft_sha256_transform(t_dgst_ctx *ctx);
int			ft_sha256_final(t_dgst_ctx *ctx);

int			ft_dgst_result(t_dgst_ctx *ctx);

uint32_t		ft_rotate_left(uint32_t word, uint32_t bits);
uint32_t		ft_rotate_right(uint32_t word, uint32_t bits);
uint32_t		ft_shift_right(uint32_t word, uint32_t bits);
uint32_t    swap_uint32(uint32_t val);
uint64_t    swap_uint64(uint64_t val);
size_t	    ft_get_size_aligned(size_t offset, size_t align);
void        hexdump(void *mem, unsigned int len);

void      ft_dgst_update_words_debug(uint32_t *w, int n);
void      ft_dgst_update_process_debug(uint32_t *state, int i, int n);
void      ft_dgst_state_debug(uint32_t *state, int n);



#endif
