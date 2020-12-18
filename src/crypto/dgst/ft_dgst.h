/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/04 00:47:28 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DGST_H
# define FT_DGST_H

# include "../../ft_ssl_global.h"
# include "../sha/ft_sha.h"

# define FT_DGST_ROTL_X32(word, bits)   \
  ((word << bits) | (word >> (32 - bits)))
# define FT_DGST_ROTR_X32(word, bits)   \
  ((word >> bits) | (word << (32 - bits)))

# define FT_DGST_ROTL_X64(word, bits)   \
  ((word << bits) | (word >> (64 - bits)))
# define FT_DGST_ROTR_X64(word, bits)   \
  ((word >> bits) | (word << (64 - bits)))

# define FT_DGST_SHFR(word, bits)       \
  (word >> bits)

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

# define FT_DGST_DEBUG            0

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

char	   *ft_dgst(int dgst_key, char *arg, int arg_type, char *md, int outp);
int     ft_dgst_init(t_dgst *dgst, int cmd_key);
int     ft_dgst_input(t_dgst *dgst, uint8_t *msg, unsigned int msg_len, t_sha_step hash);
int     ft_dgst_input_file(t_dgst *dgst, const char *filename, unsigned int outp, t_sha_step hash);
int			ft_dgst_pad(t_dgst *dgst);
int			ft_dgst_finalize(t_dgst *dgst);
char    *ft_dgst_result(t_dgst_ctx *ctx, char *cmd_dgst);

void      ft_dgst_update_words_debug(uint32_t *w, int n);
void      ft_dgst_update_process_debug(uint32_t *state, int i, int n);
void      ft_dgst_state_debug(uint32_t *state, int n);



#endif
