/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b64_enc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 08:01:56 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_b64.h"

void ft_b64_enc_pad(t_uchar *dst, size_t dst_len, size_t src_len, int *idst) {
  int pad;

  pad = src_len % 3;
  while (pad > 0 && pad < 3) {
    dst[*idst] = '=';
    pad += 1;
    *idst += 1;
  }
}

void ft_b64_enc_block(t_uchar *dst, t_uint32 block, int i, int *idst) {
  static const t_uchar b64_encode[] =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  if (!(i % 3)) {
    dst[(*idst)++] = b64_encode[(t_uchar)(block >> 18) & 0x3F];
    dst[(*idst)++] = b64_encode[(t_uchar)(block >> 12) & 0x3F];
    dst[(*idst)++] = b64_encode[(t_uchar)(block >> 6) & 0x3F];
    dst[(*idst)++] = b64_encode[(t_uchar)block & 0x3F];
  } else if (i % 3 == 2) {
    dst[(*idst)++] = b64_encode[(t_uchar)(block >> 10) & 0x3F];
    dst[(*idst)++] = b64_encode[(t_uchar)(block >> 4) & 0x3F];
    dst[(*idst)++] = b64_encode[(t_uchar)(block << 2) & 0x3F];
  } else if (i % 3 == 1) {
    dst[(*idst)++] = b64_encode[(t_uchar)(block >> 2) & 0x3F];
    dst[(*idst)++] = b64_encode[(t_uchar)(block << 4) & 0x3F];
  }
}

void ft_b64_enc(t_uchar *dst, size_t dst_len, t_uchar *src, size_t src_len) {
  t_uint32 block = 0;
  int i = 0;
  int idst = 0;

  while (i < src_len) {
    block = (block << 8) | (uint32_t)src[i++];

    if (!(i % 3)) {
      ft_b64_enc_block(dst, block, i, &idst);
      block = 0;
    }
  }

  if (i % 3) ft_b64_enc_block(dst, block, i, &idst);

  ft_b64_enc_pad(dst, dst_len, src_len, &idst);

  dst[idst] = '\0';
}
