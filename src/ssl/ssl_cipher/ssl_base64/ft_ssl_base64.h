/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_base64.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:32 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/16 14:02:03 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_BASE64_H
#define FT_SSL_BASE64_H

#include "../../../crypto/cipher/base64/ft_base64.h"

// #define FT_SSL_BASE64_ENCODE 0
// #define FT_SSL_BASE64_DECODE 1

// #define SHOW(T, V)                                      \
//   do {                                                  \
//     T x = V;                                            \
//     print_bits(#T, #V, (unsigned char *)&x, sizeof(x)); \
//   } while (0)

typedef int t_ftssl_cipher_ft(int argc, char *argv[]);

typedef enum  e_ssl_b64_mode
{
	FT_SSL_B64_ENCODE,
	FT_SSL_B64_DECODE,
	FT_SSL_B64_MODE,
}	t_ssl_b64_mode;

typedef struct s_ssl_base64_option {
  int mode;
  char *input;
  char *output;
} t_ssl_base64_opt;

typedef struct s_ssl_base64 {
  int argi;
  // t_ssl_base64_dist	dist;
  t_ssl_base64_opt opt;

} t_ssl_base64;

/*
**	Dispatcher struct
*/

typedef enum e_ssl_base64_opt_key {
  FT_SSL_BASE64_OPT_D,
  FT_SSL_BASE64_OPT_E,
  FT_SSL_BASE64_OPT_I,
  FT_SSL_BASE64_OPT_O,
  FT_SSL_BASE64_OPT
} t_ssl_base64_opt_key;

typedef void t_ssl_base64_ft(unsigned char *dst, size_t dst_len, unsigned char *src, size_t src_len);
typedef int t_ssl_base64_opt_ft(t_ssl_base64 *ctx, int argc, char *argv[]);

typedef struct s_ssl_base64_option_dispatch {
  int opt_key;
  char *opt_name;
  t_ssl_base64_opt_ft *opt_dist;
} t_ssl_base64_opt_d;

typedef struct s_ssl_base64_dispatch {
  int mode;
  t_ssl_base64_ft *base64_mode;
} t_ssl_base64_d;

/*
**	BASE64
*/

int ft_ssl_base64(int argc, char *argv[]);
int ft_ssl_base64_option(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_base64_error(t_ssl_base64 *ctx, int argc, char *argv[]);

/*
**	Options
*/
int ft_ssl_base64_parse(t_ssl_base64 *ctx, int argc, char *argv[]);

// int ft_ssl_base64_option(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_base64_opt_d(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_base64_opt_e(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_base64_opt_i(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_base64_opt_o(t_ssl_base64 *ctx, int argc, char *argv[]);

#endif
