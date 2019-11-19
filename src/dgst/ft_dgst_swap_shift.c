/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_swap_shift.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 12:14:03 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 12:14:45 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

uint32_t		ft_shift_right_x32(uint32_t word, uint32_t bits)
{
	return (word >> bits);
}

uint32_t        ft_swap_uint_x32( uint32_t val )
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

uint64_t	ft_shift_right_x64(uint64_t word, uint64_t bits)
{
	return (word >> bits);
}

uint64_t    ft_swap_uint_x64(uint64_t val)
{
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
    return (val << 32) | (val >> 32);
}
