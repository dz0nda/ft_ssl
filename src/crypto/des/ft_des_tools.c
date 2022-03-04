/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/12 17:00:37 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

int ft_des_get_encoded_len(int msg_len) {
  int padByte = 8 - msg_len % 8;
  return (msg_len + padByte);
}

// uint64_t hex2int(char *hex) {
//   uint64_t val = 0;
//   while (*hex) {
//     // get current character then increment
//     uint8_t byte = *hex++;
//     // transform hex character to the 4bit equivalent number, using the ascii
//     // table indexes
//     if (byte >= '0' && byte <= '9')
//       val = (val << 4) | ((byte - 48) & 0xF);
//     else if (byte >= 'A' && byte <= 'F')
//       val = (val << 4) | ((byte - 55) & 0xF);
//     else if (byte >= 'a' && byte <= 'f')
//       val = (val << 4) | ((byte - 87) & 0xF);
//     else
//       return 0;
//   }
//   // return val;
//   return (ft_swap_uint64(&val));
// }

// void ft_set_bit(t_uint8 *dst, int index, int value) {
//   int cell = index / 8;
//   int bit = 7 - index % 8;
//   if (value == 0) {
//     dst[cell] &= ~(1 << bit);
//   } else {
//     dst[cell] |= (1 << bit);
//   }
// }

// int ft_get_bit(const t_uint8 *src, int index) {
//   int cell = index / 8;
//   int bit = 7 - index % 8;
//   return (src[cell] & (1 << bit)) != 0;
// }

// void printBits(size_t const size, void const *const ptr) {
//   unsigned char *b = (unsigned char *)ptr;
//   unsigned char byte;
//   int i, j;

//   for (i = size - 1; i >= 0; i--) {
//     for (j = 7; j >= 0; j--) {
//       byte = (b[i] >> j) & 1;
//       printf("%u", byte);
//     }
//     printf(" ");
//   }
//   puts("");
// }

// #ifndef HEXDUMP_COLS
// #define HEXDUMP_COLS 16
// #endif

// void hexdump(void *mem, unsigned int len) {
//   unsigned int i, j;

//   for (i = 0;
//        i <
//        len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) :
//        0); i++) {
//     /* print offset */
//     if (i % HEXDUMP_COLS == 0) {
//       printf("0x%06x: ", i);
//     }

//     /* print hex data */
//     if (i < len) {
//       printf("%02x ", 0xFF & ((char *)mem)[i]);
//     } else /* end of block, just aligning for ASCII dump */
//     {
//       printf("   ");
//     }

//     /* print ASCII dump */
//     if (i % HEXDUMP_COLS == (HEXDUMP_COLS - 1)) {
//       for (j = i - (HEXDUMP_COLS - 1); j <= i; j++) {
//         if (j >= len) /* end of block, not really printing */
//         {
//           putchar(' ');
//         } else if (isprint(((char *)mem)[j])) /* printable char */
//         {
//           putchar(0xFF & ((char *)mem)[j]);
//         } else /* other char */
//         {
//           putchar('.');
//         }
//       }
//       putchar('\n');
//     }
//   }
// }