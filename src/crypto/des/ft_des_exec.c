/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/12 17:58:00 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

const static ubyte IP[] = {58, 50, 42, 34, 26, 18, 10, 2,  60, 52, 44, 36, 28,
                           20, 12, 4,  62, 54, 46, 38, 30, 22, 14, 6,  64, 56,
                           48, 40, 32, 24, 16, 8,  57, 49, 41, 33, 25, 17, 9,
                           1,  59, 51, 43, 35, 27, 19, 11, 3,  61, 53, 45, 37,
                           29, 21, 13, 5,  63, 55, 47, 39, 31, 23, 15, 7};

const static ubyte IP2[] = {40, 8,  48, 16, 56, 24, 64, 32, 39, 7,  47, 15, 55,
                            23, 63, 31, 38, 6,  46, 14, 54, 22, 62, 30, 37, 5,
                            45, 13, 53, 21, 61, 29, 36, 4,  44, 12, 52, 20, 60,
                            28, 35, 3,  43, 11, 51, 19, 59, 27, 34, 2,  42, 10,
                            50, 18, 58, 26, 33, 1,  41, 9,  49, 17, 57, 25};

void ft_des_permutation_initial(ubyte mp[8], const t_uchar *msg) {
  int i, j;

  for (i = 0; i < 64; ++i) {
    ft_set_bit(mp, i, ft_get_bit(msg, IP[i] - 1));
  }
}

void ft_des_permutation_final(char *cipher, ubyte e[8]) {
  int i, j;

  for (i = 0; i < 64; ++i) {
    ft_set_bit((t_uint8 *)cipher, i, ft_get_bit(e, IP2[i] - 1));
  }
}

void ft_des_exec(const t_uchar *msg, t_des_subkeys ks, char *cipher) {
  ubyte left[17][4];  /* 32 bits */
  ubyte right[17][4]; /* 32 bits */
  ubyte mp[8];        /* 64 bits */
  ubyte e[8];         /* 64 bits */
  int i, j;
  // bool boolean;

  uint32_t l[17];
  uint32_t r[17];

  /* permute 'message' using table IP */
  ft_des_permutation_initial(mp, msg);

  /* split 'mp' in half and process the resulting series of 'l' and 'r */
  ft_memcpy(&l[0], &mp[0], 4);
  ft_memcpy(&r[0], &mp[4], 4);

  for (i = 1; i < 17; ++i) {
    uint32_t fs;

    ft_memcpy(&l[i], &r[i - 1], 4);
    ft_des_f((ubyte *)&r[i - 1], (ubyte *)ks[i], (ubyte *)&fs);
    l[i - 1] ^= fs;
    ft_memcpy(&r[i], &l[i - 1], 4);
  }

  /* amalgamate r[16] and l[16] (in that order) into 'e' */
  ft_memcpy(&e[0], &r[16], 4);
  ft_memcpy(&e[4], &l[16], 4);

  ft_des_permutation_final(cipher, e);
}