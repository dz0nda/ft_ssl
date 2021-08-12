/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_pad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/10 23:36:20 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

int ft_des_pad(char *msg, int msg_len, char **cipher) {
  int padByte = 8 - msg_len % 8;
  int len = msg_len + padByte;

  *cipher = (char *)malloc(len + 1);
  ft_memset((*cipher), '\0', len + 1);
  ft_memcpy((*cipher), msg, msg_len);
  ft_memset(&(*cipher)[msg_len], padByte, padByte);
  return (len);
}
