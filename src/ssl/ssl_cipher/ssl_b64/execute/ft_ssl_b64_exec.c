/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_b64_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/12 19:06:41 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_b64.h"

int ft_ssl_base64_exec_init(t_ssl_b64_ctx *ctx, t_ssl_b64_opt *opt) {
  if (opt->input) 
    ctx->src_len = ft_get_input(opt->input, &ctx->src);
  else
    ctx->src_len = ft_get_input(NULL, &ctx->src);

  if (ctx->src == NULL || ctx->src_len < 1) return (FT_EXFAIL);

  if (opt->mode == FT_SSL_B64_DECODE && ctx->src[ctx->src_len - 1] == '\n')
    ctx->src[--(ctx->src_len)] = '\0';

  if (opt->mode == FT_SSL_B64_DECODE)
    ctx->dst_len = ft_b64_get_decoded_len((t_uchar *)ctx->src, ctx->src_len);
  else
    ctx->dst_len = ft_b64_get_encoded_len(ctx->src_len);

  // if (ctx->dst_len == 0) {
  //   ft_strdel(&ctx->src);
  //   return (FT_EXFAIL);
  // }

  if ((ctx->dst = (char *)ft_memalloc(ctx->dst_len + 1)) == NULL)
    return (FT_EXFAIL);

  return (FT_EXOK);
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

  ft_memset(&ctx, 0, sizeof(ctx));

  // printf("%s\n", ctx.dst);
  if (ft_ssl_base64_exec_init(&ctx, opt) == FT_EXFAIL) return (FT_EXFAIL);

  printf(".%d.\n", ctx.dst_len);


  b64[opt->mode].base64_mode(ctx.dst, ctx.dst_len, ctx.src, ctx.src_len);
  (opt->mode == FT_SSL_B64_DECODE) ? ft_write_output(opt->output, ctx.dst, 0)
                                   : ft_write_output(opt->output, ctx.dst, 64);

  printf(".%s.\n", ctx.dst);

  ft_strdel(&ctx.src);
  ft_strdel(&ctx.dst);
  return (FT_EXOK);
}