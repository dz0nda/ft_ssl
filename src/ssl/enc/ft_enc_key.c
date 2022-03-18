/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/18 15:21:44 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enc.h"

int ft_enc_get_key(t_ciph* enc_ciph, t_enc_opt* opt) {
    t_uint64 toint = 0;
    char pass[256];
    char salt[17];

    ft_bzero(pass, 256);
    ft_bzero(salt, 17);

    if (opt->key == NULL) {
        if (opt->pass == NULL) {
            ft_get_pass(pass, 256);
        }
        else {
            ft_memcpy(pass, opt->pass, ft_strlen(opt->pass));
        }

        if (opt->salt == NULL) {
            // printf("here\n", salt);
            ft_get_random(enc_ciph->salt, 8);
        }
        else {
            if (!ft_ishexstr(opt->salt)) {
                return (ft_enc_err_invalid_hex("salt"));
            }
            ft_memcpy(enc_ciph->salt, opt->salt, ft_strlen(opt->salt));
        }

        // printf("%s.\n", salt);

        toint = ft_hextoi(enc_ciph->salt);
        ft_memcpy(enc_ciph->salt, &toint, sizeof(toint));

        ft_kdf(pass, (t_uchar*)enc_ciph->salt, enc_ciph->key, enc_ciph->iv);
    }
    else {
        // printf("here\n");
        ft_memcpy(enc_ciph->key, opt->key, FT_KEY_LEN);
        ft_memcpy(enc_ciph->iv, opt->iv, ft_strlen(opt->iv));
    }


    toint = ft_hextoi(enc_ciph->key);
    // printf("%llu\n", toint);

    ft_memcpy(enc_ciph->key, &toint, sizeof(toint));
    // printf("%x\n", enc_ciph->key);

    toint = ft_hextoi(enc_ciph->iv);
    ft_memcpy(enc_ciph->iv, &toint, sizeof(toint));

    return (FT_EXOK);
}
