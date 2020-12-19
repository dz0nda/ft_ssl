/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:10:52 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA1_H
# define FT_SHA1_H

# include "../ft_ctx.h"

/*
 *  SHA1 functions
*/

int			ft_sha1_init(t_dgst_ctx *ctx);
int 		ft_sha1_transform(t_dgst_ctx *ctx);
int			ft_sha1_final(t_dgst_ctx *ctx);

/*
 *  SHA1 utils
*/

uint32_t     ft_sha1_hash_f(int j, int b, int c, int d);
uint32_t     ft_sha1_hash_k(int j);


#endif
