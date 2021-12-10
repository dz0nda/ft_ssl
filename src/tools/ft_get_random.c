/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_random.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:43:12 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/12 18:10:33 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

int ft_get_random(char *dst, int size) {
  int fd = -1;
  int res = -1;

  fd = open("/dev/urandom", O_RDONLY);
  if (fd < 0) {
    return (-1);
  }

  res = read(fd, dst, size);
  if (res < 0) {
    return (-1);
  }

  return (res);
}

int ft_get_pass(char *dst, int size) {
  char pass[256];

  ft_bzero(pass, 256);

  if (readpassphrase("enter des encryption password: ", dst, size, 0) == NULL)
    return (FT_EXFAIL);
  if (readpassphrase("Verifying - enter des encryption password: ", pass, 256,
                     0) == NULL)
    return (FT_EXFAIL);

  if (ft_memcmp(dst, pass, 256) != 0) {
    ft_putendl_fd("Verify failure", STDERR_FILENO);
    ft_putendl_fd("bad password read", STDERR_FILENO);
    return (FT_EXFAIL);
  }

  return (FT_EXOK);
}
