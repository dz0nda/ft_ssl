/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/17 12:25:41 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

int ft_ouptput(char* file, char* output, int breaker) {
  int fd;
  int i;
  int length;
  // printf("LAAA\n");

  fd = 1;
  i = 0;
  length = breaker;
  if (file != NULL &&
    (fd = open(file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
    return (0);

  // if (breaker > 0) {
  //     while (i + breaker < length) {
  //       write(fd, &output[i], breaker);
  //       write(fd, "\n", 1);
  //       i += breaker;
  //     }
  // }

  write(fd, &output[i], length);
  // if (breaker) write(fd, "\n", 1);

  return (length);
}

static int ft_ssl_des_init(t_ssl_des_ctx* ctx, const char* cmd) {
  const t_map_istr des_mode[FT_DES_MODE_MAX] = { {FT_DES_ECB, "ecb"},
                                                {FT_DES_CBC, "cbc"} };
  char** cmd_split = NULL;
  int key = -1;

  if ((cmd_split = ft_strsplit(cmd, '-')) == NULL) {
    return (FT_EXFAIL);
  }

  while (++key < FT_DES_MODE_MAX) {
    if (ft_strequ(des_mode[key].value, cmd_split[1])) {
      ctx->mode_key = des_mode[key].key;
      break;
      // ctx->mode_str =
    }
  }

  ft_stradel(&cmd_split);

  return (FT_EXOK);
}

int ft_ssl_des(int argc, char* argv[]) {
  t_arg arg;
  t_ssl_des des;
  t_ssl_des_opt opt;
  t_ssl_des_ctx ctx;

  ft_memset(&arg, 0, sizeof(arg));
  ft_memset(&des, 0, sizeof(des));
  ft_memset(&opt, 0, sizeof(opt));
  ft_memset(&ctx, 0, sizeof(ctx));

  arg.c = argc;
  arg.v = (const char**)argv;

  if (ft_ssl_des_parse(&des, argc - 1, argv + 1) == FT_EXFAIL)
    return (FT_EXFAIL);

  ft_ssl_des_init(&ctx, argv[0]);
  ft_ssl_des_exec_key(&des);

  opt = des.opt;

  // printf("%d\n", ctx.mode_key);

  if (opt.mode == FT_DES_ENC) {
    ft_ssl_des_exec_enc(ctx, opt);
  }
  else {
    ft_ssl_des_exec_dec(ctx, opt);
  }

  return (FT_EXOK);
}
