/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:42:12 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/29 20:30:37 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BITS_H
# define FT_BITS_H

# include <stdlib.h>

uint32_t	ft_rotr_uint32(uint32_t word, uint32_t bits);
uint32_t	ft_rotl_uint32(uint32_t word, uint32_t bits);
uint32_t  ft_shiftr_uint32(uint32_t word, uint32_t bits);
uint32_t  ft_shiftl_uint32(uint32_t word, uint32_t bits);
uint32_t  ft_swap_uint32(uint32_t *val);

uint64_t  ft_shiftr_uint64(uint64_t word, uint64_t bits);
uint64_t  ft_shiftl_uint64(uint64_t word, uint64_t bits);
uint64_t  ft_swap_uint64(uint64_t *val);

#endif