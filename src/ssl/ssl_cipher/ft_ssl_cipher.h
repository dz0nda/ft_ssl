/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:32 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/03 17:14:34 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_SSL_CIPHER_H
# define FT_SSL_CIPHER_H

# include "../../ft_ssl_global.h"

typedef enum		e_cipher_command_enum
{
	FT_BASE64,
	FT_DES,
	FT_CIPHER_CMD
}					t_cipher_cmd_e;

typedef struct  s_ftssl_cipher_dist
{
    char    *dist_name;
    int     dist_key;
}               t_ftssl_cipher_dist;

typedef struct  s_ftssl_cipher
{
    int          cmd_key;
    char                *cmd_name;
}               t_ftssl_cipher;

int					ft_ssl_cipher(int cmd_key, char *cmd_name, int argc, char *argv[]);
int     			ft_ssl_cipher_dispatch_dist(char *dist_name);

#endif
