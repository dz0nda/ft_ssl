/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mem.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 03:34:07 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 03:38:18 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../str/ft_str.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memalloc(size_t size);
void    ft_memdel(void **ap);

#endif
