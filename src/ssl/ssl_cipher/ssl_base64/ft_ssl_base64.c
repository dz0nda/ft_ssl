/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_base64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/29 14:16:46 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_base64.h"

int ft_ssl_base64(int argc, char *argv[]) {
  t_ssl_base64 ctx;

  ft_memset(&ctx, 0, sizeof(ctx));

  if (ft_ssl_base64_parse(&ctx, argc - 1, argv + 1) == FT_EXFAIL)
    return (FT_EXFAIL);

  if (ft_ssl_base64_exec(&ctx, argc - 1, argv + 1) == FT_EXFAIL)
    return (FT_EXFAIL);

  return (EXIT_SUCCESS);
}
