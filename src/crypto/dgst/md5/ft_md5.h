/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/04 11:09:16 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "../../../ft_ssl_global.h"

typedef enum		e_md5_enum
{
	FT_MD5_MESSAGE_BLOCK_SIZE = 64,
	FT_MD5_HS = 16,
	FT_MD5_HSB = 128,
	FT_MD5_ENDIAN = 0,
	FT_MD5_STATE = 4,
}					t_md5_enum;

typedef struct		s_md5_context
{
	int				hs;
	int				mbs;
	int				iblock;
	uint32_t		state[FT_MD5_STATE];
	uint32_t		words[80];
	uint64_t		len;
	uint8_t			block[128];
	uint8_t			*msg;
	unsigned int	msg_len;
}					t_md5_ctx;

/*
** MD5 functions
*/

int					ft_md5_init(t_md5_ctx *ctx);
int					ft_md5_pad(t_md5_ctx *ctx, uint8_t *msg,
	unsigned int msg_len);
int					ft_md5_transform(t_md5_ctx *ctx);
char				*ft_md5_final(t_md5_ctx *ctx, char *cmd_dgst);
uint32_t			ft_md5_hash_f(int i, int b, int c, int d);
uint32_t			ft_md5_hash_g(int i);
uint32_t			ft_md5_hash_k(int i);
uint32_t			ft_md5_hash_s(int i);

#endif
