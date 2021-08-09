/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_b64_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 08:50:14 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <errno.h>
#include <limits.h>

#include "../ft_ssl_b64.h"

int ft_ssl_base64_exec_init(t_ssl_b64_ctx *ctx, t_ssl_b64_opt *opt) {
  if (opt->input)
    ctx->src_len = ft_get_input(opt->input, &ctx->src);
  else
    ctx->src_len = ft_get_input(NULL, &ctx->src);

  if (ctx->src == NULL || ctx->src_len < 1) return (FT_FALSE);

  if (opt->mode == FT_SSL_B64_DECODE && ctx->src[ctx->src_len - 1] == '\n')
    ctx->src[--(ctx->src_len)] = '\0';

  if (opt->mode == FT_SSL_B64_DECODE)
    ctx->dst_len = ft_b64_get_decoded_len(ctx->src, ctx->src_len);
  else
    ctx->dst_len = ft_b64_get_encoded_len(ctx->src_len);

  if (ctx->dst_len == 0) {
    ft_strdel(&ctx->src);
    return (FT_FALSE);
  }

  if ((ctx->dst = (char *)ft_memalloc(ctx->dst_len + 1)) == NULL)
    return (FT_EXFAIL);
}

int ft_ssl_base64_exec(t_ssl_base64 *ssl_b64, int argc, char *argv[]) {
  static t_ssl_base64_d b64[FT_SSL_B64_MODE] = {
      {FT_SSL_B64_ENCODE, ft_b64_enc},
      {FT_SSL_B64_DECODE, ft_b64_dec},
  };
  t_ssl_b64_opt *opt = &ssl_b64->opt;
  t_ssl_b64_ctx ctx;
  char *msg = NULL;
  char *dst = NULL;
  int msg_len = 0;
  int dst_len = 0;

  if (ft_ssl_base64_exec_init(&ctx, opt) == FT_FALSE) return (FT_EXFAIL);
  // msg_len = ft_get_input(opt->input ? opt->input : argv[ctx->argi], &msg);
  // if (msg == NULL || msg_len < 1) return (FT_EXFAIL);

  // if (opt->mode == FT_SSL_B64_DECODE)
  //   if (msg[msg_len - 1] == '\n') msg[--msg_len] = '\0';

  // dst_len = (opt->mode == FT_SSL_B64_DECODE)
  //               ? ft_b64_get_decoded_len(msg, msg_len)
  //               : ft_b64_get_encoded_len(msg_len);
  // if (dst_len == 0) {
  //   free(msg);
  //   return (FT_EXFAIL);
  // }
  // if ((dst = (unsigned char *)ft_memalloc(dst_len + 1)) == NULL)
  //   return (FT_EXFAIL);

  b64[opt->mode].base64_mode(ctx.dst, ctx.dst_len, ctx.src, ctx.src_len);
  (opt->mode == FT_SSL_B64_DECODE) ? ft_write_output(opt->output, ctx.dst, 0)
                                   : ft_write_output(opt->output, ctx.dst, 64);

  ft_strdel(&ctx.src);
  ft_strdel(&ctx.dst);
  return (FT_EXOK);
  // if (ctx->opt.mode == FT_SSL_B64_DECODE)
  //   return (ft_ssl_base64_exec_decode(input, output));
  // return (ft_ssl_base64_exec_encode(input, output));
}