/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/04 14:19:20 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA_H
# define FT_SHA_H

# include "../../../ft_ssl_global.h"

# define FT_DGST_ENDIAN_LITTLE    0
# define FT_DGST_ENDIAN_BIG       1

# define FT_DGST_X32   8
# define FT_DGST_X64   16

typedef enum			e_sha_enum
{
	FT_SHA1_MSG_BLOCK_SIZE = 64,
	FT_SHA1_HASH_SIZE = 20,
	FT_SHA1_STATE = 5,

	FT_SHA256_MSG_BLOCK_SIZE = 64,
	FT_SHA256_HASH_SIZE = 32,
	FT_SHA256_STATE = 8,

	FT_SHA224_MSG_BLOCK_SIZE = FT_SHA256_MSG_BLOCK_SIZE,
	FT_SHA224_HASH_SIZE = 28,
	FT_SHA224_STATE = 7,

	FT_SHA512_MSG_BLOCK_SIZE = 128,
	FT_SHA512_HASH_SIZE = 64,
	FT_SHA512_STATE = 8,

	FT_SHA384_MSG_BLOCK_SIZE = FT_SHA512_MSG_BLOCK_SIZE,
	FT_SHA384_HASH_SIZE = 48,
	FT_SHA384_STATE = 6,

	FT_SHA512224_MSG_BLOCK_SIZE = FT_SHA512_MSG_BLOCK_SIZE,
	FT_SHA512224_HASH_SIZE = FT_SHA224_HASH_SIZE,
	FT_SHA512224_STATE = 8,

	FT_SHA512256_MSG_BLOCK_SIZE = FT_SHA512_MSG_BLOCK_SIZE,
	FT_SHA512256_HASH_SIZE = FT_SHA256_HASH_SIZE,
	FT_SHA512256_STATE = 8,
}						t_sha_enum;

typedef struct		s_sha1_context
{
	int				hash_size;
	int				msg_block_size;
	int				iblock;
	uint32_t		state[FT_SHA1_STATE];
	uint8_t			block[128];
	uint8_t			*msg;
	unsigned int	msg_len;
}					t_sha1_ctx;

typedef struct		s_sha256_context
{
	int				hash_size;
	int				msg_block_size;
	int				iblock;
	int				state_len;
	uint32_t		state[FT_SHA256_STATE];
	uint8_t			block[128];
	uint8_t			*msg;
	unsigned int	msg_len;
}					t_sha256_ctx;

typedef struct		s_sha512_context
{
	int				hash_size;
	int				msg_block_size;
	int				iblock;
	int				state_len;
	uint64_t		state[FT_SHA512_STATE];
	uint8_t			block[128];
	uint8_t			*msg;
	unsigned int	msg_len;
}					t_sha512_ctx;

/*
**  SHA1 functions
*/

int					ft_sha1_init(t_sha1_ctx *ctx);
int					ft_sha1_pre_process(t_sha1_ctx *ctx, uint8_t *msg,
	unsigned int msg_len);
int					ft_sha1_process(t_sha1_ctx *ctx);
char				*ft_sha1_final(t_sha1_ctx *ctx, char *cmd_dgst);
uint32_t			ft_sha1_hash_f(int j, int b, int c, int d);
uint32_t			ft_sha1_hash_k(int j);

/*
**  SHA224 functions
*/

int					ft_sha224_init(t_sha256_ctx *ctx);
int					ft_sha224_pre_process(t_sha256_ctx *ctx, uint8_t *msg,
	unsigned int msg_len);
int					ft_sha224_transform(t_sha256_ctx *ctx);
char				*ft_sha224_final(t_sha256_ctx *ctx, char *cmd_dgst);

/*
**  SHA256 functions
*/

int					ft_sha256_init(t_sha256_ctx *ctx);
int					ft_sha256_pre_process(t_sha256_ctx *ctx, uint8_t *msg,
	unsigned int msg_len);
int					ft_sha256_process(t_sha256_ctx *ctx);
char				*ft_sha256_final(t_sha256_ctx *ctx, char *cmd_dgst);
int					ft_sha256_wsigma0(uint32_t word);
int					ft_sha256_wsigma1(uint32_t word);
int					ft_sha256_sigma0(uint32_t state[8], uint32_t w,
	unsigned int i);
int					ft_sha256_sigma1(uint32_t state[8]);

/*
**  SHA384 functions
*/

int					ft_sha384_init(t_sha512_ctx *ctx);
int					ft_sha384_pre_process(t_sha512_ctx *ctx, uint8_t *msg,
	unsigned int msg_len);
int					ft_sha384_transform(t_sha512_ctx *ctx);
char				*ft_sha384final(t_sha512_ctx *ctx, char *cmd_dgst);

/*
**  SHA512 functions
*/

int					ft_sha512_init(t_sha512_ctx *ctx);
int					ft_sha512_pre_process(t_sha512_ctx *ctx, uint8_t *msg,
	unsigned int msg_len);
int					ft_sha512_process(t_sha512_ctx *ctx);
char				*ft_sha512_final(t_sha512_ctx *ctx, char *cmd_dgst);

uint64_t			ft_sha512_wsigma0(uint64_t word);
uint64_t			ft_sha512_wsigma1(uint64_t word);
uint64_t			ft_sha512_sigma0(uint64_t state[8], uint64_t w, int i);
uint64_t			ft_sha512_sigma1(uint64_t state[8]);

/*
**  SHA512256 functions
*/

int					ft_sha512224_init(t_sha512_ctx *ctx);
int					ft_sha512256_init(t_sha512_ctx *ctx);
int					ft_sha512256_pre_process(t_sha512_ctx *ctx, uint8_t *msg,
	unsigned int msg_len);
int					ft_sha512256_transform(t_sha512_ctx *ctx);
char				*ft_sha512256_final(t_sha512_ctx *ctx, char *cmd_dgst);

#endif
