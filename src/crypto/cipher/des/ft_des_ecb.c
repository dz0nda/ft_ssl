/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_ecb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/12 17:57:16 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

int ft_des_ecb_encrypt(char *key, char *msg, int msg_len, char **cipher) {
  // t_des ctx;
  t_uint64 nkey = 0;
  t_des_subkeys subkeys = {0};

  // ft_memset(&ctx, 0, sizeof(ctx));

  // ft_memcpy(&ctx.nkey, key, 8);
  ft_memcpy(&nkey, key, 8);

  int len = ft_des_pad(msg, msg_len, cipher);

  // ft_des_gensubkeys(key, ctx.ks, 0);
  ft_des_gensubkeys(nkey, subkeys, 0);

  int i = 0;
  while (i < len) {
    ft_des_exec((t_uchar *)&(*cipher)[i], subkeys, &(*cipher)[i]);
    i += 8;
  }

  return (len);
  // printf("%s\n", *cipher);
}

int ft_des_ecb_decrypt(char *key, char *msg, int msg_len, char **cipher) {
  // printf("des decode:\n");
  // t_des ctx;
  t_uint64 nkey = 0;
  t_des_subkeys subkeys = {0};

  int len = msg_len;

  *cipher = (char *)ft_memalloc(len);

  if (ft_strncmp("Salted__", &msg[0], 8) == 0) {
    len -= 16;
    ft_memcpy(cipher[0], &msg[16], len);
  } else {
    ft_memcpy(cipher[0], msg, len);
  }

  // ft_memset(&ctx, 0, sizeof(ctx));

  ft_memcpy(&nkey, key, 8);

  ft_des_gensubkeys(nkey, subkeys, 1);

  int i = 0;
  while (i < len) {
    ft_des_exec((t_uchar *)&(*cipher)[i], subkeys, &(*cipher)[i]);
    i += 8;
  }

  char padByte = (*cipher)[len - 1];
  ft_memset(&(*cipher)[len - padByte], '\0', padByte);

  return (len - padByte);
}