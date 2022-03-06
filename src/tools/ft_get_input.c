/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:43:12 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/06 22:30:59 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

int ft_get_input_404(char* err) {
  ft_putstr_fd(err, STDERR_FILENO);
  ft_putstr_fd(": No such file or diectory\n", STDERR_FILENO);
  return (FT_EXFAIL);
}

int ft_get_input(char* file, char** input) {
  int fd;
  char* tmp;
  char buf[4096];
  int nbuf;
  int length;

  fd = 0;
  tmp = NULL;
  ft_bzero(buf, 4096);
  nbuf = 0;
  length = 0;
  if (file != NULL && (fd = open(file, O_RDONLY)) == -1) return (0);
  while ((nbuf = read(fd, buf, 4096)) > 0) {
    tmp = ft_strnew(length);
    ft_memcpy(tmp, *input, length);
    ft_strdel(&(*input));
    *input = ft_strnew(length + nbuf);
    ft_memcpy(*input, tmp, length);
    ft_memcpy(*input + length, buf, nbuf);
    length += nbuf;
    ft_strdel(&tmp);
  }
  return (length);
}

int		ft_write_output(char* file, char* output, int breaker)
{
  int		fd;
  int		i;
  int		length;

  fd = 1;
  i = 0;
  length = ft_strlen(output);
  if (file != NULL && (fd = open(file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
    return (0);

  if (breaker > 0) {
    while (i + breaker < length) {
      write(fd, &output[i], breaker);
      write(fd, "\n", 1);
      i += breaker;
    }
  }

  write(fd, &output[i], length - i);
  if (breaker) write(fd, "\n", 1);

  return (length);
}
