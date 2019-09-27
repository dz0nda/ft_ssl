/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 20:11:03 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 02:59:07 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_mem.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *m;
	unsigned char ch;

	m = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n-- > 0)
	{
		if (*m == ch)
			return ((void *)m);
		m++;
	}
	return (NULL);
}
