/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:11:52 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/23 22:05:16 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

uint32_t	ft_sha1_hash_f(int j, int b, int c, int d)
{
	if (j < 20)
		return (b & c) | ((~b) & d);
	else if (j < 40)
		return (b ^ c ^ d);
	else if (j < 60)
		return (b & c) | (b & d) | (c & d);
	return (b ^ c ^ d);
}

uint32_t	ft_sha1_hash_k(int j)
{
	if (j < 20)
		return (0x5A827999);
	else if (j < 40)
		return (0x6ED9EBA1);
	else if (j < 60)
		return (0x8F1BBCDC);
	return (0xCA62C1D6);
}
