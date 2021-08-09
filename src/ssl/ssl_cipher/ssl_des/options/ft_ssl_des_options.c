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

/*
 * ft_ssl_des_opt_a
 *
 * Description:
 *   -a: decode/encode the input/output in base64,
 * 			 depending on the encrypt mode
 * Returns:
 *   FT_EXOK
 */
int ft_ssl_des_opt_a(t_ssl_des *ctx, int argc, char *argv[]) {
  ctx->opt.encode = FT_DES_B64_CODE;
  return (FT_EXOK);
}

/*
 * ft_ssl_des_opt_d
 *
 * Description:
 *   -d: decrypt mode
 * Returns:
 *   FT_EXOK
 */
int ft_ssl_des_opt_d(t_ssl_des *ctx, int argc, char *argv[]) {
  if (ctx->opt.mode == FT_DES_ECB_ENC || ctx->opt.mode == FT_DES_ECB_DEC)
    ctx->opt.mode = FT_DES_ECB_DEC;
  else
    ctx->opt.mode = FT_DES_CBC_DEC;

  return (FT_EXOK);
}

/*
 * ft_ssl_des_opt_e
 *
 * Description:
 *   -e: encrypt mode (default)
 * Returns:
 *   FT_EXOK
 */
int ft_ssl_des_opt_e(t_ssl_des *ctx, int argc, char *argv[]) {
  if (ctx->opt.mode == FT_DES_ECB_ENC || ctx->opt.mode == FT_DES_ECB_DEC)
    ctx->opt.mode = FT_DES_ECB_ENC;
  else
    ctx->opt.mode = FT_DES_CBC_ENC;

  return (FT_EXOK);
}

/*
 * ft_ssl_des_opt_i
 *
 * Description:
 *   -i: input file for message
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
int ft_ssl_des_opt_i(t_ssl_des *ctx, int argc, char *argv[]) {
  if ((ctx->opt.input = argv[++ctx->argi]) == NULL) return (FT_EXFAIL);
  return (FT_EXOK);
}

/*
 * ft_ssl_des_opt_k
 *
 * Description:
 *   -k: key in hex is the next arguement.
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
int ft_ssl_des_opt_k(t_ssl_des *ctx, int argc, char *argv[]) {
  if (!ft_ishexstr(argv[++ctx->argi])) return (FT_EXFAIL);
  ft_memcpy(ctx->opt.key, argv[ctx->argi], sizeof(ctx->opt.key));
  return (FT_EXOK);
}

/*
 * ft_ssl_des_opt_o
 *
 * Description:
 *   -o: output file for message
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
int ft_ssl_des_opt_o(t_ssl_des *ctx, int argc, char *argv[]) {
  if ((ctx->opt.output = argv[++ctx->argi]) == NULL) return (FT_EXFAIL);
  return (FT_EXOK);
}

/*
 * ft_ssl_des_opt_p
 *
 * Description:
 *   -p: password in ascii is the next argument
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
int ft_ssl_des_opt_p(t_ssl_des *ctx, int argc, char *argv[]) {
  if ((argv[++ctx->argi]) == NULL) return (FT_EXFAIL);
  ft_memcpy(
      ctx->opt.pass, argv[ctx->argi],
      (ft_strlen(argv[ctx->argi]) > 256) ? 256 : ft_strlen(argv[ctx->argi]));
  return (FT_EXOK);
}

/*
 * ft_ssl_des_opt_s
 *
 * Description:
 *   -s: the salt in hex is the next argument.
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
int ft_ssl_des_opt_s(t_ssl_des *ctx, int argc, char *argv[]) {
  if (!ft_ishexstr(argv[++ctx->argi])) return (FT_EXFAIL);
  ft_memcpy(ctx->opt.salt, argv[ctx->argi], sizeof(ctx->opt.salt));
  return (FT_EXOK);
}

/*
 * ft_ssl_des_opt_v
 *
 * Description:
 *   -v: initialization vector in hex is the next argument
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
int ft_ssl_des_opt_v(t_ssl_des *ctx, int argc, char *argv[]) {
  if (!ft_ishexstr(argv[++ctx->argi])) return (FT_EXFAIL);
  ft_memcpy(ctx->opt.iv, argv[ctx->argi], sizeof(ctx->opt.iv));
  return (FT_EXOK);
}
