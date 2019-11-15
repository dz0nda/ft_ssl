/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dgst.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:07:28 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 09:29:27 by dzonda      ###    #+. /#+    ###.fr     */
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

size_t		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

int			ft_dgst_init(t_dgst *dgst, int cmd_key)
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

char		*ft_dgst_file(int cmd_key, char *filename, int outp,
		char *cmd_dgst)
{
	int		fd;
	t_dgst	dgst;

	fd = 0;
	ft_memset(&dgst, 0, sizeof(dgst));
	ft_dgst_init(&dgst, cmd_key);
	dgst.dist.init(&dgst.ctx);
	if (filename != NULL && (fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while ((dgst.ctx.iblock = read(fd, dgst.ctx.block, dgst.ctx.len_mbs)) ==
			dgst.ctx.len_mbs)
	{
		dgst.ctx.idata += dgst.ctx.iblock;
		dgst.dist.transform(&dgst.ctx);
		if (outp == FT_SSL_TRUE)
			ft_putstr((const char *)dgst.ctx.block);
		ft_memset(dgst.ctx.block, 0, sizeof(dgst.ctx.block));
	}
	if (filename != NULL)
		close(fd);
	if (outp == FT_SSL_TRUE)
		ft_putstr((const char *)dgst.ctx.block);
	dgst.ctx.idata += dgst.ctx.iblock;
	dgst.dist.final(&dgst.ctx);
	dgst.dist.result(&dgst.ctx, cmd_dgst);
	return (cmd_dgst);
}

char		*ft_dgst_string(int cmd_key, char *cmd_arg, int cmd_arg_len,
		char *cmd_dgst)
{
	t_dgst	dgst;

	ft_memset(&dgst, 0, sizeof(dgst));
	ft_dgst_init(&dgst, cmd_key);
	dgst.dist.init(&dgst.ctx);
	while (dgst.ctx.idata < cmd_arg_len)
	{
		dgst.ctx.block[dgst.ctx.iblock++] = cmd_arg[dgst.ctx.idata++];
		if (dgst.ctx.iblock == dgst.ctx.len_mbs)
		{
			dgst.dist.transform(&dgst.ctx);
			dgst.ctx.iblock = 0;
		}
	}
	dgst.dist.final(&dgst.ctx);
	dgst.dist.result(&dgst.ctx, cmd_dgst);
	return(cmd_dgst);
}
