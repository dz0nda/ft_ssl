/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b64_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 08:06:22 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_b64.h"

static int ft_ceil(int x, int y) { return (x + y - 1) / y; }

// static int unpaddedBase64(int n) {
//   int bits = 8 * n;
//   return ceilDiv(bits, 6);
// }

int ft_b64_get_encoded_len(int src_len) {
  int blocks = ft_ceil(src_len, 3);

  return blocks * 4;
}

int ft_b64_get_decoded_len(unsigned char *src, int src_len) {
  int pad;

  pad = 0;
  if (src_len == 0 || (src_len % 4 != 0)) return (0);

  if (src[src_len - 1] == '=') pad += 1;
  if (src[src_len - 2] == '=') pad += 1;

  return (3 * (src_len / 4) - pad);
}

// 9bdfxiySfGA=
// 9bdfxiySfGA=