/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/07 16:17:59 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H

# include "../../ft_ssl_global.h"
# include "ft_ctx.h"
# include "./md5/ft_md5.h"
# include "./sha/ft_sha.h"

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

typedef struct      s_digest_context  t_dgst_ctx;

typedef     int     t_hash_step_init(t_dgst_ctx *, unsigned int);
typedef     int     t_hash_step(t_dgst_ctx *);
typedef     char*   t_hash_step_final(t_dgst_ctx *, char *);

typedef struct          s_hash_dist
{
    int                 dist_key;
    t_hash_step_init         *init;
    t_hash_step         *hash;
    t_hash_step_final   *final;
}                       t_hash_dist;

typedef struct          s_dgst
{
    t_hash_dist         dist;
    t_dgst_ctx 	        ctx;
    unsigned int        padding;
}                       t_dgst;

typedef enum    s_hash_version
{
    FT_MD5,
    FT_SHA1,
    FT_SHA224,
    FT_SHA256,
    FT_SHA384,
    FT_SHA512,
    FT_SHA512224,
    FT_SHA512256,
    FT_HASH_VERSION
}               t_hash_version;

char			*ft_hash(int hash_key, uint8_t *msg, unsigned int msg_len, char *md);

void      ft_dgst_update_words_debug(uint32_t *w, int n);
void      ft_dgst_update_process_debug(uint32_t *state, int i, int n);
void      ft_dgst_state_debug(uint32_t *state, int n);

unsigned int		ft_get_size_aligned(size_t offset, size_t align);

#endif