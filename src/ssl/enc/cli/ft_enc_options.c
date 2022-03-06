/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/06 09:50:35 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enc_cli.h"

/*
 * ft_enc_opt_a
 *
 * Description:
 *   -a: Perform base64 encoding/decoding (alias -base64)
 * Returns:
 *   FT_EXOK
 */
char* ft_enc_opt_a(char* ctx, int argc, char* argv[]) {
  // ctx->opt.encode = FT_DES_B64_CODE;
  return (FT_EXOK);
}

/*
 * ft_enc_opt_d
 *
 * Description:
 *   -d: Decrypt the input data
 * Returns:
 *   FT_EXOK
 */
char* ft_enc_opt_d(char* ctx, int argc, char* argv[]) {
  // if (ctx->opt.mode == FT_DES_ECB_ENC || ctx->opt.mode == FT_DES_ECB_DEC)
  //   ctx->opt.mode = FT_DES_ECB_DEC;
  // else
  //   ctx->opt.mode = FT_DES_CBC_DEC;
  // ctx->opt.mode = FT_DES_DEC;
  return (FT_EXOK);
}

/*
 * ft_enc_opt_e
 *
 * Description:
 *   -e: encrypt mode (default)
 * Returns:
 *   FT_EXOK
 */
char* ft_enc_opt_e(char* ctx, int argc, char* argv[]) {
  // if (ctx->opt.mode == FT_DES_ECB_ENC || ctx->opt.mode == FT_DES_ECB_DEC)
  //   ctx->opt.mode = FT_DES_ECB_ENC;
  // else
  //   ctx->opt.mode = FT_DES_CBC_ENC;
  // ctx->opt.mode = FT_DES_ENC;
  return (FT_EXOK);
}

/*
 * ft_enc_opt_i
 *
 * Description:
 *   -i: input file for message
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
char* ft_enc_opt_i(char* ctx, int argc, char* argv[]) {
  // if ((ctx = *argv) == NULL) {
  //   return (NULL);
  // }
  return (*argv);
}

/*
 * ft_enc_opt_k
 *
 * Description:
 *   -k: key in hex is the next arguement.
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
char* ft_enc_opt_k(char* ctx, int argc, char* argv[]) {
  // Check later
  // if (!ft_ishexstr(*argv) {
  //   return (FT_EXFAIL);
  // }
  int len = ft_strlen(*argv);

  if (!len) {
    return (FT_EXFAIL); // Missiing arg
  }

  ft_bzero(ctx, FT_KEY_LEN);
  ft_memcpy(ctx, *argv, len > FT_KEY_LEN ? FT_KEY_LEN : len);

  return (FT_EXOK);
}

/*
 * ft_enc_opt_o
 *
 * Description:
 *   -o: output file for message
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
char* ft_enc_opt_o(char* ctx, int argc, char* argv[]) {
  if ((ctx = *argv) == NULL) {
    return (FT_EXFAIL);
  }
  return (FT_EXOK);
}

/*
 * ft_enc_opt_p
 *
 * Description:
 *   -p: password in ascii is the next argument
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
char* ft_enc_opt_p(char* ctx, int argc, char* argv[]) {
  // int len = ft_strlen(*argv);

  if (*argv == NULL) {
    return (NULL); // Missiing arg
  }

  // ft_bzero(ctx->pass, FT_KEY_LEN);
  ctx = *argv;
  // argv++;
  // ft_strncpy(ctx, *argv, FT_KEY_LEN);

  // if ((argv[++ctx->argi]) == NULL) return (FT_EXFAIL);
  // ft_memcpy(
  //   ctx->opt.pass, argv[ctx->argi],
  //   (ft_strlen(argv[ctx->argi]) > 256) ? 256 : ft_strlen(argv[ctx->argi]));
  return (*argv);
}

/*
 * ft_enc_opt_s
 *
 * Description:
 *   -s: the salt in hex is the next argument.
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
char* ft_enc_opt_s(char* ctx, int argc, char* argv[]) {
  // if (!ft_ishexstr(argv[++ctx->argi])) return (FT_EXFAIL);
  // ft_memcpy(ctx->opt.salt, argv[ctx->argi], sizeof(ctx->opt.salt));
  if (*argv == NULL) {
    return (FT_EXFAIL); // Missiing arg
  }

  ft_strncpy(ctx, *argv, FT_SALT_LEN);

  return (FT_EXOK);
}

/*
 * ft_enc_opt_v
 *
 * Description:
 *   -v: initialization vector in hex is the next argument
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
char* ft_enc_opt_v(char* ctx, int argc, char* argv[]) {
  // if (!ft_ishexstr(argv[++ctx->argi])) return (FT_EXFAIL);
  // ft_memcpy(ctx->opt.iv, argv[ctx->argi], sizeof(ctx->opt.iv));
  if (*argv == NULL) {
    return (FT_EXFAIL); // Missiing arg
  }

  ft_strncpy(ctx, *argv, FT_IV_LEN);

  return (FT_EXOK);
}