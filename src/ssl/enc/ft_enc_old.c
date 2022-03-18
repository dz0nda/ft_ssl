// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_enc.c                                    		:+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
// /*   Updated: 2021/08/09 13:32:23 by user42           ###   ########lyon.fr   */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_enc.h"

// int		ft_enc_dist(t_ssl_cipher* ctx, int argc, char* argv[])
// {
//     static t_ssl_cipher_dist dist[FT_SSL_CIPHER_DIST] = {
//         { "base64", 	FT_SSL_CIPHER_BASE64, ft_ssl_base64 },
//         { "des", 		FT_SSL_CIPHER_DES, ft_ssl_des },
//         { "des-ecb",	FT_SSL_CIPHER_DES_ECB, ft_ssl_des },
//         { "des-cbc", 	FT_SSL_CIPHER_DES_CBC, ft_ssl_des },
//     };
//     int							dist_key;

//     dist_key = -1;
//     while (++dist_key < FT_SSL_CIPHER_DIST)
//     {
//         if (argc == -42)
//             ft_putendl_fd(dist[dist_key].dist_name, STDERR_FILENO);
//         else if (ft_strequ(argv[0], dist[dist_key].dist_name))
//         {
//             ctx->dist = dist[dist_key];
//             return(dist_key);
//         }
//     }
//     return (FT_SSL_CIPHER_NOT_FOUND);
// }

// int 	ft_enc_old(int argc, char* argv[]) {
//     t_ssl_cipher	ctx;

//     ft_memset(&ctx, 0, sizeof(ctx));
//     if (ft_enc_dist(&ctx, argc, argv) == FT_SSL_CIPHER_NOT_FOUND)
//         return (FT_SSL_CIPHER_NOT_FOUND);
//     return (ctx.dist.dist_ft(argc, argv));
// }

