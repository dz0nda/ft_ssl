/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/19 21:52:19 by dzonda           ###   ########lyon.fr   */
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

typedef struct  s_digest_context
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
    char        dgst[64];
}               t_dgst_ctx;

#endif
