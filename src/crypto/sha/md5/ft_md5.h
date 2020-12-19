/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:20:20 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "../ft_ctx.h"

typedef enum    e_md5_enum
{
  FT_MD5_MBS        = 64,
  FT_MD5_HS         = 16,                        
  FT_MD5_HSB        = 128,                   
  FT_MD5_ENDIAN     = 0,
  FT_MD5_STATE      = 4,
}               t_md5_enum;

/*
 *  MD5 functions
*/

int			ft_md5_init(t_dgst_ctx *ctx);
int 		ft_md5_transform(t_dgst_ctx *ctx);
int			ft_md5_final(t_dgst_ctx *ctx);

/*
 *  MD5 utils
*/

uint32_t     ft_md5_hash_f(int i, int b, int c, int d);
uint32_t     ft_md5_hash_g(int i);
uint32_t     ft_md5_hash_k(int i);
uint32_t     ft_md5_hash_s(int i);

#endif
