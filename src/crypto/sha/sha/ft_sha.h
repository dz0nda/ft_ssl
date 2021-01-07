/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/07 16:20:23 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA_H
# define FT_SHA_H

# include "../ft_ctx.h"

typedef enum    e_sha_enum
{
  FT_SHA1_MBS       = 64,
  FT_SHA1_HS        = 20,
  FT_SHA1_HBS       = 160,
  FT_SHA1_ENDIAN    = 1,
  FT_SHA1_STATE     = FT_SHA1_HS / 4,

  FT_SHA256_MBS     = 64,
  FT_SHA256_HS      = 32,
  FT_SHA256_HBS     = 256,
  FT_SHA256_ENDIAN  = 1,
  FT_SHA256_STATE   = FT_SHA256_HS / 4,
  
  FT_SHA224_MBS     = FT_SHA256_MBS,
  FT_SHA224_HS      = 28,
  FT_SHA224_HBS     = FT_SHA256_HBS,
  FT_SHA224_ENDIAN  = FT_SHA256_ENDIAN,
  FT_SHA224_STATE   = FT_SHA256_STATE - 1,

  FT_SHA512_MBS     = 128,
  FT_SHA512_HS      = 64,
  FT_SHA512_HBS     = 512,
  FT_SHA512_ENDIAN  = 1,
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
}               t_sha_enum;


typedef struct  s_sha256_ctx
{
    unsigned int        hs;
    unsigned int          mbs;
    unsigned int          endian;
    unsigned int         sts;
    unsigned int         x;
    unsigned int         idata;
    unsigned int         iblock;
    t_dgst_st   state;
    uint8_t     block[128];
    char        dgst[8192];
}               t_sha256_ctx;

/*
 *  SHA1 functions
*/

int			ft_sha1_init(t_dgst_ctx *ctx, unsigned int msg_len);
int 		ft_sha1_transform(t_dgst_ctx *ctx);
char		*ft_sha1_final(t_dgst_ctx *ctx, char *cmd_dgst);

/*
 *  SHA256 functions
*/

int			ft_sha256_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha224_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha256_transform(t_dgst_ctx *ctx);
char		*ft_sha256_final(t_dgst_ctx *ctx, char *cmd_dgst);
int 		ft_sha256_wsigma0(uint32_t word);
int 		ft_sha256_wsigma1(uint32_t word);
int 		ft_sha256_sigma0(uint32_t state[8], uint32_t w, unsigned int i);
int 		ft_sha256_sigma1(uint32_t state[8]);

/*
 *  SHA512 functions
*/

int			ft_sha512_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha384_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha512224_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha512256_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha512_transform(t_dgst_ctx *ctx);
char		*ft_sha512_final(t_dgst_ctx *ctx, char *cmd_dgst);
uint64_t 		ft_sha512_wsigma0(uint64_t word);
uint64_t 		ft_sha512_wsigma1(uint64_t word);
uint64_t 		ft_sha512_sigma0(uint64_t state[8], uint64_t w, int i);
uint64_t 		ft_sha512_sigma1(uint64_t state[8]);


#endif
