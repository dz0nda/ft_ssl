/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 09:33:43 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 09:34:08 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

const t_dgst g_dgst_dist[FT_DGST_DIST] = {
	{ FT_MD5, 
		{ FT_MD5_HS, FT_MD5_MBS, FT_DGST_ENDIAN_LITTLE, FT_MD5_STATE,
			0, 0, { }, { 0 }, { 0 } },
		{ ft_md5_init, ft_md5_transform, ft_md5_final, ft_dgst_result_x32 }
	},
	{ FT_SHA1, 
		{ FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_ENDIAN_BIG, FT_SHA1_STATE,
			0, 0, { }, { 0 }, { 0 } }, 
		{ ft_sha1_init, ft_sha1_transform, ft_sha1_final, ft_dgst_result_x32 }
	},
	{ FT_SHA224, 
		{ FT_SHA224_HS, FT_SHA224_MBS, FT_DGST_ENDIAN_BIG,FT_SHA224_STATE,
			0, 0, { }, { 0 }, { 0 } }, 
		{ ft_sha224_init, ft_sha256_transform, ft_sha256_final, ft_dgst_result_x32 }
	},
	{ FT_SHA256, 
		{ FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_ENDIAN_BIG, FT_SHA256_STATE,
			0, 0, { }, { 0 }, { 0 } }, 
		{ ft_sha256_init, ft_sha256_transform, ft_sha256_final, ft_dgst_result_x32 }
	},
	{ FT_SHA384, 
		{ FT_SHA384_HS, FT_SHA384_MBS, FT_DGST_ENDIAN_BIG, FT_SHA384_STATE,
			0, 0, { }, { 0 }, { 0 } },
		{ ft_sha384_init, ft_sha512_transform, ft_sha512_final, ft_dgst_result_x64 }
	},
	{ FT_SHA512, 
		{ FT_SHA512_HS, FT_SHA512_MBS, FT_DGST_ENDIAN_BIG, FT_SHA512_STATE, 
			0, 0, { }, { 0 }, { 0 } },
		{ ft_sha512_init, ft_sha512_transform, ft_sha512_final, ft_dgst_result_x64 }
	}
};


int		ft_dgst_init(t_dgst *dgst, int cmd_key)
{
	int i;

	i = -1;
	while (++i < FT_DGST_DIST)
		if (cmd_key == g_dgst_dist[i].dist_enum)
			break;
	if (i == FT_DGST_DIST)
		return (EXIT_FAILURE);
	ft_memcpy(dgst, &g_dgst_dist[i], sizeof(*dgst));
	return (EXIT_SUCCESS);
}