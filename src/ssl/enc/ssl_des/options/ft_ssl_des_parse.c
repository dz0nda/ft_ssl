/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des_options.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/18 14:04:58 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_des.h"

static int ft_ssl_des_option_err(t_ssl_des *ctx, int argc, char *argv[]) {
  ft_putstr_fd("des: ", STDERR_FILENO);
  ft_putstr_fd(argv[ctx->argi], STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putendl_fd("Unexpected error.", STDERR_FILENO);
  return (EXIT_FAILURE);
}

/*
 * ft_ssl_des_dispatch_opt
 *
 * Description:
 *   dispatch option
 * Returns:
 *   function pointer or des error
 */
int ft_ssl_des_dispatch_opt(t_ssl_des *ctx, int argc, char *argv[]) {
  static t_ssl_des_opt_d ft_ssl_cipher_opt[FT_SSL_DES_OPT] = {
      {FT_SSL_DES_OPT_A, "a", ft_ssl_des_opt_a},
      {FT_SSL_DES_OPT_D, "d", ft_ssl_des_opt_d},
      {FT_SSL_DES_OPT_E, "e", ft_ssl_des_opt_e},
      {FT_SSL_DES_OPT_I, "i", ft_ssl_des_opt_i},
      {FT_SSL_DES_OPT_K, "k", ft_ssl_des_opt_k},
      {FT_SSL_DES_OPT_O, "o", ft_ssl_des_opt_o},
      {FT_SSL_DES_OPT_P, "p", ft_ssl_des_opt_p},
      {FT_SSL_DES_OPT_S, "s", ft_ssl_des_opt_s},
      {FT_SSL_DES_OPT_O, "v", ft_ssl_des_opt_v},
  };
  int opt_key;
  char *opt;

  opt_key = -1;
  opt = argv[ctx->argi] + 1;
  while (++opt_key < FT_SSL_DES_OPT)
    if (ft_strequ(opt, ft_ssl_cipher_opt[opt_key].opt_name))
      return (ft_ssl_cipher_opt[opt_key].opt_dist(ctx, argc, argv));
  return (ft_ssl_des_option_err(ctx, argc, argv));
}

/*
 * ft_ssl_des_parse
 *
 * Description:
 *   Parse the command line
 * Returns:
 *   FT_EXFAIL if the opt function fail, otherwise FT_EXOK
 */
int ft_ssl_des_parse(t_ssl_des *ctx, int argc, char *argv[]) {
  while (ctx->argi < argc) {
    if (!ft_isopt(argv[ctx->argi])) break;
    if (ft_ssl_des_dispatch_opt(ctx, argc, argv) == FT_EXFAIL)
      return (FT_EXFAIL);
    ctx->argi++;
  }

  return (FT_EXOK);
}