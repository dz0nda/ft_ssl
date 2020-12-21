/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:32 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/21 13:01:45 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_SSL_CIPHER_H
# define FT_SSL_CIPHER_H

# include "../../ft_ssl_global.h"

# define FT_SSL_CIPHER_NOT_FOUND      -42

typedef enum		e_ftssl_cipher_dist_enum
{
	FT_SSL_BASE64,
	FT_SSL_DES,
	FT_SSL_CIPHER_DIST
}					t_ftssl_cipher_dist_e;

typedef struct      s_ftssl_cipher_dist
{
    char    *dist_name;
    int     dist_key;
}                   t_ftssl_cipher_dist;

int					ft_ssl_cipher(int argc, char *argv[]);
int     			ft_ssl_cipher_dist(int argc, char *argv[]);

#endif
