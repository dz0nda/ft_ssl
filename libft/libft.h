/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:43:25 by dz0nda            #+#    #+#             */
/*   Updated: 2021/06/23 19:16:06 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./src/bits/ft_bits.h"
# include "./src/is/ft_is.h"
# include "./src/mem/ft_mem.h"
# include "./src/str/ft_str.h"
# include "./src/put/ft_put.h"
# include "./src/to/ft_to.h"

# define FT_EXOK	  0
# define FT_EXFAIL	1

# define FT_TRUE  	1
# define FT_FALSE 	0


typedef unsigned char t_uchar;
typedef uint8_t       t_uint8;
typedef uint16_t      t_uint16;
typedef uint32_t      t_uint32;
typedef uint64_t      t_uint64;

#endif
