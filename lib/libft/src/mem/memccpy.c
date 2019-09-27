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

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    unsigned char   *d;
    unsigned char   *s;
    unsigned char   ch;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    ch = (unsigned char)c;
    while (n-- > 0)
    {
        *d=*s;
        if (*d==ch)
            return ((void *)(d + 1));
        d++;
        s++;
    }
	return (NULL);
}
