/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/11 20:58:26 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H

# include "../../../ft_ssl_global.h"

#define SHOW(T,V) do { T x = V; print_bits(#T, #V, (unsigned char*) &x, sizeof(x)); } while(0)


typedef struct		s_base64_context
{
	int		iblock;
	char 	state[3];
	char 	words[4];
	uint32_t base64_state : 24;
}					t_base64_ctx;


void 	ft_ssl_base64(char *msg);
void 	ft_ssl_base64_decode(char *msg);


void        print_byte_as_bits(char val);
void 				print_bits(char * ty, char * val, unsigned char * bytes, size_t num_bytes);



#endif
