/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_init.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 00:17:22 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 05:02:03 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_init(t_dgst *ftssl_dgst, const char *cmd_name)
{
	const t_dgst ftssl_dgst_table[FT_DGST_CMD] = {
        { 
            FT_MD5, "md5", 
            { FT_MD5_HS, FT_MD5_MBS, FT_DGST_ENDIAN_LITTLE, FT_MD5_HS / 4 },
            { ft_md5_init, ft_md5_transform, ft_dgst_final, ft_ssl_dgst_result }
        },
        {
            FT_SHA1, "sha1",
            { FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_ENDIAN_BIG, FT_SHA1_HS / 4 },
            { ft_sha1_init, ft_sha1_transform, ft_dgst_final, ft_ssl_dgst_result }
        },
        {
            FT_SHA256, "sha256",
            { FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_ENDIAN_BIG, FT_SHA256_HS / 4 },
            { ft_sha256_init, ft_sha256_transform, ft_dgst_final, ft_ssl_dgst_result }
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
    return (EXIT_SUCCESS);
}
