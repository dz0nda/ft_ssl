/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 22:14:13 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "../ft_ctx.h"

/*
 *  SHA256 functions
*/

int			ft_sha256_init(t_dgst_ctx *ctx);
int			ft_sha224_init(t_dgst_ctx *ctx);
int			ft_sha256_transform(t_dgst_ctx *ctx);
int			ft_sha256_final(t_dgst_ctx *ctx);

/*
 *  SHA256 utils
*/

int 		ft_sha256_wsigma0(uint32_t word);
int 		ft_sha256_wsigma1(uint32_t word);
int 		ft_sha256_sigma0(uint32_t state[8], uint32_t w, unsigned int i);
int 		ft_sha256_sigma1(uint32_t state[8]);


#endif
