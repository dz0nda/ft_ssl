/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:12:09 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/03 12:58:35 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dgst.h"

int			ft_sha256_wsigma0(uint32_t word)
{
	return (ft_rotr_uint32(word, 7) ^ ft_rotr_uint32(word, 18)
		^ ft_shiftr_uint32(word, 3));
}

int			ft_sha256_wsigma1(uint32_t word)
{
	return (ft_rotr_uint32(word, 17) ^ ft_rotr_uint32(word, 19)
		^ ft_shiftr_uint32(word, 10));
}

int			ft_sha256_sigma0(uint32_t state[8], uint32_t w, unsigned int i)
{
	const uint32_t	k[64] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
		0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
		0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
		0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
		0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
		0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
		0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
		0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
		0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };
	uint32_t		sigma;
	uint32_t		ch;

	sigma = ft_rotr_uint32(state[4], 6) ^ ft_rotr_uint32(state[4], 11)
			^ ft_rotr_uint32(state[4], 25);
	ch = (state[4] & state[5]) ^ ((~state[4]) & state[6]);
	return (state[7] + sigma + ch + k[i] + w);
}

int			ft_sha256_sigma1(uint32_t state[8])
{
	uint32_t	sigma;
	uint32_t	maj;

	sigma = ft_rotr_uint32(state[0], 2) ^ ft_rotr_uint32(state[0], 13)
			^ ft_rotr_uint32(state[0], 22);
	maj = (state[0] & state[1]) ^ (state[0] & state[2]) ^ (state[1] & state[2]);
	return (sigma + maj);
}
