/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:41:54 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/16 12:48:28 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"


int main() {
  int v = 6548;

  SHOW(int, v);
  ft_printb("v", (unsigned char *)&v, sizeof(v));
  ft_printb_le("v", (unsigned char *)&v, sizeof(v));

  v = v << 4;
  SHOW(int, v);
  ft_printb("v", (unsigned char *)&v, sizeof(v));
  ft_printb_le("v", (unsigned char *)&v, sizeof(v));

  return (FT_EXOK);
}