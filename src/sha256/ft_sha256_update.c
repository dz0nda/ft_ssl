#include "ft_sha256.h"
#include <stdio.h>

static void			ft_sha256_update_process(uint32_t abcd[8], uint32_t *w, int j)
{
    const uint32_t k[64] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
   0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
   0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
   0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
   0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
   0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
   0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };

	uint32_t S1;
	uint32_t S0;
	uint32_t ch;
	uint32_t temp1;
	uint32_t temp2;
	uint32_t maj;

	printf("[j = %d] A=%u, B=%u, C=%u, D=%u, E=%u, F=%u, G=%u, H=%u\n", j, abcd[0], abcd[1], abcd[2], abcd[3], abcd[4], abcd[5], abcd[6], abcd[7]);

	S1 = ft_rotate_right(abcd[4], 6) ^ ft_rotate_right(abcd[4], 11) ^ ft_rotate_right(abcd[4], 25);
	ch = (abcd[4] & abcd[5]) ^ ((~abcd[4]) & abcd[6]);
	temp1 = abcd[7] + S1 + ch + k[j] + w[j];
	
	S0 = ft_rotate_right(abcd[0], 2) ^ ft_rotate_right(abcd[0], 13) ^ ft_rotate_right(abcd[0], 22);
	maj = (abcd[0] & abcd[1]) ^ (abcd[0] & abcd[2]) ^ (abcd[1] & abcd[2]);
	
	temp2 = S0 + maj;
	
	abcd[7] = abcd[6];
	abcd[6] = abcd[5];
	abcd[5] = abcd[4];
	abcd[4] = abcd[3] + temp1;
	abcd[3] = abcd[2];
	abcd[2] = abcd[1];
	abcd[1] = abcd[0];
	abcd[0] = temp1 + temp2;

	// uint32_t s[2];
	// uint32_t ch;
	// uint32_t maj;
	// uint32_t temp[2];

	// s[1] = ft_sha256_sigma1b(abcd[4]);
	// ch = (abcd[4] & abcd[5]) ^ ((~abcd[4]) & abcd[6]);
	// temp[0] = abcd[7] + s[1] + ch + k[j] + m[j];
	// s[0] = ft_sha256_sigma0b(abcd[0]);
	// maj = (abcd[0] + abcd[1]) ^ (abcd[0] + abcd[2]) ^ (abcd[1] + abcd[2]);
	// temp[1] = s[0] + maj;

	// abcd[7] = abcd[6];
	// abcd[6] = abcd[5];
	// abcd[5] = abcd[4];
	// abcd[4] = abcd[3] + temp[0];
	// abcd[3] = abcd[2];
	// abcd[2] = abcd[1];
	// abcd[1] = abcd[0];
	// abcd[0] = temp[0] + temp[1];
}

void		ft_sha256_update_process_words(uint32_t m[64], const void *data)
{
	int 	t;

	t = 15;
	ft_strcpy(m, data);
	while (++t < 64)
		m[t] = ft_sha256_sigma1a(m[t-2]) + m[t-7] + ft_sha256_sigma0a(m[t-15]) + m[t-16];
}

static void			ft_sha256_update_show(uint32_t	*m)
{
	int i;

	i = -1;
	printf("Update show: \n");
    // m[0] = swap_uint32(m[0]);
	while (++i < 64)
		printf("Block[%d] = %x \n", i, m[i]);
	printf("\n");
}

static void          ft_sha256_update_break(uint32_t *w, const void *data)
{
    int i;
    uint32_t	*m;
	uint32_t 	s0;
	uint32_t 	s1;

    i = -1;
    m = (uint32_t *)data;
    while (++i < 16)
        w[i] = swap_uint32(m[i]);
	// w[15] = 24;
    while (i < 64)
	{
		s0 = ft_rotate_right(w[i-15], 7) ^ ft_rotate_right(w[i-15], 18) ^ ft_shift_right(w[i-15], 3);
		s1 = ft_rotate_right(w[i-2], 17) ^ ft_rotate_right(w[i-2], 19) ^ ft_shift_right(w[i-2], 10);
		w[i] = w[i-16] + s0 + w[i-7] + s1;
		// w[i] = swap_uint32(m[i]);
		// w[i] = ft_sha256_sigma1a(w[i-2]) + w[i-7] + ft_sha256_sigma0a(w[i-15]) + w[i-16];
		// w[i] = swap_uint32(w[i]);
		i++;
	}
}

int				ft_sha256_update(t_sha256_ctx *ctx, const void *data, unsigned long len)
{
	uint32_t	abcd[8];
	uint32_t	w[64];
	size_t		i;
	int			j;

	i = 0;
	j = -1;
	ft_memset(w, 0, sizeof(w));
	while (i < len)
	{
		j = -1;
		ft_sha256_update_break(w, data);
		ft_sha256_update_show(w);
		while (++j < 8)
			abcd[j] = ctx->state[j];
		j = -1;
		while (++j < 64)
			ft_sha256_update_process(abcd, w, j);
		j = -1;
		while (++j < 8)
			ctx->state[j] += abcd[j];
		i += 64;
	}
}