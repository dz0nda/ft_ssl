#include "ft_dgst.h"

static int			ft_sha1_process_f(int j, int B, int C, int D)
{
	if (j < 20)
		return ((B & C) | ((~B) & D));
	else if (j < 40)
        return (B ^ C ^ D);
    else if (j < 60)
        return ((B & C) | (B & D) | (C & D));
    return (B ^ C ^ D);
}

static int			ft_sha1_process_k(int j)
{
	if (j < 20)
		return (0x5A827999);
	else if (j < 40)
        return (0x6ED9EBA1);
    else if (j < 60)
        return (0x8F1BBCDC);
    return (0xCA62C1D6);
}

static void			ft_sha1_update_process(uint32_t abcd[4], uint32_t *w, int j)
{
	uint32_t f;
	uint32_t k;
    uint32_t tmp;

	f = ft_sha1_process_f(j, abcd[1], abcd[2], abcd[3]);
    k = ft_sha1_process_k(j);
	tmp = ft_rotate_left(abcd[0], 5) + f + abcd[4] + k + w[j];
    abcd[4] = abcd[3];
	abcd[3] = abcd[2];
	abcd[2] = ft_rotate_left(abcd[1], 30);
	abcd[1] = abcd[0];
    abcd[0] = tmp;

	printf("[j = %d] A=%u, B=%u, C=%u, D=%u, E=%u\n", j, abcd[0], abcd[1], abcd[2], abcd[3], abcd[4]);
	// printf("rotateLeft(%d + %x + %x + %x, %d), %x, %x\n", abcd[0], fg[0], k, m[j], s, abcd[1], abcd[2]);
}

static void			ft_sha1_update_show(uint32_t	*m)
{
	int i;

	i = -1;
	printf("Update show: \n");
    // m[0] = swap_uint32(m[0]);
	while (++i < 80)
		printf("Block[%d] = %u \n", i, m[i]);
	printf("\n");
}

static void          ft_sha1_update_break(uint32_t *w, const void *data)
{
    int i;
    uint32_t    rotator;
    uint32_t	*m;

    i = -1;
    rotator = 0;
    m = (uint32_t *)data;
    // m[0] = swap_uint32(m[0]);
    while (++i < 16)
        w[i] = swap_uint32(m[i]);
    while (i < 80)
    {
        rotator = (w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16]);
        w[i] = ft_rotate_left(rotator, 1);
        // w[i] = swap_uint32(w[i]);
        i++;
    }
    // i = -1;
    // while (++i < 80)
    //     w[i] = swap_uint32(w[i]);
}

int					ft_sha1_update(t_sha1_ctx *ctx, const void *data, unsigned long len)
{
	uint32_t	abcd[5];
	uint32_t	*m;
    uint32_t    w[80];
	size_t		i;
	int			j;

	i = 0;
	j = -1;
	ft_putnbr(len);
	ft_memset(abcd, 0, sizeof(abcd));
	ft_memset(w, 0, sizeof(w));
	while (i < len)
	{
        ft_sha1_update_break(w, data);
		ft_sha1_update_show(w);
		j = -1;
		while (++j < 5)
		  abcd[j] = ctx->state[j];  // ft_memcpy(&abcd[j], &ctx->state[j], sizeof(uint32_t));
		j = -1;
		while (++j < 80)
			ft_sha1_update_process(abcd, w, j);
		j = -1;
		while (++j < 5)
			ctx->state[j] += abcd[j];
		i += 64;
	}
	return (EXIT_SUCCESS);
}
