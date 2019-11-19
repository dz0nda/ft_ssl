/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_rotate.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 12:11:37 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 12:12:16 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

uint32_t		ft_rotate_left_x32(uint32_t word, uint32_t bits)
{
	return ((word << bits) | (word >> (32 - bits)));
}

uint32_t		ft_rotate_right_x32(uint32_t word, uint32_t bits)
{
	return ((word >> bits) | (word << (32 - bits)));
}

uint64_t    ft_rotate_left_x64(uint64_t word, uint64_t bits)
{
	return ((word << bits) | (word >> (64 - bits)));
}

uint64_t    ft_rotate_right_x64(uint64_t word, uint64_t bits)
{
	return ((word >> bits) | (word << (64 - bits)));
}
