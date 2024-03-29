

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/07/13 04:44:14 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

const static ubyte E[] = {32, 1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,
                          8,  9,  10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
                          16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
                          24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};

const static ubyte S[][64] = {
    {14, 4,  13, 1, 2,  15, 11, 8,  3,  10, 6,  12, 5,  9,  0, 7,
     0,  15, 7,  4, 14, 2,  13, 1,  10, 6,  12, 11, 9,  5,  3, 8,
     4,  1,  14, 8, 13, 6,  2,  11, 15, 12, 9,  7,  3,  10, 5, 0,
     15, 12, 8,  2, 4,  9,  1,  7,  5,  11, 3,  14, 10, 0,  6, 13},
    {15, 1,  8,  14, 6,  11, 3,  4,  9,  7, 2,  13, 12, 0, 5,  10,
     3,  13, 4,  7,  15, 2,  8,  14, 12, 0, 1,  10, 6,  9, 11, 5,
     0,  14, 7,  11, 10, 4,  13, 1,  5,  8, 12, 6,  9,  3, 2,  15,
     13, 8,  10, 1,  3,  15, 4,  2,  11, 6, 7,  12, 0,  5, 14, 9},
    {10, 0,  9,  14, 6, 3,  15, 5,  1,  13, 12, 7,  11, 4,  2,  8,
     13, 7,  0,  9,  3, 4,  6,  10, 2,  8,  5,  14, 12, 11, 15, 1,
     13, 6,  4,  9,  8, 15, 3,  0,  11, 1,  2,  12, 5,  10, 14, 7,
     1,  10, 13, 0,  6, 9,  8,  7,  4,  15, 14, 3,  11, 5,  2,  12},
    {7,  13, 14, 3, 0,  6,  9,  10, 1,  2, 8, 5,  11, 12, 4,  15,
     13, 8,  11, 5, 6,  15, 0,  3,  4,  7, 2, 12, 1,  10, 14, 9,
     10, 6,  9,  0, 12, 11, 7,  13, 15, 1, 3, 14, 5,  2,  8,  4,
     3,  15, 0,  6, 10, 1,  13, 8,  9,  4, 5, 11, 12, 7,  2,  14},
    {2,  12, 4,  1,  7,  10, 11, 6,  8,  5,  3,  15, 13, 0, 14, 9,
     14, 11, 2,  12, 4,  7,  13, 1,  5,  0,  15, 10, 3,  9, 8,  6,
     4,  2,  1,  11, 10, 13, 7,  8,  15, 9,  12, 5,  6,  3, 0,  14,
     11, 8,  12, 7,  1,  14, 2,  13, 6,  15, 0,  9,  10, 4, 5,  3},
    {12, 1,  10, 15, 9, 2,  6,  8,  0,  13, 3,  4,  14, 7,  5,  11,
     10, 15, 4,  2,  7, 12, 9,  5,  6,  1,  13, 14, 0,  11, 3,  8,
     9,  14, 15, 5,  2, 8,  12, 3,  7,  0,  4,  10, 1,  13, 11, 6,
     4,  3,  2,  12, 9, 5,  15, 10, 11, 14, 1,  7,  6,  0,  8,  13},
    {4,  11, 2,  14, 15, 0, 8,  13, 3,  12, 9, 7,  5,  10, 6, 1,
     13, 0,  11, 7,  4,  9, 1,  10, 14, 3,  5, 12, 2,  15, 8, 6,
     1,  4,  11, 13, 12, 3, 7,  14, 10, 15, 6, 8,  0,  5,  9, 2,
     6,  11, 13, 8,  1,  4, 10, 7,  9,  5,  0, 15, 14, 2,  3, 12},
    {13, 2,  8,  4, 6,  15, 11, 1,  10, 9,  3,  14, 5,  0,  12, 7,
     1,  15, 13, 8, 10, 3,  7,  4,  12, 5,  6,  11, 0,  14, 9,  2,
     7,  11, 4,  1, 9,  12, 14, 2,  0,  6,  10, 13, 15, 3,  5,  8,
     2,  1,  14, 7, 4,  10, 8,  13, 15, 12, 9,  0,  3,  5,  6,  11}};

const static ubyte P[] = {16, 7, 20, 21, 29, 12, 28, 17, 1,  15, 23,
                          26, 5, 18, 31, 10, 2,  8,  24, 14, 32, 27,
                          3,  9, 19, 13, 30, 6,  22, 11, 4,  25};

void ft_des_f_expansion(ubyte *er, ubyte *r) {
  int i = 0;

  /* permute 'r' using table E */
  for (i = 0; i < 48; ++i) {
    ft_set_bit(er, i, ft_get_bit(r, E[i] - 1));
  }
}

void ft_des_f_key_mixing(ubyte *er, ubyte *ks) {
  int i = 0;

  /* xor 'er' with 'ks' and store back into 'er' */
  for (i = 0; i < 6; ++i) {
    er[i] ^= ks[i];
  }
}

void ft_des_f_sbox(ubyte out[4], ubyte in[6]) {
  int i = 0;

  /* process 'er' six bits at a time and store resulting four bits in 'sr' */
  for (i = 0; i < 8; ++i) {
    int j = i * 6;
    int b[6];
    int k, row, col, m, n;

    // ft_memcpy(b, in, 6);
    for (k = 0; k < 6; ++k) {
      b[k] = ft_get_bit(in, j + k) != 0 ? 1 : 0;
    }

    row = 2 * b[0] + b[5];
    col = 8 * b[1] + 4 * b[2] + 2 * b[3] + b[4];
    m = S[i][row * 16 + col]; /* apply table s */
    n = 1;

    while (m > 0) {
      int p = m % 2;
      ft_set_bit(out, (i + 1) * 4 - n, p == 1);
      m /= 2;
      n++;
    }
  }
}

void ft_des_f_permutation(ubyte *sp, ubyte *sr) {
  int i = 0;

  /* permute sr using table P */
  for (i = 0; i < 32; ++i) {
    ft_set_bit(sp, i, ft_get_bit(sr, P[i] - 1));
  }
}

/*
 * Function used in processing the messages
 *
 * r: an array of bytes to be processed
 * ks: one of the subkeys to be used for processing
 * sp: output from the processing
 */
void ft_des_f(ubyte *r, ubyte *ks, ubyte *sp) {
  ubyte er[6]; /* 48 bits */
  ubyte sr[4]; /* 32 bits */

  ft_memset(er, 0, sizeof(er));
  ft_memset(sr, 0, sizeof(sr));

  ft_des_f_expansion(er, r);
  ft_des_f_key_mixing(er, ks);
  ft_des_f_sbox(sr, er);
  ft_des_f_permutation(sp, sr);
}