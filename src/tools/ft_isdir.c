/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:30:50 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/11 10:18:17 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

int ft_isdir(char *arg) {
  struct stat st;

  ft_memset(&st, 0, sizeof(st));
  if (lstat(arg, &st) == 0 && S_ISDIR(st.st_mode)) return (1);
  return (0);
}