/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/14 22:17:45 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enc.h"

int ft_enc_get_key(t_ciph* enc_ciph, t_enc_opt* opt) {
    t_uint64 toint = 0;
    char pass[256];

    ft_bzero(pass, 256);

    // if (!ft_strlen(ctx[FT_ENC_OPT_K])) {
    //     if (!ft_strlen(ctx[FT_ENC_OPT_P])) {
    //         ft_get_pass(pass, 256);
    //     }

    //     if (!ft_strlen(ctx[FT_ENC_OPT_S])) {
    //         ft_get_random(salt, 8);
    //     }

    //     toint = ft_hextoi(salt);
    //     ft_memcpy(salt, &toint, sizeof(toint));

    //     ft_kdf(pass, (t_uchar*)salt, key, iv);
    // }
    // else {

    ft_memcpy(enc_ciph->key, opt->key, FT_KEY_LEN);
    // printf("%s:%s\n", )
    // }


    toint = ft_hextoi(enc_ciph->key);
    printf("%llu\n", toint);

    ft_memcpy(enc_ciph->key, &toint, sizeof(toint));
    printf("%x\n", enc_ciph->key);

    // toint = ft_hextoi(ctx->opt.iv);
    // ft_memcpy(ctx->opt.iv, &toint, sizeof(toint));

    return (FT_EXOK);
}
