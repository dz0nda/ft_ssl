/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_cbc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/17 23:06:16 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

int ft_des_cbc_encrypt(char* key, char* msg, int msg_len, char** cipher,
  char* iv) {
  // t_des ctx;
  t_uint64 nkey = 0;
  t_des_subkeys subkeys = { 0 };

  // ft_memset(&ctx, 0, sizeof(ctx));
  // printf("here\n");

  ft_memcpy(&nkey, key, 8);

  int len = ft_des_pad(msg, msg_len, cipher);

  ft_des_gensubkeys(nkey, subkeys, 0);

  int i = 0;
  while (i < len) {
    int j = -1;
    while (++j < 8) {
      (*cipher)[i + j] ^= iv[j];
    }

    ft_des_exec((t_uchar*)&(*cipher)[i], subkeys, &(*cipher)[i]);
    ft_memcpy(iv, &(*cipher)[i], 8);

    i += 8;
  }

  return (len);
  // printf("%s\n", *cipher);
}

int ft_des_cbc_decrypt(char* key, char* msg, int msg_len, char** cipher,
  char* iv) {
  // t_des ctx;
  t_uint64 nkey = 0;
  t_des_subkeys subkeys = { 0 };

  // ft_memset(&ctx, 0, sizeof(ctx));

  int len = msg_len;

  *cipher = (char*)ft_memalloc(len);

  if (ft_strncmp("Salted__", &msg[0], 8) == 0) {
    len -= 16;
    ft_memcpy(cipher[0], &msg[16], len);
  }
  else {
    ft_memcpy(cipher[0], msg, len);
  }

  // int len = ft_des_pad(msg, msg_len, cipher);
  ft_memcpy(&nkey, key, 8);

  ft_des_gensubkeys(nkey, subkeys, 1);

  char t[8];

  int i = 0;
  while (i < len) {
    ft_memcpy(t, &(*cipher)[i], 8);
    ft_des_exec((t_uchar*)&(*cipher)[i], subkeys, &(*cipher)[i]);

    int j = -1;
    while (++j < 8) {
      (*cipher)[i + j] ^= iv[j];
    }
    ft_memcpy(iv, t, 8);

    i += 8;
  }

  char padByte = (*cipher)[len - 1];
  ft_memset(&(*cipher)[len - padByte], '\0', padByte);

  return (len - padByte);
}
