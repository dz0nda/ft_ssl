/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher_des_options.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/18 14:04:58 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_cipher.h"

/*
 * ft_ssl_cipher_des_opt_a
 *
 * Description:
 *   -a: decode/encode the input/output in base64, 
 * 			 depending on the encrypt mode
 * Returns:
 *   EXIT_SUCCESS
*/
int		ft_ssl_cipher_des_opt_a(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -a\n");
	ctx->opt.mode = FT_SSL_CIPHER_DECODE;
	return (EXIT_SUCCESS);
}

/*
 * ft_ssl_cipher_des_opt_d
 *
 * Description:
 *   -d: decrypt mode
 * Returns:
 *   EXIT_SUCCESS
*/
int		ft_ssl_cipher_des_opt_d(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -d\n");
	ctx->opt.mode = FT_SSL_CIPHER_DECODE;
	return (EXIT_SUCCESS);
}

/*
 * ft_ssl_cipher_des_opt_e
 *
 * Description:
 *   -e: encrypt mode (default)
 * Returns:
 *   EXIT_SUCCESS
*/
int		ft_ssl_cipher_des_opt_e(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -e\n");
	ctx->opt.mode = FT_SSL_CIPHER_ENCODE;
	return (EXIT_SUCCESS);
}

/*
 * ft_ssl_cipher_des_opt_i
 *
 * Description:
 *   -i: input file for message
 * Returns:
 *   EXIT_SUCCESS or EXIT_FAILURE if argument is NULL
*/
int		ft_ssl_cipher_des_opt_i(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -i\n");
	if ((ctx->opt.input = argv[++ctx->argi]) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
 * ft_ssl_cipher_des_opt_k
 *
 * Description:
 *   -k: key in hex is the next arguement.
 * Returns:
 *   EXIT_SUCCESS or EXIT_FAILURE if argument is NULL
*/
int		ft_ssl_cipher_des_opt_k(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -k\n");
	return (EXIT_SUCCESS);
}

/*
 * ft_ssl_cipher_des_opt_o
 *
 * Description:
 *   -o: output file for message
 * Returns:
 *   EXIT_SUCCESS or EXIT_FAILURE if argument is NULL
*/
int		ft_ssl_cipher_des_opt_o(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -o\n");
	if ((ctx->opt.output = argv[++ctx->argi]) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
 * ft_ssl_cipher_des_opt_p
 *
 * Description:
 *   -p: password in ascii is the next argument
 * Returns:
 *   EXIT_SUCCESS or EXIT_FAILURE if argument is NULL
*/
int		ft_ssl_cipher_des_opt_p(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -p\n");
	return (EXIT_SUCCESS);
}

/*
 * ft_ssl_cipher_des_opt_s
 *
 * Description:
 *   -s: the salt in hex is the next argument.
 * Returns:
 *   EXIT_SUCCESS or EXIT_FAILURE if argument is NULL
*/
int		ft_ssl_cipher_des_opt_s(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -s\n");
	return (EXIT_SUCCESS);
}

/*
 * ft_ssl_cipher_des_opt_v
 *
 * Description:
 *   -v: initialization vector in hex is the next argument
 * Returns:
 *   EXIT_SUCCESS or EXIT_FAILURE if argument is NULL
*/
int		ft_ssl_cipher_des_opt_v(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	printf("opt: -v\n");
	return (EXIT_SUCCESS);
}

/*
 * ft_ssl_cipher_des_option
 *
 * Description:
 *   dispatch option
 * Returns:
 *   function pointer or des error
*/
int		ft_ssl_cipher_des_option(t_ftssl_cipher *ctx, int argc, char *argv[])
{
	static t_ftssl_cipher_opt_d	ft_ssl_cipher_opt[FT_SSL_CIPHER_DES_OPT] = {
		{ FT_SSL_CIPHER_DES_OPT_A, "a", ft_ssl_cipher_des_opt_a },
		{ FT_SSL_CIPHER_DES_OPT_D, "d", ft_ssl_cipher_des_opt_d },
		{ FT_SSL_CIPHER_DES_OPT_E, "e", ft_ssl_cipher_des_opt_e },
		{ FT_SSL_CIPHER_DES_OPT_I, "i", ft_ssl_cipher_des_opt_i },
		{ FT_SSL_CIPHER_DES_OPT_K, "k", ft_ssl_cipher_des_opt_k },
		{ FT_SSL_CIPHER_DES_OPT_O, "o", ft_ssl_cipher_des_opt_o },
		{ FT_SSL_CIPHER_DES_OPT_P, "p", ft_ssl_cipher_des_opt_p },
		{ FT_SSL_CIPHER_DES_OPT_S, "s", ft_ssl_cipher_des_opt_s },
		{ FT_SSL_CIPHER_DES_OPT_O, "v", ft_ssl_cipher_des_opt_v },
	};
	int							opt_key;
	char						*opt;

	opt_key = -1;
	opt = argv[ctx->argi] + 1;
	while (++opt_key < FT_SSL_CIPHER_DES_OPT)
		if (ft_strequ(opt, ft_ssl_cipher_opt[opt_key].opt_name))
			return (ft_ssl_cipher_opt[opt_key].opt_dist(ctx, argc, argv));
	return (ft_ssl_cipher_des_error(ctx, argc, argv));
}