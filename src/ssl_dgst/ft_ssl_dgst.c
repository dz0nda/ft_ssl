#include "ft_ssl_dgst.h"

t_dgst_ctx      ft_ssl_dgst_init_ctx(int cmd_key)
{
    const t_dgst_ctx dispatcher[FT_DGST_CMD] = {
        { FT_MD5, FT_MD5_HS, FT_MD5_MBS, FT_DGST_LITTLE_ENDIAN, FT_MD5_HS / 4, NULL, NULL },
		{ FT_SHA1, FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_BIG_ENDIAN, FT_SHA1_HS / 4, NULL, NULL },
        { FT_SHA256,FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_BIG_ENDIAN, FT_SHA256_HS / 4, NULL, NULL }
    };
    int i;
    t_dgst_ctx ctx;

    i = -1;
    ft_memset(&ctx, 0, sizeof(t_dgst_ctx));
    while (++i < FT_DGST_CMD)
        if (cmd_key == dispatcher[i].cmd_key)
            break;
    ft_memcpy(&ctx, &dispatcher[i], sizeof(t_dgst_ctx));
    return (ctx);
	// const int dgst_ctx[FT_DGST_CMD][4] = {
	// 	{ FT_MD5, FT_MD5_HS, FT_MD5_MBS, FT_DGST_LITTLE_ENDIAN},
	// 	{ FT_SHA1, FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_BIG_ENDIAN},
	// 	{ FT_SHA256,FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_BIG_ENDIAN}
	// };
	// t_dgst_ctx	*ctx;	

	// ctx = NULL;
	// if ((ctx = (t_dgst_ctx *)malloc(sizeof(t_dgst_ctx))) == NULL)
	// 	return (NULL);
	// ft_memset(ctx, 0, sizeof(t_dgst_ctx));
	// ctx->len_hs = dgst_ctx[cmd_key][1];
	// ctx->len_mbs = dgst_ctx[cmd_key][2];
	// ctx->endian = dgst_ctx[cmd_key][3];
	// ctx->len_state = ctx->len_hs / 4;
	// ctx->state = (uint32_t *)malloc(sizeof(uint32_t) * ctx->len_state);
	// ctx->block = (uint8_t *)malloc(sizeof(uint8_t) * ctx->len_mbs);
	// if (ctx->state == NULL || ctx->block == NULL)
	// {
	// 	ctx->state != NULL ? free(ctx->state) : 0;
	// 	ctx->block != NULL ? free(ctx->block) : 0;
	// 	free(ctx);
	// 	return (NULL);
	// }
	// return (ctx);
}


int     ft_ssl_dgst(int cmd_key, int argc, char *argv[])
{
    printf("dgst has been.\n");
    t_dgst_ctx  ctx;
 
    ctx = ft_ssl_dgst_init_ctx(cmd_key);
    printf("cmd = %d && hs = %d\n", ctx.cmd_key, ctx.len_hs);
    return (0);   
}
