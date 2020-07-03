/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_utils.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 12:14:03 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 15:58:43 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

uint32_t    ft_shift_x32(uint32_t word, uint32_t bits, t_dgst_rot_e rot)
{
    if (rot == FT_ROT_RIGHT)
	    return (word >> bits);
    return (word << bits);
}

uint32_t	ft_rotate_x32(uint32_t word, uint32_t bits, t_dgst_rot_e rot)
{
	if (rot == FT_ROT_RIGHT)
		return ((word >> bits) | (word << (32 - bits)));
	return ((word << bits) | (word >> (32 - bits)));
}

uint64_t    ft_shift_x64(uint64_t word, uint64_t bits, t_dgst_rot_e rot)
{
    if (rot == FT_ROT_RIGHT)
	    return (word >> bits);
    return (word << bits);
}

uint64_t    ft_rotate_x64(uint64_t word, uint64_t bits, t_dgst_rot_e rot)
{
	if (rot == FT_ROT_RIGHT)
		return ((word >> bits) | (word << (64 - bits)));
	return ((word << bits) | (word >> (64 - bits)));
}

uint64_t    ft_swap_uint(uint64_t val, size_t len)
{
    size_t i;
    char c;
    uint8_t *up;

    i = 0;
    c = 0;
    up = (uint8_t *)&val;
    len -= 1;
    while (i < len)
    {
        c = up[i];
        up[i++] = up[len];
        up[len--] = c;
    }
    return (val);
}
