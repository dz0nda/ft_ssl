/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/11 20:01:29 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <arpa/inet.h>
#include <errno.h>

void print_byte_as_bits(char val) {
  for (int i = 7; 0 <= i; i--) {
    printf("%c", (val & (1 << i)) ? '1' : '0');
  }
}

void print_bits(char * ty, char * val, unsigned char * bytes, size_t num_bytes) {
  printf("(%*s) %*s = [ ", 15, ty, 16, val);
  for (size_t i = 0; i < num_bytes; i++) {
    print_byte_as_bits(bytes[i]);
    printf(" ");
  }
  printf("]\n");
}
