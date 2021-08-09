/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:32 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 08:48:12 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_DES_H
#define FT_SSL_DES_H

#include "../../../crypto/cipher/des/ft_des.h"
#include "../ssl_b64/ft_ssl_b64.h"

#define FT_SSL_DES_ENCODE 0
#define FT_SSL_DES_DECODE 1
#define FT_DES_ECB_ENC 0
#define FT_DES_ECB_DEC 1
#define FT_DES_CBC_ENC 0
#define FT_DES_CBC_DEC 1

// #define SHOW(T,V) do { T x = V; print_bits(#T, #V, (unsigned char*) &x,
// sizeof(x)); } while(0)

#define FT_DES_B64_CODE 1

typedef struct s_ssl_des_option {
  int mode;
  int encode;
  char *input;
  char *output;
  char salt[17];
  char pass[256];
  char key[17];
  char iv[17];
} t_ssl_des_opt;

typedef struct s_ssl_des {
  int argi;
  t_ssl_des_opt opt;
} t_ssl_des;

/*
**	Dispatcher struct
*/

typedef enum e_ftssl_cipher_opt_des_key {
  FT_SSL_DES_OPT_A,
  FT_SSL_DES_OPT_D,
  FT_SSL_DES_OPT_E,
  FT_SSL_DES_OPT_I,
  FT_SSL_DES_OPT_K,
  FT_SSL_DES_OPT_O,
  FT_SSL_DES_OPT_P,
  FT_SSL_DES_OPT_S,
  FT_SSL_DES_OPT_V,
  FT_SSL_DES_OPT
} t_ssl_des_opt_des_key;

typedef int t_ssl_des_opt_ft(t_ssl_des *ctx, int argc, char *argv[]);
typedef int t_des_ecb_ft(char *key, char *msg, int msg_len, char **cipher);
typedef int t_des_cbc_ft(char *key, char *msg, int msg_len, char **cipher,
                         char *iv);

typedef struct s_ssl_des_option_dispatch {
  int opt_key;
  char *opt_name;
  t_ssl_des_opt_ft *opt_dist;
} t_ssl_des_opt_d;

typedef struct s_des_ecb_dispatch {
  int mode;
  t_des_ecb_ft *des_mode;
} t_des_ecb_d;

typedef struct s_des_cbc_dispatch {
  int mode;
  t_des_cbc_ft *des_mode;
} t_des_cbc_d;

/*
**	DES
*/

int ft_ssl_des_ecb(int argc, char *argv[]);
int ft_ssl_des_cbc(int argc, char *argv[]);
int ft_ssl_des_option(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_error(t_ssl_des *ctx, int argc, char *argv[]);

/*
**	Options
*/
int ft_ssl_des_parse(t_ssl_des *ctx, int argc, char *argv[]);

// int ft_ssl_b64_option(t_ssl_base64 *ctx, int argc, char *argv[]);
int ft_ssl_des_opt_a(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_opt_d(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_opt_e(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_opt_i(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_opt_k(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_opt_o(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_opt_p(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_opt_s(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_opt_v(t_ssl_des *ctx, int argc, char *argv[]);

/*
**	Execute
*/
int ft_ssl_des_exec(t_ssl_des *ctx, int argc, char *argv[]);
int ft_ssl_des_exec_pre_process(t_ssl_des *ctx);
int ft_ssl_des_exec_handle_password(t_ssl_des *ctx);
int ft_ssl_des_exec_handle_salt(t_ssl_des *ctx);
#endif
