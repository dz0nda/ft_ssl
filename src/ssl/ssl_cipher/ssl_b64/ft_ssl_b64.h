/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_base64.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:32 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 08:01:49 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_BASE64_H
#define FT_SSL_BASE64_H

#include "../../../crypto/cipher/b64/ft_b64.h"

typedef int t_ftssl_cipher_ft(int argc, char *argv[]);

typedef enum e_ssl_b64_mode {
  FT_SSL_B64_ENCODE,
  FT_SSL_B64_DECODE,
  FT_SSL_B64_MODE,
} t_ssl_b64_mode;

typedef struct s_ssl_base64_option {
  int mode;
  char *input;
  char *output;
} t_ssl_b64_opt;

typedef struct s_ssl_base64_context {
  char *src;
  char *dst;
  int src_len;
  int dst_len;
} t_ssl_b64_ctx;

typedef struct s_ssl_base64 {
  int argi;
  // t_ssl_base64_dist	dist;
  t_ssl_b64_opt opt;
  // t_uchar *msg;
  // t_uchar *
} t_ssl_base64;

/*
**	Dispatcher struct
*/

typedef enum e_ssl_base64_opt_key {
  Ft_ssl_b64_opt_D,
  Ft_ssl_b64_opt_E,
  Ft_ssl_b64_opt_I,
  Ft_ssl_b64_opt_O,
  Ft_ssl_b64_opt
} t_ssl_b64_opt_key;

typedef void t_ssl_base64_ft(unsigned char *dst, size_t dst_len,
                             unsigned char *src, size_t src_len);
typedef int t_ssl_b64_opt_ft(t_ssl_base64 *ctx, int argc, char *argv[]);

typedef struct s_ssl_base64_option_dispatch {
  int opt_key;
  char *opt_name;
  t_ssl_b64_opt_ft *opt_dist;
} t_ssl_b64_opt_d;

typedef struct s_ssl_base64_dispatch {
  int mode;
  t_ssl_base64_ft *base64_mode;
} t_ssl_base64_d;

/*
**	BASE64
*/

int ft_ssl_base64(int argc, char *argv[]);
int ft_ssl_b64_option(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_base64_error(t_ssl_base64 *ctx, int argc, char *argv[]);

/*
**	Options
*/
int ft_ssl_base64_parse(t_ssl_base64 *ctx, int argc, char *argv[]);

// int ft_ssl_b64_option(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_b64_opt_d(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_b64_opt_e(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_b64_opt_i(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_b64_opt_o(t_ssl_base64 *ctx, int argc, char *argv[]);

#endif
