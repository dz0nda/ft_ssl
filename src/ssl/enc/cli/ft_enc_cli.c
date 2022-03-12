
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enc_ciphers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:49:26 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/07 21:48:48 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enc_cli.h"

int ft_enc_cli(t_enc_cli_opt* opts, int argc, const char* argv[]) {
    t_arg arg;

    arg.i = 1;
    arg.c = argc;
    arg.v = argv;

    // if (!ft_strequ("enc", argv[0])) {
    // 	// parse_alias_command(&ctx, argv[0])
    // 	if (ft_enc_get_ciph(enc.cipher, *argv) == FT_EXFAIL) {
    // 		printf("errooor\n");
    // 		// return (FT_EXFAIL);
    // 	}
    // 	argc -= 1;
    // 	argv += 1;
    // }

    while (*arg.v && ft_isopt(*arg.v)) {



        return (FT_EXOK);
    }
