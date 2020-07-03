/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/03 17:34:55 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA_H
# define FT_SHA_H

# include "../../ft_ssl_global.h"

# define FT_DGST_SHA256_SIGMA_W0(word)  \
  (FT_DGST_ROTR_X32(word, 7) ^ FT_DGST_ROTR_X32(word, 18) ^ \
    FT_DGST_SHFR(word, 3))
# define FT_DGST_SHA256_SIGMA_W1(word)  \
  (FT_DGST_ROTR_X32(word, 17) ^ FT_DGST_ROTR_X32(word, 19) ^ \
    FT_DGST_SHFR(word, 10))

# define FT_DGST_SHA256_SIGMA_CH(x, y, z) \
  ((x & y) ^ ((~x) & z))
# define FT_DGST_SHA256_SIGMA_MAJ(x, y, z) \
  ((x & y) ^ (x & z) ^ (y & z))

# define FT_DGST_SHA256_SIGMA_T0(word) \
  (FT_DGST_ROTR_X32(word, 6) ^ FT_DGST_ROTR_X32(word, 11) ^ \
    FT_DGST_ROTR_X32(word, 25))
# define FT_DGST_SHA256_SIGMA_T1(word) \
  (FT_DGST_ROTR_X32(word, 2) ^ FT_DGST_ROTR_X32(word, 13) ^ \
    FT_DGST_ROTR_X32(word, 22))

/*
 *  
 *  Enum :
 *      MBS : Message Block Size
 *      HS  : Hash Size
 *      HSB : Hash Size in Bits
 *  
 *  Structure context :
 *      hs    : Hash size
 *      mbs   : Message block size
 *      endian    : Endian type (Big or Little)
 *      sts : Length of array state
 *      len_input : Length total of input
 *      len_block : Length of block (max: 2 * mbs)
 *      state     : Array of variables processed
 *      block     : Data to be processed (len: 2 * mbs)
*/

# define FT_DGST_ENDIAN_LITTLE    0
# define FT_DGST_ENDIAN_BIG       1

# define FT_DGST_X32   8
# define FT_DGST_X64   16

typedef struct  s_digest_context  t_dgst_ctx;

typedef     int  t_dgst_process(t_dgst_ctx *);
typedef     char*	  t_dgst_dist_result(t_dgst_ctx *, char *);

typedef     int t_dgst_ft(t_dgst_ctx *);

typedef enum    s_digest_command_enum
{
    FT_MD5,
    FT_SHA1,
    FT_SHA224,
    FT_SHA256,
    FT_SHA384,
    FT_SHA512,
    FT_SHA512224,
    FT_SHA512256,
    FT_DGST_CMD
}               t_dgst_cmd_e;

typedef enum    s_digest_arg_type
{
  FT_DGST_FILE,
  FT_DGST_FILE_OUTPUT,
  FT_DGST_STRING
}               t_dgst_arg_type;

typedef enum    e_digest_rotate_enum
{
    FT_ROT_LEFT,
    FT_ROT_RIGHT
}               t_dgst_rot_e;

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

  FT_SHA256_MBS     = 64,
  FT_SHA256_HS      = 32,
  FT_SHA256_HBS     = 256,
  FT_SHA256_ENDIAN  = FT_DGST_ENDIAN_BIG,
  FT_SHA256_STATE   = FT_SHA256_HS / 4,
  
  FT_SHA224_MBS     = FT_SHA256_MBS,
  FT_SHA224_HS      = 28,
  FT_SHA224_HBS     = FT_SHA256_HBS,
  FT_SHA224_ENDIAN  = FT_SHA256_ENDIAN,
  FT_SHA224_STATE   = FT_SHA256_STATE - 1,

  FT_SHA512_MBS     = 128,
  FT_SHA512_HS      = 64,
  FT_SHA512_HBS     = 512,
  FT_SHA512_ENDIAN  = FT_DGST_ENDIAN_BIG,
  FT_SHA512_STATE   = FT_SHA512_HS / 8,

  FT_SHA384_MBS     = FT_SHA512_MBS,
  FT_SHA384_HS      = 48,
  FT_SHA384_HBS     = FT_SHA512_HBS,
  FT_SHA384_ENDIAN  = FT_SHA512_ENDIAN,
  FT_SHA384_STATE   = FT_SHA512_STATE - 2,

  FT_SHA512224_MBS     = FT_SHA512_MBS,
  FT_SHA512224_HS      = FT_SHA224_HS,
  FT_SHA512224_HBS     = FT_SHA512_HBS,
  FT_SHA512224_ENDIAN  = FT_SHA512_ENDIAN,
  FT_SHA512224_STATE   = FT_SHA512_STATE - 4,

  FT_SHA512256_MBS     = FT_SHA512_MBS,
  FT_SHA512256_HS      = FT_SHA256_HS,
  FT_SHA512256_HBS     = FT_SHA512_HBS,
  FT_SHA512256_ENDIAN  = FT_SHA512_ENDIAN,
  FT_SHA512256_STATE   = FT_SHA256_STATE,
}               t_dgst_e;

typedef union   s_digest_state
{
  uint32_t      x_32[FT_SHA512_STATE];
  uint64_t      x_64[FT_SHA512_STATE];
}               t_dgst_st;

typedef struct  s_digest_context
{
    unsigned int        hs;
    unsigned int          mbs;
    unsigned int          endian;
    unsigned int         sts;
    unsigned int         x;
    unsigned int         idata;
    unsigned int         iblock;
    t_dgst_st   state;
    uint8_t     block[FT_SHA512_MBS];
    char        dgst[FT_SHA512_HS];
}               t_dgst_ctx;


typedef struct s_dgst_dist
{
    t_dgst_process      *transform;
}               t_dgst_dist;

typedef struct  s_digest_dispatcher
{
  int   dgst_key;
  int   dgst_hash_size;
  int   dgst_message_block_size;
  int   dgst_endian;
  int   dgst_state_size;
  int   dgst_x;
  t_dgst_ft *dgst_init;
  t_dgst_ft *dgst_compress;
}               t_digest_dispatch;

typedef struct  s_digest
{
  int         dist_enum;
  t_dgst_ctx  ctx;
  t_dgst_dist dist;
}               t_dgst;

/*
 *      init: Init the dgst state
 *      transform: Process block of size 'mbs'
*/

int			ft_md5_init(t_dgst_ctx *ctx);
int 		ft_md5_transform(t_dgst_ctx *ctx);

int			ft_sha1_init(t_dgst_ctx *ctx);
int 		ft_sha1_transform(t_dgst_ctx *ctx);

int			ft_sha256_init(t_dgst_ctx *ctx);
int			ft_sha256_transform(t_dgst_ctx *ctx);

int			ft_sha512_init(t_dgst_ctx *ctx);
int			ft_sha512_transform(t_dgst_ctx *ctx);

int			ft_sha384_init(t_dgst_ctx *ctx);
int			ft_sha224_init(t_dgst_ctx *ctx);
int			ft_sha512224_init(t_dgst_ctx *ctx);
int			ft_sha512256_init(t_dgst_ctx *ctx);

/*
 *      This interface connect to the sha functions
*/


/*
 *  dgst_utils
*/

uint32_t		ft_rotate_x32(uint32_t word, uint32_t bits, t_dgst_rot_e);
uint32_t		ft_shift_x32(uint32_t word, uint32_t bits, t_dgst_rot_e);
uint64_t		ft_rotate_x64(uint64_t word, uint64_t bits, t_dgst_rot_e);
uint64_t		ft_shift_x64(uint64_t word, uint64_t bits, t_dgst_rot_e);
uint64_t        ft_swap_uint(uint64_t val, size_t len);


void      ft_dgst_update_words_debug(uint32_t *w, int n);
void      ft_dgst_update_process_debug(uint32_t *state, int i, int n);
void      ft_dgst_state_debug(uint32_t *state, int n);



#endif
