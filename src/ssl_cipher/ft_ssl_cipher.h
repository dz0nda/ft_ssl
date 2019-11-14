/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_cipher.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:13:32 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 10:09:26 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_CIPHER_H
# define FT_SSL_CIPHER_H

# include "../ft_ssl_global.h"

typedef enum		e_cipher_command_enum
{
	FT_BASE64,
	FT_DES,
	FT_CIPHER_CMD
}					t_cipher_cmd_e;

int					ft_ssl_cipher(int argc, char *argv[]);

#endif
