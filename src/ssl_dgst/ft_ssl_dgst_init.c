#include "ft_ssl_dgst.h"

// int			ft_ssl_dgst_init(t_dgst_ctx *ctx, int cmd)
// {
// 	const ft_ssl_dgst_init[FT_SSL_DGST_CMD] = {
// 		{}
// 	}


// 	return (EXIT_SUCCESS);
// }

int			ft_ssl_dgst_md5_init(t_dgst_ctx *ctx)
{
	ft_memset((void *)&ctx->md5ctx, 0, sizeof(t_md5_ctx));
	ctx->md5ctx.state[0] = 0x67452301;
	ctx->md5ctx.state[1] = 0xefcdab89;
	ctx->md5ctx.state[2] = 0x98badcfe;
	ctx->md5ctx.state[3] = 0x10325476;
	return (EXIT_SUCCESS);
}

int			ft_ssl_dgst_sha1_init(t_dgst_ctx *ctx)
{
	ft_memset((void *)&ctx->sha1ctx, 0, sizeof(t_sha1_ctx));
	ctx->sha1ctx.state[0] = 0x67452301;
	ctx->sha1ctx.state[1] = 0xEFCDAB89;
	ctx->sha1ctx.state[2] = 0x98BADCFE;
	ctx->sha1ctx.state[3] = 0x10325476;
	ctx->sha1ctx.state[4] = 0xC3D2E1F0;
	return (EXIT_SUCCESS);
}

int			ft_ssl_dgst_sha256_init(t_dgst_ctx *ctx)
{
	ft_memset((void *)&ctx->sha256ctx, 0, sizeof(t_sha256_ctx));
	ctx->sha256ctx.state[0] = 0x6a09e667;
	ctx->sha256ctx.state[1] = 0xbb67ae85;
	ctx->sha256ctx.state[2] = 0x3c6ef372;
	ctx->sha256ctx.state[3] = 0xa54ff53a;
	ctx->sha256ctx.state[4] = 0x510e527f;
	ctx->sha256ctx.state[5] = 0x9b05688c;
	ctx->sha256ctx.state[6] = 0x1f83d9ab;
	ctx->sha256ctx.state[7] = 0x5be0cd19;
	return (EXIT_SUCCESS);
}