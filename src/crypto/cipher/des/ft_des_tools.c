/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/30 14:51:29 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

uint64_t hex2int(char *hex) {
    uint64_t val = 0;
    while (*hex) {
        // get current character then increment
        uint8_t byte = *hex++; 
        // transform hex character to the 4bit equivalent number, using the ascii table indexes
        if (byte >= '0' && byte <= '9')
					val = (val << 4) | ((byte - 48) & 0xF);
        else if (byte >= 'A' && byte <='F')
					val = (val << 4) | ((byte - 55) & 0xF);
        else if (byte >= 'a' && byte <='f')
					val = (val << 4) | ((byte - 87) & 0xF);
				else
					return 0;
    }
    // return val;
    return (ft_swap_uint64(&val));
}

void ft_set_bit(t_uint8 *dst, int index, int value) {
    int cell = index / 8;
    int bit = 7 - index % 8;
    if (value == 0) {
        dst[cell] &= ~(1 << bit);
    } else {
        dst[cell] |= (1 << bit);
    }
}

int ft_get_bit(const t_uint8 *src, int index) {
    int cell = index / 8;
    int bit = 7 - index % 8;
    return (src[cell] & (1 << bit)) != 0;
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
				printf(" ");
    }
    puts("");
}

