/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_b64_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/14 15:03:36 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_b64.h"

/*
 * ft_ssl_b64_opt_d
 *
 * Description:
 *   -d: Decrypt the input data
 * Returns:
 *   FT_EXOK
 */
int ft_ssl_b64_opt_d(t_ssl_base64 *ctx, int argc, char *argv[]) {
  ctx->opt.mode = FT_SSL_B64_DECODE;
  return (FT_EXOK);
}

/*
 * ft_ssl_b64_opt_e
 *
 * Description:
 *   -e: Encrypt the input data (default)
 * Returns:
 *   FT_EXOK
 */
int ft_ssl_b64_opt_e(t_ssl_base64 *ctx, int argc, char *argv[]) {
  ctx->opt.mode = FT_SSL_B64_ENCODE;
  return (EXIT_SUCCESS);
}

/*
 * ft_ssl_b64_opt_i
 *
 * Description:
 *   -i file: Input file to read from (default stdin)
 * Returns:
 *   FT_EXFAIL if file is null, otherwise FT_EXOK
 */
int ft_ssl_b64_opt_i(t_ssl_base64 *ctx, int argc, char *argv[]) {
  if ((ctx->opt.input = argv[++ctx->argi]) == NULL) return (FT_EXFAIL);
  return (FT_EXOK);
}

/*
 * ft_ssl_b64_opt_o
 *
 * Description:
 *   -o file: Output file to write to (default stdout)
 * Returns:
 *   FT_EXFAIL if file is null, otherwise FT_EXOK
 */
int ft_ssl_b64_opt_o(t_ssl_base64 *ctx, int argc, char *argv[]) {
  if ((ctx->opt.output = argv[++ctx->argi]) == NULL) return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
