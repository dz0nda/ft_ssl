/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:14:00 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/03 22:35:26 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_DGST_H
# define FT_SSL_DGST_H

# include "../../crypto/dgst/udgst/ft_udgst.h"

# define FTSSL_DGST_MAX_BUFFER      8192
# define FT_SSL_DGST_NOT_FOUND      -42

/*
** ENUM KEYS
*/

typedef enum			e_ftssl_digest_key
{
	FTSSL_DGST_OUTP_DEFAULT,
	FTSSL_DGST_OUTP_QUIET,
	FTSSL_DGST_OUTP_STRING,
	FTSSL_DGST_OUTP_FILE,
	FTSSL_DGST_OUTP
}						t_ftssl_dgst_k;

typedef enum			e_ftssl_digest_err_key
{
	FTSSL_DGST_ERR_NO,
	FTSSL_DGST_ERR_OPT,
	FTSSL_DGST_ERR_OPT_ARG,
	FTSSL_DGST_ERR_FILE,
	FTSSL_DGST_ERR_DIR,
	FTSSL_DGST_ERR
}						t_ftssl_dgst_err_key;

typedef enum			e_ftssl_digest_opt_key
{
	FT_SSL_DGST_OPT_P,
	FT_SSL_DGST_OPT_Q,
	FT_SSL_DGST_OPT_R,
	FT_SSL_DGST_OPT_S,
	FT_SSL_DGST_OPT
}						t_ftssl_dgst_opt_key;

/*
** FT_SSL_DGST STRUCT
*/

typedef struct			s_ftssl_dgst_option
{
	int		output;
	int		output_print;
	int		reverse;
}						t_ftssl_dgst_opt;

typedef struct			s_ftssl_dgst_distribution
{
	int					key;
	char				*name_lower;
	char				*name_upper;
}						t_ftssl_dgst_dist;

typedef struct			s_ftssl_dgst
{
	int					argi;
	char				*cmd_arg;
	char				*arg;
	int					length;
	t_ftssl_dgst_dist	distrib;
	t_ftssl_dgst_opt	opt;
	char				md[FTSSL_DGST_MAX_BUFFER];
	int					err;
}						t_ftssl_dgst;

/*
** dispatcher struct
*/

typedef int				t_ftssl_dgst_ft(t_ftssl_dgst *ctx);
typedef int				t_ftssl_dgst_opt_ft(t_ftssl_dgst *ctx, int argc,
											char *argv[]);
typedef int				t_ftssl_dgst_err_ft(int err_key, char *msg, char *msg2);
typedef int				t_ftssl_dgst_out_ft(t_ftssl_dgst *ctx, char *arg,
	char *md);

typedef struct			s_ftssl_dgst_option_dispatch
{
	int					opt_key;
	char				*opt_name;
	t_ftssl_dgst_opt_ft	*opt_dist;
}						t_ftssl_dgst_opt_d;

typedef struct			s_ftssl_dgst_error_dispatch
{
	int					err_key;
	t_ftssl_dgst_err_ft	*err_dist;
}						t_ftssl_dgst_err_d;

typedef struct			s_ftssl_dgst_output_dispatch
{
	int					outp_key;
	t_ftssl_dgst_out_ft	*outp_dist;
}						t_ftssl_dgst_out_d;

/*
** ft_ssl_dgst functions
*/

int						ft_ssl_dgst(int argc, char *argv[]);
int						ft_ssl_dgst_exec(t_ftssl_dgst *ctx);

int						ft_ssl_dgst_dist(t_ftssl_dgst *ctx, int argc,
	char *argv[]);
int						ft_ssl_dgst_option(t_ftssl_dgst *ctx, int argc,
	char *argv[]);
int						ft_ssl_dgst_error(int err_key,
	t_ftssl_dgst *ctx, char *arg);
int						ft_ssl_dgst_output(int out_key, t_ftssl_dgst *ctx,
	char *arg);

#endif
