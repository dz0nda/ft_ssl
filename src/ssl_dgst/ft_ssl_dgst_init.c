#include "ft_ssl_dgst.h"

int			ft_ssl_dgst_init_sha256(t_dgst_ctx *ctx)
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
