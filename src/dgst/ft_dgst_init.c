#include "ft_dgst.h"

int			ft_dgst_init_md5_sha1(t_dgst_ctx *ctx)
{
	const uint32_t init[5] = {
		0x67452301, 0xefcdab89, 0x98badcfe,
		0x10325476, 0xC3D2E1F0
	};
	int i;

	i = -1;
	while(++i < ctx->len_state)
		ctx->state[i] = init[i];
	return (EXIT_SUCCESS);
}

int			ft_dgst_init_sha256(t_dgst_ctx *ctx)
{
	const uint32_t init[8] = {
		0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
		0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
	};
	int i;

	i = -1;
	while(++i < ctx->len_state)
		ctx->state[i] = init[i];
	return (EXIT_SUCCESS);
}
