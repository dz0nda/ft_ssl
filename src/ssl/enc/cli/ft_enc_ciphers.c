/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_ciphers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/14 21:41:05 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enc_cli.h"

const t_enc_ciph enc_ciph_table[FT_ENC_CIPH_MAX] = {
    { FT_ENC_CIPH_DES,      FT_ENC_DES,     { ft_des_ecb_encrypt, ft_des_ecb_decrypt } },
    { FT_ENC_CIPH_DES_CBC,  FT_ENC_DES_CBC, { ft_des_cbc_encrypt, ft_des_cbc_decrypt } },
    { FT_ENC_CIPH_DES_ECB,  FT_ENC_DES_ECB, { ft_des_ecb_encrypt, ft_des_ecb_decrypt } }
};

int ft_enc_get_ciph(t_enc_cyph_ft* cipher[2], t_arg* arg) {
    int i = -1;

    while (++i < FT_ENC_CIPH_MAX) {
        if (ft_strequ(*(arg->v) + 1, enc_ciph_table[i].name)) {
            cipher[0] = enc_ciph_table[i].ft[0];
            cipher[1] = enc_ciph_table[i].ft[1];

            arg->c -= 1;
            arg->v += 1;

            return (FT_EXOK);
        }
    }

    return (FT_EXFAIL);
}

// int ft_enc_parse_cipher(t_enc_ciph* ciph, char* argv) {
//     int i = -1;

//     while (++i < FT_ENC_CIPH_MAX) {
//         if (ft_strequ(argv, enc_ciph_table[i].name))
//             ciph = enc_ciph_table[i];
//     }

//     return (FT_EXOK);
// }

void ft_enc_cipher_iter(t_enc_ciph* ciph, void (*f)(t_enc_ciph)) {
    int i = -1;

    while (++i < FT_ENC_CIPH_MAX)
        f(enc_ciph_table[i]);
}

