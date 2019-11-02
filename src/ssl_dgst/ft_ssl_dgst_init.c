#include "ft_ssl_dgst.h"

int      ft_dgst_init(int cmd_key, t_dgst *dgst)
{
    const t_dgst_ctx_d dispatcher[FT_DGST_CMD] = {
        { FT_MD5, { FT_MD5_HS, FT_MD5_MBS, FT_DGST_ENDIAN_LITTLE, FT_MD5_HS / 4 } },
		{ FT_SHA1, { FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_ENDIAN_BIG, FT_SHA1_HS / 4 } },
        { FT_SHA256, { FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_ENDIAN_BIG, FT_SHA256_HS / 4 } }
    };

}

int      ft_dgst_dispatcher_ctx(int cmd_key, t_dgst_ctx *ctx)
{
    const t_dgst_ctx_d dispatcher[FT_DGST_CMD] = {
        { FT_MD5, { FT_MD5_HS, FT_MD5_MBS, FT_DGST_ENDIAN_LITTLE, FT_MD5_HS / 4 } },
		{ FT_SHA1, { FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_ENDIAN_BIG, FT_SHA1_HS / 4 } },
        { FT_SHA256, { FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_ENDIAN_BIG, FT_SHA256_HS / 4 } }
    };
    int i;

    i = -1;
    while (++i < FT_DGST_CMD)
        if (cmd_key == dispatcher[i].cmd_key)
            break;
	if (i == FT_DGST_CMD)
		return (EXIT_FAILURE);
    ft_memcpy(ctx, &dispatcher[i].ctx, sizeof(t_dgst_ctx));
    // *ctx = dispatcher[i].ctx;
    if ((ctx->state = (uint32_t *)ft_memalloc(sizeof(uint32_t) * ctx->len_state)) == NULL)
        return (EXIT_FAILURE);
    if ((ctx->block = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (ctx->len_mbs * 2))) == NULL)
    {
        free(ctx->state);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int		ft_dgst_dispatcher_act(int cmd_key, t_dgst_act *act)
{
	const t_dgst_act dispatcher[FT_DGST_CMD] = {
        { FT_MD5, ft_dgst_init_md5_sha1, ft_dgst_update_md5, ft_dgst_final }, 
        { FT_SHA1, ft_dgst_init_md5_sha1, ft_dgst_update_sha1, ft_dgst_final },
        { FT_SHA256, ft_dgst_init_sha256, ft_dgst_update_256, ft_dgst_final }
	};
    int i;

    i = -1;
    while (++i < FT_DGST_CMD)
        if (cmd_key == dispatcher[i].cmd_key)
            break;
	if (i == FT_DGST_CMD)
		return (EXIT_FAILURE);
    // *act = dispatcher[i];
    ft_memcpy(act, &dispatcher[i], sizeof(t_dgst_act));
	return (EXIT_SUCCESS);
}