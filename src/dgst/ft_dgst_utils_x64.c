
#include "ft_dgst.h"

uint64_t    ft_rotate_left_x64(uint64_t word, uint64_t bits)
{
	return ((word << bits) | (word >> (64 - bits)));
}

uint64_t    ft_rotate_right_x64(uint64_t word, uint64_t bits)
{
	return ((word >> bits) | (word << (64 - bits)));
}

uint64_t	ft_shift_right_x64(uint64_t word, uint64_t bits)
{
	return (word >> bits);
}

uint64_t    ft_swap_uint_x64(uint64_t val)
{
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
    return (val << 32) | (val >> 32);
}

char        *ft_dgst_result_x64(t_dgst_ctx *ctx, char *cmd_dgst)
{
	int		i;
	int		j;
	char	s[6];
	uint8_t	*p;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < ctx->len_state)
	{
		j = -1;
        if (ctx->endian == FT_DGST_ENDIAN_BIG)
		    ctx->state.x_64[i] = ft_swap_uint_x64(ctx->state.x_64[i]); 
		p = (uint8_t *)&ctx->state.x_64[i];
		while (++j < 8)
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(cmd_dgst, s);
		}
	}
	return (cmd_dgst);
}
