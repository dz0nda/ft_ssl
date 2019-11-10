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


typedef struct  s_digest_context  t_dgst_ctx;

typedef     int  t_dgst_process(t_dgst_ctx *);
typedef     char*	  t_dgst_dist_result(t_dgst_ctx *, char *);

typedef enum    s_digest_dist_enum
{
    FT_MD5,
    FT_SHA1,
    FT_SHA256,
    FT_SHA384,
    FT_SHA512,
    FT_DGST_DIST
}               t_dgst_dist_e;

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
  FT_SHA512_HS      = 128,
  FT_SHA512_HBS     = 512,
  FT_SHA512_ENDIAN  = FT_DGST_ENDIAN_BIG,
  FT_SHA512_STATE   = FT_SHA512_HS / 8
}               t_dgst_e;

typedef union   s_digest_state
{
  uint32_t      x_32[FT_SHA512_STATE];
  uint64_t      x_64[FT_SHA512_STATE];
}               t_dgst_st;

typedef struct  s_digest_context
{
    int         len_hs;
    int         len_mbs;
    int         endian;
    int         len_state;
    int         idata;
    int         iblock;
    t_dgst_st   state;
    uint8_t     block[FT_SHA512_MBS];
    char        dgst[FT_SHA512_HS];
}               t_dgst_ctx;

typedef struct s_dgst_dist
{
    t_dgst_process      *init;
    t_dgst_process      *transform;
    t_dgst_process      *final;
    t_dgst_dist_result  *result;
}               t_dgst_dist;


typedef struct  s_digest
{
  int         dist_enum;
  t_dgst_ctx  ctx;
  t_dgst_dist dist;
}               t_dgst;


char*     ft_dgst(int cmd_key, char *cmd_arg, int cmd_arg_len, char *cmd_dgst);

/*
 *      init: Init the dgst state
 *      transform: Process block of size 'len_mbs'
*/



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

/*
 *      This interface connect to the sha functions
*/

int			ft_dgst_addlength_32(t_dgst_ctx *ctx);
int			ft_dgst_addlength_64(t_dgst_ctx *ctx);

int			ft_dgst_pad(t_dgst_ctx *ctx);

char*				ft_dgst_result32(t_dgst_ctx *ctx, char *cmd_dgst);
char*				ft_dgst_result64(t_dgst_ctx *ctx, char *cmd_dgst);

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
