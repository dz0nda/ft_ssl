/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:33:43 by dzonda            #+#    #+#             */
/*   Updated: 2020/02/29 13:01:36 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_dgst.h"

const t_digest_dispatch g_dgst_dispatcher[FT_DGST_CMD] = {
	{
		FT_MD5, FT_MD5_HS, FT_MD5_MBS, FT_DGST_ENDIAN_LITTLE, FT_MD5_STATE,
		FT_DGST_X32, ft_md5_init, ft_md5_transform
	},
	{
		FT_SHA1, FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_ENDIAN_BIG, FT_SHA1_STATE,
		FT_DGST_X32, ft_sha1_init, ft_sha1_transform
	},
	{
		FT_SHA224, FT_SHA224_HS, FT_SHA224_MBS, FT_DGST_ENDIAN_BIG,
		FT_SHA224_STATE, FT_DGST_X32, ft_sha224_init, ft_sha256_transform
	},
	{
		FT_SHA256, FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_ENDIAN_BIG, 
		FT_SHA256_STATE, FT_DGST_X32, ft_sha256_init, ft_sha256_transform
	},
	{
		FT_SHA384, FT_SHA384_HS, FT_SHA384_MBS, FT_DGST_ENDIAN_BIG, 
		FT_SHA384_STATE, FT_DGST_X64, ft_sha384_init, ft_sha512_transform
	},
	{
		FT_SHA512, FT_SHA512_HS, FT_SHA512_MBS, FT_DGST_ENDIAN_BIG, 
		FT_SHA512_STATE, FT_DGST_X64, ft_sha512_init, ft_sha512_transform
	},
	{
		FT_SHA512224,FT_SHA512224_HS, FT_SHA512224_MBS, FT_SHA512224_ENDIAN, 
		FT_SHA512224_STATE, FT_DGST_X64, ft_sha512224_init, ft_sha512_transform
	},
	{
		FT_SHA512256, FT_SHA512256_HS, FT_SHA512256_MBS, FT_SHA512256_ENDIAN, 
		FT_SHA512256_STATE, FT_DGST_X64, ft_sha512256_init, ft_sha512_transform
	}
};

int		ft_dgst_init_d(t_dgst *dgst, int cmd_key)
{
	int i;

	i = -1;
	while (++i < FT_DGST_CMD)
		if (cmd_key == g_dgst_dispatcher[i].dgst_key)
			break;
	if (i == FT_DGST_CMD)
		return (EXIT_FAILURE);
	ft_memcpy(dgst, &g_dgst_dispatcher[i], sizeof(*dgst));
	return (EXIT_SUCCESS);
}

const t_dgst g_dgst_dist[FT_DGST_CMD] = {
	{ FT_MD5, 
		{
			FT_MD5_HS, 
			FT_MD5_MBS, 
			FT_DGST_ENDIAN_LITTLE, 
			FT_MD5_STATE,
			FT_DGST_X32,
			0, 0,
			{
				.x_32 = {
					0x67452301,
					0xefcdab89,
					0x98badcfe,
					0x10325476
				}
			},
			{ 0 }, { 0 }
		},
		{ 
			ft_md5_transform, 
		}
	},
	{ FT_SHA1, 
		{ 
			FT_SHA1_HS, 
			FT_SHA1_MBS, 
			FT_DGST_ENDIAN_BIG, 
			FT_SHA1_STATE,
			FT_DGST_X32,
			0, 0,
			{ 
				.x_32 = {
					0x67452301,
					0xefcdab89,
					0x98badcfe,
					0x10325476,
					0xc3d2e1f0
				}
			}, { 0 }, { 0 }
		}, 
		{ 
			ft_sha1_transform, 
		}
	},
	{ FT_SHA224, 
		{ 
			FT_SHA224_HS, 
			FT_SHA224_MBS, 
			FT_DGST_ENDIAN_BIG,
			FT_SHA224_STATE,
			FT_DGST_X32,
			0, 0,
			{
				.x_32 = {
					0xc1059ed8,
					0x367cd507,
					0x3070dd17,
					0xf70e5939,
					0xffc00b31,
					0x68581511,
					0x64f98fa7,
					0xbefa4fa4
				}
			}, { 0 }, { 0 } 
		}, 
		{ 
			ft_sha256_transform, 
		}
	},
	{ FT_SHA256, 
		{ 
			FT_SHA256_HS, 
			FT_SHA256_MBS, 
			FT_DGST_ENDIAN_BIG, 
			FT_SHA256_STATE,
			FT_DGST_X32,
			0, 0, 
			{ 
				.x_32 = {
					0x6a09e667,
					0xbb67ae85,
					0x3c6ef372,
					0xa54ff53a,
					0x510e527f,
					0x9b05688c,
					0x1f83d9ab,
					0x5be0cd19
				}
			},
			{ 0 }, { 0 } 
		}, 
		{ 
			ft_sha256_transform, 
		}
	},
	{ FT_SHA384, 
		{ 
			FT_SHA384_HS, 
			FT_SHA384_MBS, 
			FT_DGST_ENDIAN_BIG, 
			FT_SHA384_STATE,
			FT_DGST_X64,
			0, 0,
			{
				.x_64 = {
					0xcbbb9d5dc1059ed8,
					0x629a292a367cd507,
					0x9159015a3070dd17,
					0x152fecd8f70e5939,
					0x67332667ffc00b31,
					0x8eb44a8768581511,
					0xdb0c2e0d64f98fa7,
					0x47b5481dbefa4fa4
				}
			}, 
			{ 0 }, { 0 } 
		},
		{ 
			ft_sha512_transform 
		}
	},
	{ FT_SHA512, 
		{ 
			FT_SHA512_HS, 
			FT_SHA512_MBS, 
			FT_DGST_ENDIAN_BIG, 
			FT_SHA512_STATE, 
			FT_DGST_X64,
			0, 0,
			{ 
				.x_64 = {
					0x6a09e667f3bcc908,
					0xbb67ae8584caa73b,
					0x3c6ef372fe94f82b,
					0xa54ff53a5f1d36f1,
					0x510e527fade682d1,
					0x9b05688c2b3e6c1f,
					0x1f83d9abfb41bd6b,
					0x5be0cd19137e2179
				}
			}, 
			{ 0 }, { 0 } 
		},
		{ ft_sha512_transform }
	},
	{ FT_SHA512224, 
		{ 
			FT_SHA512224_HS, 
			FT_SHA512224_MBS, 
			FT_SHA512224_ENDIAN, 
			FT_SHA512224_STATE, 
			FT_DGST_X64,
			0, 0,
			{ 
				.x_64 = {
					0x8C3D37C819544DA2,
					0x73E1996689DCD4D6,
					0x1DFAB7AE32FF9C82,
					0x679DD514582F9FCF,
					0x0F6D2B697BD44DA8,
					0x77E36F7304C48942,
					0x3F9D85A86A1D36C8,
					0x1112E6AD91D692A1
				}
			}, 
			{ 0 }, { 0 } 
		},
		{ ft_sha512_transform }
	},
	{ FT_SHA512256, 
		{ 
			FT_SHA512256_HS, 
			FT_SHA512256_MBS, 
			FT_SHA512256_ENDIAN, 
			FT_SHA512256_STATE, 
			FT_DGST_X64,
			0, 0,
			{ 
				.x_64 = {
					0x22312194FC2BF72C,
					0x9F555FA3C84C64C2,
					0x2393B86B6F53B151,
					0x963877195940EABD,
					0x96283EE2A88EFFE3,
					0xBE5E1E2553863992,
					0x2B0199FC2C85B8AA,
					0x0EB72DDC81C52CA2
				}
			}, 
			{ 0 }, { 0 } 
		},
		{ ft_sha512_transform }
	},
};


int		ft_dgst_init(t_dgst *dgst, int cmd_key)
{
	int i;

	i = -1;
	while (++i < FT_DGST_CMD)
		if (cmd_key == g_dgst_dist[i].dist_enum)
			break;
	if (i == FT_DGST_CMD)
		return (EXIT_FAILURE);
	ft_memcpy(dgst, &g_dgst_dist[i], sizeof(*dgst));
	return (EXIT_SUCCESS);
}