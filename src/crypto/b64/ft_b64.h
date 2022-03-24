/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/20 20:25:02 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_B64_H
#define FT_B64_H

#include "../../ft_ssl_global.h"

/*
**	Encode
*/
int ft_b64_enc(char** dst, char* src, size_t src_len);

/*
**	Decode
*/
int ft_b64_dec(char** dst, char* src, size_t src_len);

/*
**	Tools
*/
int ft_b64_get_encoded_len(int src_len);
int ft_b64_get_decoded_len(t_uchar* src, int src_len);

void print_byte_as_bits(char val);
void print_bits(char* ty, char* val, t_uchar* bytes, size_t num_bytes);

#endif
