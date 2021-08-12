/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des_exec_enc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/10 14:10:57 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_des.h"

int ft_ssl_des_exec_salt(char **cipher, int cipher_len, char *salt) {
  char *tmp = NULL;

  if ((tmp = ft_memalloc(cipher_len)) == NULL) {
    return (FT_FALSE);
  }
  ft_memcpy(tmp, cipher[0], cipher_len);
  ft_strdel(cipher);
  if ((*cipher = ft_memalloc(cipher_len + 16 + 1)) == NULL) {
    return (FT_FALSE);
  }
  // ft_memset(cipher[0], '\0', cipher_len + 16 + 1);
  ft_memcpy(&(*cipher)[0], "Salted__", 8);
  ft_memcpy(&(*cipher)[8], salt, 8);
  ft_memcpy(&(*cipher)[16], tmp, cipher_len);
  free(tmp);
  return (cipher_len + 16);
}

int ft_ssl_des_exec_enc(t_ssl_des_ctx ctx, t_ssl_des_opt opt) {
  char *cipher = NULL;
  char *input = NULL;
  int input_len = 0;
  int len = 0;

  // if (opt.input == NULL) opt.input = argv[ctx->argi];
  input_len = ft_get_input(opt.input, &input);

  if (ctx.mode_key == FT_DES_ECB) {
    len = ft_des_ecb_encrypt(opt.key, input, input_len, &cipher);
    // printf("LAA\n");
  } else if (ctx.mode_key == FT_DES_CBC)
    len = ft_des_cbc_encrypt(opt.key, input, input_len, &cipher, opt.iv);

  if (ft_strlen(opt.salt)) {
    len = ft_ssl_des_exec_salt(&cipher, len, opt.salt);
  }

  if (opt.encode == FT_DES_B64_CODE) {
    // printf("here?");
    int dst_len = ft_b64_get_encoded_len(len);
    char *dst = (char *)ft_memalloc(dst_len + 1);

    ft_b64_enc(dst, dst_len, cipher, len);

    ft_write_output(opt.output, dst, 64);
  } else {
    ft_ouptput(opt.output, cipher, len);
  }

  return (FT_EXOK);
}
