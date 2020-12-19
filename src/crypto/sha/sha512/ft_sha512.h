/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:08:12 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA512_H
# define FT_SHA512_H

# include "../ft_ctx.h"

/*
 *  SHA functions
*/

int			ft_sha512_init(t_dgst_ctx *ctx);
int			ft_sha384_init(t_dgst_ctx *ctx);
int			ft_sha512224_init(t_dgst_ctx *ctx);
int			ft_sha512256_init(t_dgst_ctx *ctx);
int			ft_sha512_transform(t_dgst_ctx *ctx);
int			ft_sha512_final(t_dgst_ctx *ctx);

/*
 *  SHA utils
*/

uint64_t 		ft_sha512_wsigma0(uint64_t word);
uint64_t 		ft_sha512_wsigma1(uint64_t word);
uint64_t 		ft_sha512_sigma0(uint64_t state[8], uint64_t w, int i);
uint64_t 		ft_sha512_sigma1(uint64_t state[8]);

#endif
