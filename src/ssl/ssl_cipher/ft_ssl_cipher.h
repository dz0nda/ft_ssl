/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:32 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 09:46:26 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_CIPHER_H
#define FT_SSL_CIPHER_H

#include "../../crypto/cipher/b64/ft_b64.h"
#include "../../crypto/cipher/des/ft_des.h"
#include "../../crypto/cipher/kdf/ft_kdf.h"
#include "./ssl_b64/ft_ssl_b64.h"
#include "./ssl_des/ft_ssl_des.h"

#define FT_SSL_CIPHER_NOT_FOUND -42

#define FT_SSL_CIPHER_ENCODE 0
#define FT_SSL_CIPHER_DECODE 1

typedef int t_ssl_cipher_ft(int argc, char *argv[]);

typedef enum e_ssl_cipher_key {
  FT_SSL_CIPHER_BASE64,
  FT_SSL_CIPHER_DES,
  FT_SSL_CIPHER_DES_ECB,
  FT_SSL_CIPHER_DES_CBC,
  FT_SSL_CIPHER_DIST
} t_ssl_cipher_key;

typedef struct s_ssl_cipher_dist {
  char *dist_name;
  int dist_key;
  t_ssl_cipher_ft *dist_ft;
} t_ssl_cipher_dist;

typedef struct s_ssl_cipher {
  int argi;
  t_ssl_cipher_dist dist;
} t_ssl_cipher;

int ft_ssl_cipher(int argc, char *argv[]);

#endif
