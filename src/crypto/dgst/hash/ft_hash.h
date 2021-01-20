/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/19 23:00:40 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H

# include "../../../ft_ssl_global.h"

# define FT_DGST_ENDIAN_LITTLE    0
# define FT_DGST_ENDIAN_BIG       1

# define FT_DGST_X32   8
# define FT_DGST_X64   16

typedef enum    e_sha_enum
{
  FT_MD5_MBS        = 64,
  FT_MD5_HS         = 16,                        
  FT_MD5_HSB        = 128,                   
  FT_MD5_ENDIAN     = 0,
  FT_MD5_STATE      = 4,

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

typedef union   s_digest_state
{
  uint32_t      x_32[8];
  uint64_t      x_64[8];
}               t_dgst_st;

typedef union   s_digest_length
{
  uint64_t      x_32;
  __uint128_t   x_64;
}               t_dgst_len;

typedef struct    s_digest_context
{
    unsigned int  hs;
    unsigned int  mbs;
    unsigned int  endian;
    unsigned int  sts;
    unsigned int  x;
    unsigned int  padding;
    unsigned int  iblock;
    t_dgst_st     state;
    t_dgst_len    len;
    uint8_t       block[128];
    uint8_t       *msg;
    unsigned int  msg_len;
}                 t_dgst_ctx;

/*
 *  MD5 functions
*/

int			ft_md5_init(t_dgst_ctx *ctx, unsigned int msg_len);
int 		ft_md5_transform(t_dgst_ctx *ctx);
char		*ft_md5_final(t_dgst_ctx *ctx, char *cmd_dgst);

uint32_t     ft_md5_hash_f(int i, int b, int c, int d);
uint32_t     ft_md5_hash_g(int i);
uint32_t     ft_md5_hash_k(int i);
uint32_t     ft_md5_hash_s(int i);

/*
 *  SHA1 functions
*/

int			ft_sha1_init(t_dgst_ctx *ctx, unsigned int msg_len);
int 		ft_sha1_transform(t_dgst_ctx *ctx);
char		*ft_sha1_final(t_dgst_ctx *ctx, char *cmd_dgst);

/*
 *  SHA224 functions
*/

int			ft_sha224_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha224_pre_process(t_dgst_ctx *ctx, uint8_t *msg, unsigned int msg_len);
int			ft_sha224_transform(t_dgst_ctx *ctx);
char		*ft_sha224_final(t_dgst_ctx *ctx, char *cmd_dgst);

/*
 *  SHA256 functions
*/

int			ft_sha256_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha256_pre_process(t_dgst_ctx *ctx, uint8_t *msg, unsigned int msg_len);
int			ft_sha256_transform(t_dgst_ctx *ctx);
char		*ft_sha256_final(t_dgst_ctx *ctx, char *cmd_dgst);

int 		ft_sha256_wsigma0(uint32_t word);
int 		ft_sha256_wsigma1(uint32_t word);
int 		ft_sha256_sigma0(uint32_t state[8], uint32_t w, unsigned int i);
int 		ft_sha256_sigma1(uint32_t state[8]);

/*
 *  SHA384 functions
*/

int			ft_sha384_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha384_pre_process(t_dgst_ctx *ctx, uint8_t *msg, unsigned int msg_len);
int			ft_sha384_transform(t_dgst_ctx *ctx);
char		*ft_sha384final(t_dgst_ctx *ctx, char *cmd_dgst);

/*
 *  SHA512 functions
*/

int			ft_sha512_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha512_pre_process(t_dgst_ctx *ctx, uint8_t *msg, unsigned int msg_len);
int			ft_sha512_transform(t_dgst_ctx *ctx);
char		*ft_sha512_final(t_dgst_ctx *ctx, char *cmd_dgst);

uint64_t 		ft_sha512_wsigma0(uint64_t word);
uint64_t 		ft_sha512_wsigma1(uint64_t word);
uint64_t 		ft_sha512_sigma0(uint64_t state[8], uint64_t w, int i);
uint64_t 		ft_sha512_sigma1(uint64_t state[8]);

/*
 *  SHA512256 functions
*/

int			ft_sha512224_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha512256_init(t_dgst_ctx *ctx, unsigned int msg_len);
int			ft_sha512256_pre_process(t_dgst_ctx *ctx, uint8_t *msg, unsigned int msg_len);
int			ft_sha512256_transform(t_dgst_ctx *ctx);
char		*ft_sha512256_final(t_dgst_ctx *ctx, char *cmd_dgst);

#endif
