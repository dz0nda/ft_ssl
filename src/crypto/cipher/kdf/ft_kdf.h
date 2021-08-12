/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/09 10:18:32 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_KDF_H
#define FT_KDF_H

#include <bsd/readpassphrase.h>

#include "../../../ft_ssl_global.h"
#include "../../dgst/udgst/ft_udgst.h"

/*
**	KDF
*/
int ft_kdf(char *pass, const t_uchar *salt, char *key, char *iv);

#endif
