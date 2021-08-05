/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_base64_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/16 14:04:18 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_base64.h"

#include <arpa/inet.h>
#include <errno.h>
#include <limits.h>

// int ft_ssl_base64_exec_encode(char *input, char *output) {
//   char *msg = NULL;
//   char *dst = NULL;
//   int msg_len = 0;
//   int dst_len = 0;

//   msg_len = ft_get_input(input, &msg);
// 	if (msg == NULL || msg_len < 1) return (FT_EXFAIL);

//   dst_len = ft_base64_get_encoded_len(msg_len);
//   if ((dst = (unsigned char *)ft_memalloc(dst_len + 1)) == NULL) return (FT_EXFAIL);

//   ft_b64_enc(dst, msg);
//   ft_write_output(output, dst, 64);

//   ft_strdel(&msg);
//   ft_strdel(&dst);
// }

// int ft_ssl_base64_exec_decode(char *input, char *output) {
//   char *msg = NULL;
//   char *dst = NULL;
//   int msg_len = 0;
//   int dst_len = 0;

//   msg_len = ft_get_input(input, &msg);
// 	if (msg == NULL || msg_len < 1) return (FT_EXFAIL);
//   if (msg[msg_len - 1] == '\n') msg[--msg_len] = '\0';

//   dst_len = ft_base64_get_decoded_len(msg, msg_len);
//   if (dst_len == 0) {
//     free(msg);
//     return (FT_EXFAIL);
//   }
//   if ((dst = (unsigned char *)ft_memalloc(dst_len + 1)) == NULL) return (FT_EXFAIL);

//   ft_b64_dec(dst, msg);
//   ft_write_output(output, dst, 0);

//   ft_strdel(&msg);
//   ft_strdel(&dst);

// }

int ft_ssl_base64_exec(t_ssl_base64 *ctx, int argc, char *argv[]) {
  static t_ssl_base64_d b64[FT_SSL_B64_MODE] = {
      {FT_SSL_B64_ENCODE, ft_b64_enc},
      {FT_SSL_B64_DECODE, ft_b64_dec},
  };
  t_ssl_base64_opt *opt = &ctx->opt;
  char *msg = NULL;
  char *dst = NULL;
  int msg_len = 0;
  int dst_len = 0;

  msg_len = ft_get_input(opt->input ? opt->input : argv[ctx->argi], &msg);
	if (msg == NULL || msg_len < 1) return (FT_EXFAIL);

  if (opt->mode == FT_SSL_B64_DECODE)
    if (msg[msg_len - 1] == '\n') msg[--msg_len] = '\0';

  dst_len = (opt->mode == FT_SSL_B64_DECODE) ? ft_base64_get_decoded_len(msg, msg_len) : ft_base64_get_encoded_len(msg_len);
  if (dst_len == 0) {
    free(msg);
    return (FT_EXFAIL);
  }
  if ((dst = (unsigned char *)ft_memalloc(dst_len + 1)) == NULL) return (FT_EXFAIL);

  b64[opt->mode].base64_mode(dst, dst_len, msg, msg_len);
  (opt->mode == FT_SSL_B64_DECODE) ? ft_write_output(opt->output, dst, 0) : ft_write_output(opt->output, dst, 64);

  ft_strdel(&msg);
  ft_strdel(&dst);
  return (FT_EXOK);
  // if (ctx->opt.mode == FT_SSL_B64_DECODE)
  //   return (ft_ssl_base64_exec_decode(input, output));
  // return (ft_ssl_base64_exec_encode(input, output));
}