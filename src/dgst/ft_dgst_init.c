#include "ft_dgst.h"

// int			ft_ssl_dgst_init_md5_sha1(uint32_t *ctx_)
// {
// 	const uint32_t init[5] = {
// 		0x67452301, 0xefcdab89, 0x98badcfe,
// 		0x10325476, 0xC3D2E1F0
// 	};
// 	int i;

// 	i = -1;
// 	while(++i < ctx->len_state)
// 		ctx->state[i] = init[i];
// 	return (EXIT_SUCCESS);
// }

int			ft_md5_init(t_md5_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_md5_ctx));
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xefcdab89;
	ctx->state[2] = 0x98badcfe;
	ctx->state[3] = 0x10325476;
	return (EXIT_SUCCESS);
}

int			ft_sha1_init(t_sha1_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_sha1_ctx));
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xEFCDAB89;
	ctx->state[2] = 0x98BADCFE;
	ctx->state[3] = 0x10325476;
	ctx->state[4] = 0xC3D2E1F0;
	return (EXIT_SUCCESS);
}

int			ft_sha256_init(t_sha256_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_sha256_ctx));
	ctx->state[0] = 0x6a09e667;
	ctx->state[1] = 0xbb67ae85;
	ctx->state[2] = 0x3c6ef372;
	ctx->state[3] = 0xa54ff53a;
	ctx->state[4] = 0x510e527f;
	ctx->state[5] = 0x9b05688c;
	ctx->state[6] = 0x1f83d9ab;
	ctx->state[7] = 0x5be0cd19;
	return (EXIT_SUCCESS);
}