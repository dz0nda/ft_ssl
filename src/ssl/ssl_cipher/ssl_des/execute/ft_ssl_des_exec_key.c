/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des_exec_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/12 17:12:51 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_des.h"

int ft_ssl_des_exec_key(t_ssl_des *ctx) {
  t_uint64 toint = 0;

  if (!ft_strlen(ctx->opt.key)) {
    if (!ft_strlen(ctx->opt.pass)) ft_get_pass(ctx->opt.pass, 256);

    if (!ft_strlen(ctx->opt.salt)) ft_get_random(ctx->opt.salt, 8);

    toint = ft_hextoi(ctx->opt.salt);
    ft_memcpy(ctx->opt.salt, &toint, sizeof(toint));

    ft_kdf(ctx->opt.pass, ctx->opt.salt, ctx->opt.key, ctx->opt.iv);
  }

  toint = ft_hextoi(ctx->opt.key);
  ft_memcpy(ctx->opt.key, &toint, sizeof(toint));

  toint = ft_hextoi(ctx->opt.iv);
  ft_memcpy(ctx->opt.iv, &toint, sizeof(toint));

  return (FT_EXOK);
}
