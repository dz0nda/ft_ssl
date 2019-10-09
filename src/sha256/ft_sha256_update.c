#include "ft_sha256.h"
#include <stdio.h>

static uint32_t		ft_leftrotate(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

static uint32_t		ft_rightrotate(uint32_t x, uint32_t c)
{
	return ((x >> c) | (x << (32 - c)));
}


static void			ft_sha256_update_process(uint32_t abcd[4], uint32_t *m, int j)
{
    const uint32_t k[64] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
   0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
   0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
   0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
   0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
   0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
   0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };
	uint32_t fg[2];

	fg[0] = ft_md5_process_f(j, abcd[1], abcd[2], abcd[3]);
	fg[1] = ft_md5_process_g(j);
	fg[0] += abcd[0] + k[j] + m[fg[1]];
	abcd[0] = abcd[3];
	abcd[3] = abcd[2];
	abcd[2] = abcd[1];
	abcd[1] += ft_leftrotate(fg[0], s[j]);
}

int				ft_sha256_update(t_ft_sha256_ctx *ctx, const void *data, unsigned long len)
{
	uint32_t	abcd[4];
	uint32_t	*m;
	size_t		i;
	int			j;

	i = 0;
	j = -1;
	while (i < len)
	{
		m = (uint32_t *)data;
        while (++j < )
		// while (++j < 4)
		// 	abcd[j] = ctx->state[j];
		// j = -1;
		// while (++j < 64)
		// 	ft_md5_update_process(abcd, m, j);
		// j = -1;
		// while (++j < 4)
		// 	ctx->state[j] += abcd[j];
		// i += 64;
	}
}