#include "ft_md5.h"

int   ft_md5_init(t_ft_md5_ctx *ctx)
{
  ft_memset(ctx, 0, sizeof(t_ft_md5_ctx));
  ctx->state[0] = 0x67452301;
  ctx->state[1] = 0xefcdab89;
  ctx->state[2] = 0x98badcfe;
  ctx->state[3] = 0x10325476;
  return (EXIT_SUCCESS);
}