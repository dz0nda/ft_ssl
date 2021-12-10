/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:10:56 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/12 18:02:34 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
#define FT_SSL_H

#include "./ssl_core/ft_ssl_core.h"

typedef struct s_ftssl_dist
{
	int key_dist;
	t_ftssl_dist *dist_ft;
} t_ftssl_dist_t;

typedef struct s_ftssl
{
	int key_dist;
	int shmode;
	int err;
	t_ftssl_sh sh;
} t_ftssl;

#endif
