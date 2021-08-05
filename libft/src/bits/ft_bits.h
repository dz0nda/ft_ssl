/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 03:34:07 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/16 13:01:40 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BITS_H
# define FT_BITS_H

# include "../put/ft_put.h"

# define SHOW(T,V) do { T x = V; ft_printb(#V, (unsigned char*) &x, sizeof(x)); } while(0)

unsigned int ft_align_bits(size_t offset, size_t align);

void ft_printb_byte(char val);
void ft_printb(const char *var, unsigned char *bytes, size_t num_bytes);
void ft_printb_be(const char *var, unsigned char *bytes, size_t num_bytes);
void ft_printb_le(const char *var, unsigned char *bytes, size_t num_bytes);

uint32_t ft_rotl(uint32_t word, uint32_t bits);
uint32_t ft_rotr(uint32_t word, uint32_t bits);

uint32_t ft_rotr_uint32(uint32_t word, uint32_t bits);
uint32_t ft_rotl_uint32(uint32_t word, uint32_t bits);
uint32_t ft_shiftr_uint32(uint32_t word, uint32_t bits);
uint32_t ft_shiftl_uint32(uint32_t word, uint32_t bits);
uint32_t ft_swap_uint32(uint32_t *val);

uint64_t ft_rotr_uint64(uint64_t word, uint64_t bits);
uint64_t ft_rotl_uint64(uint64_t word, uint64_t bits);
uint64_t ft_shiftr_uint64(uint64_t word, uint64_t bits);
uint64_t ft_shiftl_uint64(uint64_t word, uint64_t bits);
uint64_t ft_swap_uint64(uint64_t *val);

#endif
