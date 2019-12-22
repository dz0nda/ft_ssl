/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 20:10:57 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 02:58:56 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_mem.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    unsigned char   *d;
    unsigned char   *s;
    unsigned char   ch;
    size_t i;

    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    ch = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        if (d[i] == ch)
            return ((void *)(d + i + 1));
        i++;
    }
	return (NULL);
}
