/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:07:28 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/04 01:28:45 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_dgst.h"

char	*ft_dgst(int dgst_key, char *arg, int arg_type, char *md, int outp)
{
	const t_sha_dist g_sha_dist[FT_SHA_VERSION] = {
		{ FT_MD5, ft_md5_init, ft_md5_transform, ft_md5_final },
		{ FT_SHA1, ft_sha1_init, ft_sha1_transform, ft_sha1_final },
		{ FT_SHA224, ft_sha224_init, ft_sha256_transform, ft_sha256_final },
		{ FT_SHA256, ft_sha256_init, ft_sha256_transform, ft_sha256_final },
		{ FT_SHA384, ft_sha384_init, ft_sha512_transform, ft_sha512_final },
		{ FT_SHA512, ft_sha512_init, ft_sha512_transform, ft_sha512_final },
		{ FT_SHA512224, ft_sha512224_init, ft_sha512_transform, ft_sha512_final },
		{ FT_SHA512256, ft_sha512256_init, ft_sha512_transform, ft_sha512_final }
	};
	t_dgst	dgst;

	ft_memset(&dgst, 0, sizeof(dgst));
	g_sha_dist[dgst_key].init(&dgst.ctx);
	if (arg_type == FT_DGST_STRING)
		ft_dgst_input(&dgst, (uint8_t *)arg, ft_strlen(arg), g_sha_dist[dgst_key].hash);
	else
		ft_dgst_input_file(&dgst, arg, outp, g_sha_dist[dgst_key].hash);
	g_sha_dist[dgst_key].final(&dgst.ctx);
	ft_dgst_result(&dgst.ctx, md);
	return (md);
}