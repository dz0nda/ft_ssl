/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:41:54 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/29 17:45:15 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bits.h"

uint32_t	ft_rotr_uint32(uint32_t word, uint32_t bits)
{
  return ((word >> bits) | (word << (32 - bits)));
}

uint32_t	ft_rotl_uint32(uint32_t word, uint32_t bits)
{
	return ((word << bits) | (word >> (32 - bits)));
}