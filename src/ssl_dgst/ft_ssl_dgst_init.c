/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_init.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 00:17:22 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 07:23:28 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_init(t_dgst *ftssl_dgst, const char *cmd_name)
{
	const t_dgst ftssl_dgst_table[FT_DGST_CMD] = {
        { 
            FT_MD5, "md5", 
            { { FT_MD5_HS, FT_MD5_MBS, FT_DGST_ENDIAN_LITTLE, FT_MD5_STATE },
            ft_md5_init, ft_md5_transform, ft_md5_final }, 
            ft_ssl_dgst_output
        },
        {
            FT_SHA1, "sha1",
            { { FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_ENDIAN_BIG, FT_SHA1_STATE },
            ft_sha1_init, ft_sha1_transform, ft_sha1_final },
            ft_ssl_dgst_output
        },
        {
            FT_SHA256, "sha256",
            { { FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_ENDIAN_BIG, FT_SHA256_STATE },
            ft_sha256_init, ft_sha256_transform, ft_sha1_final },
            ft_ssl_dgst_output
        },
        {
            FT_SHA384, "sha384",
            { { FT_SHA384_HS, FT_SHA384_MBS, FT_DGST_ENDIAN_BIG, FT_SHA384_STATE },
            ft_sha384_init, ft_sha512_transform, ft_sha512_final },
            ft_ssl_dgst_output
        },
        {
            FT_SHA512, "sha512",
            { { FT_SHA512_HS, FT_SHA512_MBS, FT_DGST_ENDIAN_BIG, FT_SHA512_STATE },
            ft_sha512_init, ft_sha512_transform, ft_sha512_final },
            ft_ssl_dgst_output
        } 
    };
    int i;

    i = -1;
    while (++i < FT_DGST_CMD)
        if (ft_strcmp(ftssl_dgst_table[i].cmd_name, cmd_name) == 0)
            break;
	if (i == FT_DGST_CMD)
		return (EXIT_FAILURE);
    ft_memcpy(ftssl_dgst, &ftssl_dgst_table[i], sizeof(t_dgst));
    // ftssl_dgst->output = ft_ssl_dgst_output;
    return (EXIT_SUCCESS);
}
