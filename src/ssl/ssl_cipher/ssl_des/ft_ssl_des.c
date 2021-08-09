/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/17 12:25:41 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

int ft_ssl_des_ecb(int argc, char *argv[]) {
  t_ssl_des ctx;

  ft_memset(&ctx, 0, sizeof(ctx));
  ctx.opt.mode = FT_DES_ECB_ENC;

  if (ft_ssl_des_parse(&ctx, argc - 1, argv + 1) == FT_EXFAIL)
    return (FT_EXFAIL);

  if (ft_ssl_des_exec(&ctx, argc - 1, argv + 1) == FT_EXFAIL)
    return (FT_EXFAIL);

  return (EXIT_SUCCESS);
}

int ft_ssl_des_cbc(int argc, char *argv[]) {
  t_ssl_des ctx;

  ft_memset(&ctx, 0, sizeof(ctx));
  ctx.opt.mode = FT_DES_CBC_ENC;

  if (ft_ssl_des_parse(&ctx, argc - 1, argv + 1) == FT_EXFAIL)
    return (FT_EXFAIL);

  if (ft_ssl_des_exec(&ctx, argc - 1, argv + 1) == FT_EXFAIL)
    return (FT_EXFAIL);

  return (EXIT_SUCCESS);
}
