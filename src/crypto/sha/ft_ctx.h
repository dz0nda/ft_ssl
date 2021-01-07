/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/01/06 17:05:02 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTX_H
# define FT_CTX_H

# include "../../ft_ssl_global.h"

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

#endif
