/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:32 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/12 15:37:30 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_CIPHER_H
# define FT_SSL_CIPHER_H

# include "cli/ft_enc_cli.h"

# include "../../crypto/b64/ft_b64.h"
# include "../../crypto/des/ft_des.h"
# include "../../crypto/kdf/ft_kdf.h"
# include "ssl_b64/ft_ssl_b64.h"
# include "ssl_des/ft_ssl_des.h"

# define FT_SSL_CIPHER_NOT_FOUND -42

# define FT_SSL_CIPHER_ENCODE 0
# define FT_SSL_CIPHER_DECODE 1

typedef int t_ssl_cipher_ft(int argc, char* argv[]);

typedef enum e_ssl_cipher_key {
  FT_SSL_CIPHER_BASE64,
  FT_SSL_CIPHER_DES,
  FT_SSL_CIPHER_DES_ECB,
  FT_SSL_CIPHER_DES_CBC,
  FT_SSL_CIPHER_DIST
} t_ssl_cipher_key;

// # define FT_ENC_BASE64   "base64"
// # define FT_ENC_DES      "des"
// # define FT_ENC_DES_ECB  "des-ecb"
// # define FT_ENC_DES_CBC  "des-cbc"

// typedef enum e_ciphername {
//   FT_DES,
//   FT_ECB,
//   FT_CBC,
// } t_cipher; 

// typedef enum e_enc_command {
//   FT_,
//   FT_ECB,
//   FT_CBC,
// } t_enc_cmd; 

/*
**	Options
*/

// typedef enum e_enc_option {
//   FT_ENC_OPT_A,   // Perform base64 encoding/decoding (alias -base64)
//   FT_ENC_OPT_D,   // Decrypt the input data
//   FT_ENC_OPT_E,   // Encrypt the input data (default)
//   FT_ENC_OPT_I,   // Input file to read from (default stdin)
//   FT_ENC_OPT_K,   // Key to use, specified as a hexadecimal string
//   FT_ENC_OPT_O,   // Output file to write to (default stdout)
//   FT_ENC_OPT_P,   // Password in ascii
//   FT_ENC_OPT_S,   // Salt to use, specified as a hexadecimal string
//   FT_ENC_OPT_V,   // IV to use, specified as a hexadecimal string
//   FT_ENC_OPT_MAX
// } t_enc_opt;

// typedef struct s_enc t_enc;
// typedef int t_enc_crypt(t_enc* ctx, int argc, char* argv[]);
// typedef int t_enc_cypher(char* key, char* msg, int msg_len, char** cipher, char* iv);

// # define FT_PASS_LEN    sizeof(char) * 256
// # define FT_KEY_LEN     sizeof(char) * 17
// # define FT_SALT_LEN    sizeof(char) * 17
// # define FT_IV_LEN      sizeof(char) * 17

typedef struct s_cipher
{
  char pass[FT_PASS_LEN];
  char key[FT_KEY_LEN];
  char salt[FT_SALT_LEN];
  char iv[FT_IV_LEN];
} t_ciph;



typedef struct s_enc {
  char* in;
  char* out;
  // t_enc_crypt* crypt;
  t_enc_cyph_ft* cipher[2];
  char pass[FT_PASS_LEN];
  char key[FT_KEY_LEN];
  char salt[FT_SALT_LEN];
  char iv[FT_IV_LEN];
  t_enc_opt enc_opt[FT_ENC_OPT_MAX];
  // t_enc_cip
  char* ctx[FT_ENC_OPT_MAX];
} t_enc;

int ft_enc(int argc, char* argv[]);
int ft_enc_get_key(t_ciph* enc_ciph, char* ctx[FT_ENC_OPT_MAX]);


typedef struct s_ssl_cipher_dist {
  char* dist_name;
  int  dist_key;
  t_ssl_cipher_ft* dist_ft;
} t_ssl_cipher_dist;

typedef struct s_ssl_cipher {
  int argi;
  t_ssl_cipher_dist dist;
} t_ssl_cipher;

int		ft_enc_old(int argc, char* argv[]);


#endif
