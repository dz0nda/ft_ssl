/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pbkdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/07/21 22:55:53 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

// const unsigned char salt_test[] = "488843243FBFF7D9";
// const char ft_random[] = { 0x16, 0xF7, 0xA4, 0xA5, 0x14, 0x6B, 0xC9, 0xBE };
// const char *pass = "dzonda";
// const char *salt_test = "488843243FBFF7D9";

// char *salt_arg = "488843243FBFF7D9";
// char *pass_arg = "dzonda";
// char *key_arg = "133457799BBCDFF1";//"6162636465666768"; //abcdefgh

void ft_pbkdf_debug(t_des *ctx) {
  printf("salt=");
  for (int i = 0; i < PKCS5_SALT_LEN; i++) printf("%c", ctx->salt[i]);
  printf("\n");

  printf("key=");
  for (int i = 0; i < 16; i++) printf("%c", ctx->key[i]);
  printf("\n");

  printf("iv=");
  for (int i = 0; i < 16; i++) printf("%c", ctx->iv[i]);
  printf("\n");
}

int ft_des_kdf(char *pass, const unsigned char *salt, char *key, char *iv) {
  char md[EVP_MAX_MD_SIZE];
  int pass_len;
  int data_len;
  char *data;
  // char data[64];
  // ft_bzero(data, 64);

  ft_bzero(md, EVP_MAX_MD_SIZE);
  pass_len = ft_strlen(pass);
  data_len = pass_len + 8;
  if ((data = (char *)ft_memalloc(data_len)) == NULL) return (EXIT_FAILURE);
  ft_memcpy(data, pass, pass_len);
  ft_memcpy(&data[pass_len], salt, 8);

  ft_udgst(FT_MD5, (uint8_t *)data, data_len, md);

  ft_memcpy(key, &md[0], 16);
  ft_memcpy(iv, &md[16], 16);

  // ft_strdel(&data);
  // A0DBEFC72002ABEE B9FA76D1822CFEFD
  // a0dbefc7202abeeb9fa76d1822cfefd
  // printf("salt=");
  // for (int i = 0; i < PKCS5_SALT_LEN; i++) printf("%c", salt[i]);
  // printf("\n");

  printf("key=");
  for (int i = 0; i < 16; i++) printf("%c", key[i]);
  printf("\n");

  printf("iv=");
  for (int i = 0; i < 16; i++) printf("%c", iv[i]);
  printf("\n");

  return (EXIT_SUCCESS);
}

void ft_pbkdf(t_des *ctx, char *pass, char *salt, char *md) {
  // ft_memcpy(&ctx->salt, ft_random, sizeof(ctx->salt));

  // if (key_arg == NULL) {
  // 	/* get salt if provided, use random instead */
  // 	// if (salt_arg != NULL) {
  // 	// 	uint64_t n = hex2int(salt_arg);
  // 	// 	ft_memcpy(&ctx->salt, &n, sizeof(n));
  // 	// }

  // 	/* password concatenation */
  // 	// ctx->pass_length =	ft_strlen(pass_arg) + 8;
  // 	ctx->pass_data = (unsigned char *)ft_memalloc(ctx->pass_length);
  // 	if (!ctx->pass_data)
  // 		return;
  // 	ft_memcpy(ctx->pass_data, pass, ft_strlen(pass));
  // 	ft_memcpy(&ctx->pass_data[ft_strlen(pass)], ctx->salt,
  // sizeof(ctx->salt));

  // 	/* hash */
  // 	char md[EVP_MAX_MD_SIZE];
  // 	ft_bzero(md, sizeof(md));

  // 	ft_udgst(FT_MD5, (uint8_t *)ctx->pass_data, ctx->pass_length, md);

  // 	ft_memcpy(ctx->key, &md[0], 16);
  // 	ft_memcpy(ctx->iv, &md[16], 16);
  // } else {
  // 	/* key is set, get the key from hexa */
  // 	ctx->nkey = hex2int(key_arg);
  // 	ft_memcpy(&ctx->key, &ctx->nkey, sizeof(ctx->nkey));
  // }

  ft_pbkdf_debug(ctx);
}
