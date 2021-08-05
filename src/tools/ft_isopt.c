/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isopt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:30:50 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/11 12:46:30 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

int ft_isopt(char *opt) {
  if (*opt && *opt == '-' && ft_strlen(opt) > 1) return (FT_TRUE);
  return (FT_FALSE);
}