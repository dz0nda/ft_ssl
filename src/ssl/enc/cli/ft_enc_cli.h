/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_cli.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/12 15:49:58 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENC_CLI
# define FT_ENC_CLI

// # include "../ft_enc.h"
# include "../../../crypto/des/ft_des.h"

/*
**	Options
*/

// typedef int t_enc_opt_ft(t_enc* ctx, int argc, char* argv[]);

// typedef struct s_enc_option_dispatch {
//   char* opt;
//   t_enc_opt_ft* ft;
// } t_enc_opt_d;
# define FT_ENC_E 0
# define FT_ENC_D 1

# define FT_ENC_B64 0
# define FT_DEC_B64 1

typedef char* t_enc_opt_ft(char* ctx, int argc, char* argv[]);

typedef enum e_enc_option_key {
  FT_ENC_OPT_A,   // Perform base64 encoding/decoding (alias -base64)
  FT_ENC_OPT_D,   // Decrypt the input data
  FT_ENC_OPT_E,   // Encrypt the input data (default)
  FT_ENC_OPT_I,   // Input file to read from (default stdin)
  FT_ENC_OPT_K,   // Key to use, specified as a hexadecimal string
  FT_ENC_OPT_O,   // Output file to write to (default stdout)
  FT_ENC_OPT_P,   // Password in ascii
  FT_ENC_OPT_S,   // Salt to use, specified as a hexadecimal string
  FT_ENC_OPT_V,   // IV to use, specified as a hexadecimal string
  FT_ENC_OPT_MAX
} t_enc_opt_k;

typedef struct s_enc_option_table {
  t_enc_opt_k opt_key;
  char* opt_name;
  char* opt_description;
  t_enc_opt_ft* ft;
} t_enc_opt_t;

typedef struct s_enc_cli_option {
  char* cipher;
  int b64;
  char* in;
  char* key;
  char* out;
  char* pass;
  char* iv;
} t_enc_cli_opt;

/*
**	Cyphers
*/

# define FT_ENC_BASE64   "base64"
# define FT_ENC_DES      "des"
# define FT_ENC_DES_ECB  "des-ecb"
# define FT_ENC_DES_CBC  "des-cbc"

# define FT_PASS_LEN    sizeof(char) * 256
# define FT_KEY_LEN     sizeof(char) * 17
# define FT_SALT_LEN    sizeof(char) * 17
# define FT_IV_LEN      sizeof(char) * 17

typedef int t_enc_cyph_ft(char* key, char* msg, int msg_len, char** cipher, char* iv);

typedef enum e_enc_cipher_key {
  FT_ENC_CIPH_DES,
  FT_ENC_CIPH_DES_CBC,
  FT_ENC_CIPH_DES_ECB,
  FT_ENC_CIPH_MAX
} t_enc_ciph_k;

typedef struct s_enc_cipher {
  t_enc_ciph_k key;
  char* name;
  t_enc_cyph_ft* ft[2];
} t_enc_ciph;

/*
**	Help
*/

int		ft_enc_help(void);

int ft_enc_get_ciph(t_enc_cyph_ft* cipher[2], char* name);

void ft_enc_opt_init(t_enc_opt ctx_opt[FT_ENC_OPT_MAX]);

void ft_enc_opt_dispatch(char* ctx[], int argc, char* argv[]);

char* ft_enc_opt_a(char* ctx, int argc, char* argv[]);
char* ft_enc_opt_d(char* ctx, int argc, char* argv[]);
char* ft_enc_opt_e(char* ctx, int argc, char* argv[]);
char* ft_enc_opt_i(char* ctx, int argc, char* argv[]);
char* ft_enc_opt_k(char* ctx, int argc, char* argv[]);
char* ft_enc_opt_o(char* ctx, int argc, char* argv[]);
char* ft_enc_opt_p(char* ctx, int argc, char* argv[]);
char* ft_enc_opt_s(char* ctx, int argc, char* argv[]);
char* ft_enc_opt_v(char* ctx, int argc, char* argv[]);


#endif
