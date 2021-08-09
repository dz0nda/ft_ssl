/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_b64_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 08:50:00 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_b64.h"

static int ft_ssl_b64_opt_err(t_ssl_base64 *ctx, int argc, char *argv[]) {
  ft_putstr_fd("base64: ", STDERR_FILENO);
  ft_putstr_fd(argv[ctx->argi], STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putendl_fd("Unexpected error.", STDERR_FILENO);
  return (EXIT_FAILURE);
}

/*
 * ft_ssl_b64_opt
 *
 * Description:
 *   Dispatch the option
 * Returns:
 *   ft_ssl_b64_opt_err if the opt is unrecognized,
 *   otherwise the opt function
 */
static int ft_ssl_b64_opt(t_ssl_base64 *ctx, int argc, char *argv[]) {
  static t_ssl_b64_opt_d ft_ssl_b64_opt[Ft_ssl_b64_opt] = {
      {Ft_ssl_b64_opt_D, "d", ft_ssl_b64_opt_d},
      {Ft_ssl_b64_opt_E, "e", ft_ssl_b64_opt_e},
      {Ft_ssl_b64_opt_I, "i", ft_ssl_b64_opt_i},
      {Ft_ssl_b64_opt_O, "o", ft_ssl_b64_opt_o},
  };
  int opt_key;
  char *opt;

  opt_key = -1;
  opt = argv[ctx->argi] + 1;
  while (++opt_key < Ft_ssl_b64_opt)
    if (ft_strequ(opt, ft_ssl_b64_opt[opt_key].opt_name))
      return (ft_ssl_b64_opt[opt_key].opt_dist(ctx, argc, argv));
  return (ft_ssl_b64_opt_err(ctx, argc, argv));
}

/*
 * ft_ssl_base64_parse
 *
 * Description:
 *   Parse the command line
 * Returns:
 *   FT_EXFAIL if the opt function fail, otherwise FT_EXOK
 */
int ft_ssl_base64_parse(t_ssl_base64 *ctx, int argc, char *argv[]) {
  while (ctx->argi < argc) {
    if (!ft_isopt(argv[ctx->argi])) break;
    if (ft_ssl_b64_opt(ctx, argc, argv) == FT_EXFAIL) return (FT_EXFAIL);
    ctx->argi++;
  }

  return (FT_EXOK);
}