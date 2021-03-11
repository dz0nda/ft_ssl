/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:32 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/11 21:04:13 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_CIPHER_H
# define FT_SSL_CIPHER_H

# include "../../crypto/cipher/base64/ft_base64.h"

# define FT_SSL_CIPHER_NOT_FOUND      -42

# define FT_SSL_CIPHER_ENCODE	0
# define FT_SSL_CIPHER_DECODE	1


#define SHOW(T,V) do { T x = V; print_bits(#T, #V, (unsigned char*) &x, sizeof(x)); } while(0)


typedef int				t_ftssl_cipher_ft(int argc, char *argv[]);

typedef enum		e_ftssl_cipher_key
{
	FT_SSL_BASE64,
	FT_SSL_DES,
	FT_SSL_CIPHER_DIST
}					t_ftssl_cipher_key;

typedef struct			s_ftssl_cipher_option
{
	int		mode;
	char 	*input;
	char 	*output;
}						t_ftssl_cipher_opt;

typedef struct		s_ftssl_cipher_dist
{
	char	*dist_name;
	int		dist_key;
	t_ftssl_cipher_ft	*dist_ft;
}					t_ftssl_cipher_dist;

typedef struct		s_ftssl_cipher
{
	int	argi;
	t_ftssl_cipher_dist	dist;
	t_ftssl_cipher_opt	opt;

}					t_ftssl_cipher;

/*
**	Dispatcher struct
*/

typedef enum			e_ftssl_cipher_opt_key
{
	FT_SSL_CIPHER_OPT_D,
	FT_SSL_CIPHER_OPT_E,
	FT_SSL_CIPHER_OPT_I,
	FT_SSL_CIPHER_OPT_O,
	FT_SSL_CIPHER_OPT
}						t_ftssl_cipher_opt_key;

typedef int				t_ftssl_cipher_opt_ft(t_ftssl_cipher *ctx, int argc, char *argv[]);
typedef void				t_ftssl_base64_ft(char *msg);

typedef struct			s_ftssl_cipher_option_dispatch
{
	int					opt_key;
	char				*opt_name;
	t_ftssl_cipher_opt_ft	*opt_dist;
}						t_ftssl_cipher_opt_d;

typedef struct			s_ftssl_base64_dispatch
{
	int					mode;
	t_ftssl_base64_ft	*base64_mode;
}						t_ftssl_base64_d;

int					ft_ssl_cipher(int argc, char *argv[]);
int					ft_ssl_cipher_dist(t_ftssl_cipher *ctx, int argc, char *argv[]);

/*
**	BASE64
*/

int					ft_ssl_cipher_base64(int argc, char *argv[]);
int					ft_ssl_cipher_base64_option(t_ftssl_cipher *ctx, int argc, char *argv[]);
int					ft_ssl_cipher_base64_error(t_ftssl_cipher *ctx, int argc, char *argv[]);

/*
**	DES
*/

int					ft_ssl_cipher_des(int argc, char *argv[]);

#endif
