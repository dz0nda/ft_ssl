/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_subkeys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/06 17:00:38 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>  // for CHAR_BIT

#include "ft_des.h"

// Assumes little endian
void printBitss(size_t const size, void const *const ptr) {
  unsigned char *b = (unsigned char *)ptr;
  unsigned char byte;
  int i, j;

  for (i = size - 1; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
    printf(" ");
  }
  puts("");
}

const static ubyte PC1[] = {
    57, 49, 41, 33, 25, 17, 9,  1,  58, 50, 42, 34, 26, 18, 10, 2,  59, 51, 43,
    35, 27, 19, 11, 3,  60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7,  62, 54,
    46, 38, 30, 22, 14, 6,  61, 53, 45, 37, 29, 21, 13, 5,  28, 20, 12, 4};

const static ubyte PC2[] = {14, 17, 11, 24, 1,  5,  3,  28, 15, 6,  21, 10,
                            23, 19, 12, 4,  26, 8,  16, 7,  27, 20, 13, 2,
                            41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
                            44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

const static ubyte SHIFTS[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

// key in bits
// 00010011 00110100 01010111 01111001 10011011 10111100 11011111 11110001
// 00010011 00110100 01010111 01111001 10011011 10111100 11011111 11110001

// void ft_des_generate_subkeys_debug(t_des *ctx) {
//   SHOW_LE(uint64_t, ctx->nkey);
// }

// static void ft_des_subkeys_permute1(t_uint8 dst_key[8], t_uint64 *src_key) {
//   const static t_uint8 PC1[] = {
//     57, 49, 41, 33, 25, 17, 9,  1,  58, 50, 42, 34, 26, 18, 10, 2,  59, 51,
//     43, 35, 27, 19, 11, 3,  60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7,
//     62, 54, 46, 38, 30, 22, 14, 6,  61, 53, 45, 37, 29, 21, 13, 5,  28, 20,
//     12, 4
//   };

//   /* permute 'key' using table PC1 */
//   for (int i = 0; i < 56; ++i) {
//     ft_set_bit(dst_key, i, ft_get_bit((const t_uint8 *)src_key, PC1[i] - 1));
//   }
// }

// static void ft_des_subkeys_permute2(t_des_subkeys dst_key, t_uint64
// src_key[17]) {
//   const static t_uint8 PC2[] = {
//     14, 17, 11, 24, 1,  5,  3,  28, 15, 6,  21, 10,
//     23, 19, 12, 4,  26, 8,  16, 7,  27, 20, 13, 2,
//     41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
//     44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
//   };

//   /* form the sub-keys and store them in 'ks'
//    * permute 'c' using table PC2 */
//   for (int i = 1; i < 17; ++i) {
//     for (int j = 0; j < 48; ++j) {
//       ft_set_bit(dst_key[i], j, ft_get_bit((const ubyte *)&src_key[i], PC2[j]
//       - 1));
//     }
//   }
// }

static void shiftLeft(const ubyte *src, int len, int times, ubyte *dst) {
  int i, t;
  for (i = 0; i <= len; ++i) {
    ft_set_bit(dst, i, ft_get_bit(src, i));
  }
  for (t = 1; t <= times; ++t) {
    int temp = ft_get_bit(dst, 0);
    for (i = 1; i <= len; ++i) {
      ft_set_bit(dst, i - 1, ft_get_bit(dst, i));
    }
    ft_set_bit(dst, len - 1, temp);
  }
}

#define INT_BITS 32

typedef ubyte t_des_subkeys[17][6]; /* 17 sets of 48 bits */
// typedef uint64_t t_des_subkeys[17]; /* 17 sets of 64 bits */
static void getSubKeys(t_uint64 key, t_des_subkeys ks) {
  ubyte kp[8];
  int i, j;

  /* intialize */
  uint64_t c[17];
  uint32_t d[17];

  ft_memset(c, 0, sizeof(c));
  ft_memset(kp, 0, sizeof(kp));
  ft_memset(d, 0, sizeof(d));
  ft_memset(ks, 0, sizeof(t_des_subkeys));
  /* permute 'key' using table PC1 */

  // ft_des_subkeys_permute1(kp, &key);
  // ft_des_subkeys_permute1(kpcopy, &key);
  for (i = 0; i < 56; ++i) {
    ft_set_bit(kp, i, ft_get_bit((const ubyte *)&key, PC1[i] - 1));
  }

  /* split 'kp' in half and process the resulting series of 'c' and 'd' */
  for (i = 0; i < 28; ++i) {
    ft_set_bit((ubyte *)&c[0], i, ft_get_bit(kp, i));
    ft_set_bit((ubyte *)&d[0], i, ft_get_bit(kp, i + 28));
  }

  for (i = 1; i < 17; ++i) {
    shiftLeft((const ubyte *)&c[i - 1], 28, SHIFTS[i - 1], (ubyte *)&c[i]);
    shiftLeft((const ubyte *)&d[i - 1], 28, SHIFTS[i - 1], (ubyte *)&d[i]);
  }

  /* merge 'd' into 'c' */
  for (i = 1; i < 17; ++i) {
    for (j = 28; j < 56; ++j) {
      ft_set_bit((ubyte *)&c[i], j, ft_get_bit((const ubyte *)&d[i], j - 28));
    }
  }

  for (int i = 1; i < 17; ++i) {
    for (int j = 0; j < 48; ++j) {
      ft_set_bit(ks[i], j, ft_get_bit((const ubyte *)&c[i], PC2[j] - 1));
    }
  }
}

void ft_des_gensubkeys(t_uint64 key, t_des_subkeys ks, int reverse) {
  getSubKeys(key, ks);

  if (reverse) {
    for (int i = 1; i < 9; ++i) {
      for (int j = 0; j < 6; ++j) {
        ubyte temp = ks[i][j];
        ks[i][j] = ks[17 - i][j];
        ks[17 - i][j] = temp;
      }
    }
  }
}
