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

char msg[] = {
    0x40, 0x03, 0x06, 0x0e, 0x8d, 0xb0, 0xd2, 0x6f,
    0xfd, 0xf2, 0xe1, 0x74, 0x49, 0x29, 0x22, 0xf8};  // "abcdefgh";
                                                      // //"0123456789ABCDEF";
// char 	msg[] = { 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68 }; //
// "abcdefgh"; //"0123456789ABCDEF";

int msg_len = 0;

// int		ft_ssl_des_exec_base64(t_ssl_des *ctx, int argc, char *argv[]) {

// }

static int ft_ouptput(char *file, char *output, int breaker) {
  int fd;
  int i;
  int length;

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

int ft_ssl_des_exec(t_ssl_des *ctx, int argc, char *argv[]) {
  static t_des_ecb_d ft_des_ecb[2] = {
      {FT_DES_ECB_ENC, ft_des_ecb_encrypt},
      {FT_DES_ECB_DEC, ft_des_ecb_decrypt},
  };
  static t_des_cbc_d ft_des_cbc[2] = {
      {FT_DES_CBC_ENC, ft_des_cbc_encrypt},
      {FT_DES_ECB_DEC, ft_des_cbc_decrypt},
  };
  char *cipher = NULL;
  char *input = NULL;
  int input_len = 0;

  if (ctx->opt.input == NULL) ctx->opt.input = argv[ctx->argi];
  input_len = ft_get_input(ctx->opt.input, &input);
  // printf("%s\n", input);

  // printf("input len %d\n", input_len);

  if ((ctx->opt.mode == FT_DES_ECB_DEC || ctx->opt.mode == FT_DES_CBC_DEC) &&
      ctx->opt.encode == FT_DES_B64_CODE) {
    input[--input_len] = '\0';

    int dst_len = ft_b64_get_decoded_len(input, input_len);

    char *dst = (char *)ft_memalloc(dst_len + 1);

    ft_b64_dec(dst, dst_len, input, input_len);

    free(input);

    input = dst;
    input_len = dst_len;
  }
  // printf("%s %d\n", input, input_len);

  ft_ssl_des_exec_pre_process(ctx);

  // printf("key: %s\n", ctx->opt.key);
  // printf("iv: %s\n", ctx->opt.iv);

  // int len = ft_des_ebc(ctx->opt.key, input, input_len, &cipher, ctx->opt.iv);
  int len = 0;

  if (ctx->opt.mode == FT_DES_ECB_ENC || ctx->opt.mode == FT_DES_ECB_DEC)
    len = ft_des_ecb[ctx->opt.mode].des_mode(ctx->opt.key, input, input_len,
                                             &cipher);
  else
    len = ft_des_cbc[ctx->opt.mode].des_mode(ctx->opt.key, input, input_len,
                                             &cipher, ctx->opt.iv);

  // hexdump(cipher, len);

  if ((ctx->opt.mode == FT_DES_ECB_ENC || ctx->opt.mode == FT_DES_CBC_ENC) &&
      ft_strlen(ctx->opt.salt)) {
    // char *tmp = ft_strdup(cipher); // here !
    char *tmp = ft_memalloc(len);
    ft_memcpy(tmp, cipher, len);
    free(cipher);
    cipher = ft_memalloc(len + 16 + 1);
    ft_memset(cipher, '\0', len + 16 + 1);
    ft_memcpy(&cipher[0], "Salted__", 8);
    ft_memcpy(&cipher[8], ctx->opt.salt, 8);
    ft_memcpy(&cipher[16], tmp, len);
    free(tmp);
    len += 16;
  }

  // hexdump(cipher, len);
  if ((ctx->opt.mode == FT_DES_ECB_ENC || ctx->opt.mode == FT_DES_CBC_ENC) &&
      ctx->opt.encode == FT_DES_B64_CODE) {
    int dst_len = ft_b64_get_encoded_len(len);
    char *dst = (char *)ft_memalloc(dst_len + 1);

    ft_b64_enc(dst, dst_len, cipher, len);

    ft_write_output(ctx->opt.output, dst, 64);
  } else {
    ft_ouptput(ctx->opt.output, cipher, len);
  }

  return (EXIT_SUCCESS);
}