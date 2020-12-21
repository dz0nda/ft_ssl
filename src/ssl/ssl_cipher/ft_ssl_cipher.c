/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cipher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:39 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/21 13:35:09 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_cipher.h"

int		ft_ssl_cipher(int argc, char *argv[])
{
	if (ft_ssl_cipher_dist(argc, argv) == FT_SSL_CIPHER_NOT_FOUND)
		return (FT_SSL_CIPHER_NOT_FOUND);
	return (EXIT_SUCCESS);
}
