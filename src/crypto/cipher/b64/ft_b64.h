/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 08:08:49 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_B64_H
# define FT_B64_H

# include "../../../ft_ssl_global.h"

/*
**	Encode
*/
void 	ft_b64_enc(t_uchar *dst, size_t dst_len, t_uchar *src, size_t src_len);

/*
**	Decode
*/
void 	ft_b64_dec(t_uchar *dst, size_t dst_len, t_uchar *src, size_t src_len);

/*
**	Tools
*/
int ft_b64_get_encoded_len(int src_len);
int ft_b64_get_decoded_len(t_uchar *src, int src_len);

void        print_byte_as_bits(char val);
void 				print_bits(char * ty, char * val, t_uchar * bytes, size_t num_bytes);



#endif
