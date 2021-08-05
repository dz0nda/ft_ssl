/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/29 14:08:40 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"

static int ceil(int x, int y) { return (x + y - 1) / y; }

// static int unpaddedBase64(int n) {
//   int bits = 8 * n;
//   return ceilDiv(bits, 6);
// }

int ft_base64_get_encoded_len(int src_len) {
  int blocks = ceil(src_len, 3);

  return blocks * 4;
}

int ft_base64_get_decoded_len(unsigned char *src, int src_len) {
  int pad;

  pad = 0;
  if (src_len == 0 || (src_len % 4 != 0)) return (0);

  if (src[src_len - 1] == '=') pad += 1;
  if (src[src_len - 2] == '=') pad += 1;

  return (3 * (src_len / 4) - pad);
}
