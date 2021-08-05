/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/29 13:59:59 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H

# include "../../../ft_ssl_global.h"

/*
**	Encode
*/
void 	ft_b64_enc(unsigned char *dst, size_t dst_len, unsigned char *src, size_t src_len);

/*
**	Decode
*/
void 	ft_b64_dec(unsigned char *dst, size_t dst_len, unsigned char *src, size_t src_len);

/*
**	Tools
*/
int ft_base64_get_encoded_len(int src_len);
int ft_base64_get_decoded_len(unsigned char *src, int src_len);

void        print_byte_as_bits(char val);
void 				print_bits(char * ty, char * val, unsigned char * bytes, size_t num_bytes);



#endif
