/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 03:38:51 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/12 16:55:04 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TO_H
#define FT_TO_H

#include "../ft_libft_global.h"

int ft_atoi(const char *nptr);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_itoa(int input, char *buffer, int radix);
size_t ft_nbrlen(int n);
uint64_t ft_hextoi(char *hex);

#endif
