/* ************************************************************************** */

#include "ft_dgst.h"

static int			ft_md5_process_f(int j, int B, int C, int D)
{
	if (j < 16)
		return ((B & C) | ((~B) & D));
	else if (j < 32)
		return ((D & B) | ((~D) & C));
	else if (j < 48)
		return (B ^ C ^ D);
	return (C ^ (B | (~D)));
}

static int			ft_md5_process_g(int j)
{
	if (j < 16)
		return (j);
	else if (j < 32)
		return ((5 * j + 1) % 16);
	else if (j < 48)
		return ((3 * j + 5) % 16);
	return ((7 * j) % 16);
}

static int			ft_md5_process_k(int j)
{
	const uint32_t k[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 
		0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340, 0x265e5a51,
		0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6, 0xc33707d6, 
		0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 0xfffa3942,
		0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 
		0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
		0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82,
		0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };
	
	if (j < 0 || j > 63)
		return (0);
	return (k[j]);
}

static int			ft_md5_process_s(int j)
{
	const uint32_t s[64] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17,
		22, 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20, 4, 11, 16,
		23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23, 6, 10, 15, 21,  6, 10, 15,
		21,  6, 10, 15, 21,  6, 10, 15, 21 };
	
	if (j < 0 || j > 63)
		return (0);
	return (s[j]);
}

static void			ft_md5_update_process(uint32_t abcd[4], uint32_t *m, int j)
{
	uint32_t k;
	uint32_t s;
	uint32_t fg[2];

	k = ft_md5_process_k(j);
	s = ft_md5_process_s(j);
	fg[0] = ft_md5_process_f(j, abcd[1], abcd[2], abcd[3]);
	fg[1] = ft_md5_process_g(j);
	fg[0] = fg[0] + abcd[0] + k + m[fg[1]];
	abcd[0] = abcd[3];
	abcd[3] = abcd[2];
	abcd[2] = abcd[1];
	abcd[1] = abcd[1] + ft_rotate_left(fg[0], s);
	
	printf("[j = %d] A=%u, B=%u, C=%u, D=%u\n", j, abcd[0], abcd[1], abcd[2], abcd[3]);
	// printf("rotateLeft(%d + %x + %x + %x, %d), %x, %x\n", abcd[0], fg[0], k, m[j], s, abcd[1], abcd[2]);
}

static void			ft_md5_update_show(uint32_t	*m)
{
	int i;

	i = -1;
	printf("Update show: \n");
	while (++i < 15)
		printf("Block[%d] = %u \n", i, m[i]);
	printf("\n");
}

int                 ft_md5_update_break(uint32_t *w, const void *data)
{
	int i;
    uint32_t *m;

	i = -1;
    m = (uint32_t *)data;
    while (++i < 16)
        w[i] = m[i];
    return (EXIT_SUCCESS);
}

int					ft_md5_update(t_md5_ctx *ctx, const void *data, unsigned long len)
{
	uint32_t	abcd[4];
	uint32_t	*m;
	size_t		i;
	int			j;

	i = 0;
	j = -1;
	ft_putnbr(len);
	ft_memset(abcd, 0, sizeof(abcd));
    m = (uint32_t *)data;
    ft_md5_update_show(m);
    j = -1;
    while (++j < 4)
        abcd[j] = ctx->state[j];  // ft_memcpy(&abcd[j], &ctx->state[j], sizeof(uint32_t));
    j = -1;
    while (++j < 64)
        ft_md5_update_process(abcd, m, j);
    j = -1;
    while (++j < 4)
        ctx->state[j] += abcd[j];
    i += 64;
    return (EXIT_SUCCESS);
}

