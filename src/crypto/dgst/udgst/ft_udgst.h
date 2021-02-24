/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udgst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/23 22:12:38 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UDGST_H
# define FT_UDGST_H

# include "../md5/ft_md5.h"
# include "../sha/ft_sha.h"

typedef enum	e_dgst_version
{
	FT_MD5,
	FT_SHA1,
	FT_SHA224,
	FT_SHA256,
	FT_SHA384,
	FT_SHA512,
	FT_SHA512224,
	FT_SHA512256,
	FT_DGST_VERSION
}				t_dgst_version;

typedef union		u_udgst_ctx
{
	t_md5_ctx			md5_ctx;
	t_sha1_ctx		sha1_ctx;
	t_sha256_ctx 	sha256_ctx;
	t_sha512_ctx	sha512_ctx;
}								t_udgst_ctx;

typedef struct	s_udgst
{
	int					key;
	t_udgst_ctx	ctx;
}								t_udgst;

char	*ft_udgst(int key, uint8_t *msg, unsigned int msg_len, char *md);

#endif
