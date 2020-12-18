#include "ft_sha.h"

int			ft_sha384_init(t_dgst_ctx *ctx)
{
    ctx->hs = FT_SHA384_HS;
	ctx->mbs = FT_SHA384_MBS;
	ctx->endian = FT_DGST_ENDIAN_BIG;
	ctx->sts = FT_SHA384_STATE;
	ctx->x = FT_DGST_X64;
    ctx->state.x_64[0] = 0xcbbb9d5dc1059ed8;
    ctx->state.x_64[1] = 0x629a292a367cd507;
    ctx->state.x_64[2] = 0x9159015a3070dd17;
    ctx->state.x_64[3] = 0x152fecd8f70e5939;
    ctx->state.x_64[4] = 0x67332667ffc00b31;
    ctx->state.x_64[5] = 0x8eb44a8768581511;
    ctx->state.x_64[6] = 0xdb0c2e0d64f98fa7;
    ctx->state.x_64[7] = 0x47b5481dbefa4fa4;
	return (EXIT_SUCCESS);
}
