/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/14 21:56:06 by dzonda           ###   ########lyon.fr   */
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
int ft_enc_opt_a(t_enc_opt* opt, t_arg* arg) {
  // ctx->opt.encode = FT_DES_B64_CODE;
  opt->enc = FT_ENC_B64;

  arg->c -= 1;
  arg->v += 1;

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
int ft_enc_opt_d(t_enc_opt* opt, t_arg* arg) {
  // if (ctx->opt.mode == FT_DES_ECB_ENC || ctx->opt.mode == FT_DES_ECB_DEC)
  //   ctx->opt.mode = FT_DES_ECB_DEC;
  // else
  //   ctx->opt.mode = FT_DES_CBC_DEC;
  // ctx->opt.mode = FT_DES_DEC;
  opt->enc = FT_ENC_D;

  arg->c -= 1;
  arg->v += 1;

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
int ft_enc_opt_e(t_enc_opt* opt, t_arg* arg) {
  // if (ctx->opt.mode == FT_DES_ECB_ENC || ctx->opt.mode == FT_DES_ECB_DEC)
  //   ctx->opt.mode = FT_DES_ECB_ENC;
  // else
  //   ctx->opt.mode = FT_DES_CBC_ENC;
  // ctx->opt.mode = FT_DES_ENC;
  opt->enc = FT_ENC_E;

  arg->c -= 1;
  arg->v += 1;

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
int ft_enc_opt_i(t_enc_opt* opt, t_arg* arg) {
  // if ((ctx = *argv) == NULL) {
  //   return (NULL);
  // }
  opt->in = (char*)*(arg->v + 1);

  arg->c -= 2;
  arg->v += 2;

  return (FT_EXOK);
}

/*
 * ft_enc_opt_k
 *
 * Description:
 *   -k: key in hex is the next arguement.
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
int ft_enc_opt_k(t_enc_opt* opt, t_arg* arg) {
  // Check later
  // if (!ft_ishexstr(*argv) {
  //   return (FT_EXFAIL);
  // }
  // int len = ft_strlen(*argv);

  // if (!len) {
  //   return (FT_EXFAIL); // Missiing arg
  // }

  // ft_bzero(ctx, FT_KEY_LEN);
  // ft_memcpy(ctx, *argv, len > FT_KEY_LEN ? FT_KEY_LEN : len);
  opt->key = (char*)*(arg->v + 1);

  arg->c -= 2;
  arg->v += 2;

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
int ft_enc_opt_o(t_enc_opt* opt, t_arg* arg) {
  // if ((ctx = *argv) == NULL) {
  //   return (FT_EXFAIL);
  // }
  opt->out = (char*)*(arg->v + 1);

  arg->c -= 2;
  arg->v += 2;

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
int ft_enc_opt_p(t_enc_opt* opt, t_arg* arg) {
  // int len = ft_strlen(*argv);

  // if (*argv == NULL) {
  //   return (NULL); // Missiing arg
  // }

  // ft_bzero(ctx->pass, FT_KEY_LEN);
  // ctx = *argv;
  // argv++;
  // ft_strncpy(ctx, *argv, FT_KEY_LEN);

  // if ((argv[++ctx->argi]) == NULL) return (FT_EXFAIL);
  // ft_memcpy(
  //   ctx->opt.pass, argv[ctx->argi],
  //   (ft_strlen(argv[ctx->argi]) > 256) ? 256 : ft_strlen(argv[ctx->argi]));
  opt->pass = (char*)*(arg->v + 1);

  arg->c -= 2;
  arg->v += 2;

  return (FT_EXOK);
}

/*
 * ft_enc_opt_s
 *
 * Description:
 *   -s: the salt in hex is the next argument.
 * Returns:
 *   FT_EXOK or FT_EXFAIL if argument is NULL
 */
int ft_enc_opt_s(t_enc_opt* opt, t_arg* arg) {
  // if (!ft_ishexstr(argv[++ctx->argi])) return (FT_EXFAIL);
  // ft_memcpy(ctx->opt.salt, argv[ctx->argi], sizeof(ctx->opt.salt));
  // if (*argv == NULL) {
  //   return (FT_EXFAIL); // Missiing arg
  // }

  // ft_strncpy(ctx, *argv, FT_SALT_LEN);

  opt->salt = (char*)*(arg->v + 1);

  arg->c -= 2;
  arg->v += 2;

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
int ft_enc_opt_v(t_enc_opt* opt, t_arg* arg) {
  // if (!ft_ishexstr(argv[++ctx->argi])) return (FT_EXFAIL);
  // ft_memcpy(ctx->opt.iv, argv[ctx->argi], sizeof(ctx->opt.iv));
  // if (*argv == NULL) {
  //   return (FT_EXFAIL); // Missiing arg
  // }

  // ft_strncpy(ctx, *argv, FT_IV_LEN);

  opt->iv = (char*)*(arg->v + 1);

  arg->c -= 2;
  arg->v += 2;

  return (FT_EXOK);
}
