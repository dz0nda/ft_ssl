#include "ft_sha.h"

int			ft_sha224_init(t_dgst_ctx *ctx)
{
    ctx->hs = FT_SHA224_HS;
	ctx->mbs = FT_SHA224_MBS;
	ctx->endian = FT_DGST_ENDIAN_BIG;
	ctx->sts = FT_SHA224_STATE;
	ctx->x = FT_DGST_X32;
    ctx->state.x_32[0] = 0xc1059ed8;
    ctx->state.x_32[1] = 0x367cd507;
    ctx->state.x_32[2] = 0x3070dd17;
    ctx->state.x_32[3] = 0xf70e5939;
    ctx->state.x_32[4] = 0xffc00b31;
    ctx->state.x_32[5] = 0x68581511;
    ctx->state.x_32[6] = 0x64f98fa7;
    ctx->state.x_32[7] = 0xbefa4fa4;
	return (EXIT_SUCCESS);
}
