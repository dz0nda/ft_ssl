/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:41:54 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/30 14:59:34 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bits.h"
#include <stdio.h>

void ft_printb(const char *var, unsigned char *bytes, size_t num_bytes) {
  return (ft_printb_le(var, bytes, num_bytes));
}

void ft_printb_byte_be(char val) {
  for (int i = 0; i <= 7; i++) {
    ft_putchar((val & (1 << i)) ? '1' : '0');
  }
}

void ft_printb_byte_le(char val) {
  for (int i = 7; 0 <= i; i--) {
    ft_putchar((val & (1 << i)) ? '1' : '0');
  }
}

void ft_printb_be(const char *var, unsigned char *bytes, size_t num_bytes) {
  ft_putstr("("); ft_putstr(var); ft_putstr(") = [ ");
  for (size_t i = 0; i < num_bytes; i++) {
    ft_printb_byte_le(bytes[i]);
    ft_putchar(' ');
  }
  ft_putendl("]");
}

void ft_printb_le(const char *var, unsigned char *bytes, size_t num_bytes) {
  ft_putstr("("); ft_putstr(var); ft_putstr(") = [ ");
  for (int i = num_bytes - 1; i; i--) {
    ft_printb_byte_le(bytes[i]);
    ft_putchar(' ');
  }
  ft_printb_byte_le(bytes[0]);
  ft_putendl(" ]");
}