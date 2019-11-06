#include "ft_dgst.h"

int			ft_sha384_init(t_dgst_ctx *ctx)
{
    ctx->state64[0] = 0xcbbb9d5dc1059ed8;
    ctx->state64[1] = 0x629a292a367cd507;
    ctx->state64[2] = 0x9159015a3070dd17;
    ctx->state64[3] = 0x152fecd8f70e5939;
    ctx->state64[4] = 0x67332667ffc00b31;
    ctx->state64[5] = 0x8eb44a8768581511;
    ctx->state64[6] = 0xdb0c2e0d64f98fa7;
    ctx->state64[7] = 0x47b5481dbefa4fa4;
	return (EXIT_SUCCESS);
}