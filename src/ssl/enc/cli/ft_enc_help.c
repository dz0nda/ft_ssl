/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:32 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/18 15:40:36 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ft_enc_cli.h"

const t_enc_opt_t opt_table[FT_ENC_OPT_MAX] = {
    {
        FT_ENC_OPT_A,
        "a",
        "Perform base64 encoding/decoding (alias -base64)",
        ft_enc_opt_a
    },
    {
        FT_ENC_OPT_D,
        "d",
        "Decrypt the input data",
        ft_enc_opt_d
    },
    {
        FT_ENC_OPT_E,
        "e",
        "Encrypt the input data (default)",
        ft_enc_opt_e
    },
    {
        FT_ENC_OPT_I,
        "i",
        "Input file to read from (default stdin)",
        ft_enc_opt_i
    },
    {
        FT_ENC_OPT_K,
        "k",
        "Key to use, specified as a hexadecimal string",
        ft_enc_opt_k
    },
    {
        FT_ENC_OPT_O,
        "o",
        "Output file to write to (default stdout)",
        ft_enc_opt_o
    },
    {
        FT_ENC_OPT_P,
        "p",
        "Password in ascii",
        ft_enc_opt_p
    },
    {
        FT_ENC_OPT_S,
        "s",
        "Salt to use, specified as a hexadecimal string",
        ft_enc_opt_s
    },
    {
        FT_ENC_OPT_V,
        "v",
        "IV to use, specified as a hexadecimal string",
        ft_enc_opt_v
    },
};

// void ft_enc_opt_init(t_enc_opt ctx_opt[FT_ENC_OPT_MAX]) {
//     ft_memcpy(ctx_opt, enc_opt, sizeof(enc_opt));
// }

int ft_enc_get_opt(t_enc_opt* opt, t_arg* arg) {
    int i = -1;

    while (++i < FT_ENC_OPT_MAX) {
        if (ft_strequ(*(arg->v), opt_table[i].opt_name)) {
            return (opt_table[i].ft(opt, arg));
        }
    }

    return (FT_EXFAIL);
}

// int ft_enc_parse_cipher(t_enc_ciph* ciph, char* argv) {
//     int i = -1;

//     while (++i < FT_ENC_CIPH_MAX) {
//         if (ft_strequ(argv, enc_ciph_table[i].name))
//             ciph = &enc_ciph_table[i];
//     }

//     return (FT_EXOK);
// }


// const t_enc_ciph enc_ciph_table[FT_ENC_CIPH_MAX] = {
//     { FT_ENC_CIPH_DES, "des" },
//     { FT_ENC_CIPH_DES_CBC, "des-cbc" },
//     { FT_ENC_CIPH_DES_ECB, "des-ecb" },
// };

void    ft_display_option()
{
    int i = -1;

    while (++i < FT_ENC_OPT_MAX) {
        ft_putstr(" -");
        ft_putstr(opt_table[i].opt_name);
        ft_putstr("\t\t");
        ft_putendl(opt_table[i].opt_description);
    }
}

int		ft_enc_help(void)
{
    ft_putendl("usage: enc -ciphername [-ade] [-base64]");
    ft_putendl("    [-i file] [-v IV] [-k key] [-p password]");
    ft_putendl("    [-o file] [-s salt]\n");

    ft_display_option();

    ft_putendl("\nValid ciphername values:");
    ft_putendl("-des    -des-cbc    -des-ecb");

    return (FT_EXFAIL);
}
