/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_random.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:43:12 by dzonda            #+#    #+#             */
/*   Updated: 2021/07/11 14:43:40 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

int ft_get_random(char *dst) {
  int fd;
  char myRandomData[8];
  ssize_t result;

  fd = open("/dev/urandom", O_RDONLY);
  if (fd < 0) {
      // ft_putendl_fd("Something went wrong when generating random number", STDERR_FILENO);
    return (-1);
  }

  result = read(fd, myRandomData, sizeof myRandomData);
  if (result < 0) {
    // ft_putendl_fd("Something went wrong when generating random number", STDERR_FILENO);
    return (-1);
  }
  ft_memcpy(dst, myRandomData, 8);

  return (result);
}
