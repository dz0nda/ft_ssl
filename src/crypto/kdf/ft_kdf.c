/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 08:32:42 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

// void ft_pbkdf_debug(t_des *ctx) {
//   printf("salt=");
//   for (int i = 0; i < PKCS5_SALT_LEN; i++) printf("%c", ctx->salt[i]);
//   printf("\n");

//   printf("key=");
//   for (int i = 0; i < 16; i++) printf("%c", ctx->key[i]);
//   printf("\n");

//   printf("iv=");
//   for (int i = 0; i < 16; i++) printf("%c", ctx->iv[i]);
//   printf("\n");
// }

int ft_kdf(char *pass, const t_uchar *salt, char *key, char *iv) {
  char md[EVP_MAX_MD_SIZE];
  int pass_len;
  int data_len;
  char *data;

  ft_bzero(md, EVP_MAX_MD_SIZE);
  pass_len = ft_strlen(pass);
  data_len = pass_len + 8;
  if ((data = (char *)ft_memalloc(data_len)) == NULL) return (EXIT_FAILURE);
  
  ft_memcpy(data, pass, pass_len);
  ft_memcpy(&data[pass_len], salt, 8);

  ft_udgst(FT_MD5, (uint8_t *)data, data_len, md);

  ft_memcpy(key, &md[0], 16);
  ft_memcpy(iv, &md[16], 16);

  return (EXIT_SUCCESS);
}
