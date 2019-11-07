#include "ft_dgst.h"

int				ft_dgst_result32(t_dgst_ctx *ctx)
{
	int		i;
	int		j;
	char	s[512];
	uint8_t	*p;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < ctx->len_state)
	{
		j = -1;
        if (ctx->endian == FT_DGST_ENDIAN_BIG)
		    ctx->state.st_32[i] = swap_uint32(ctx->state.st_32[i]); 
		p = (uint8_t *)&ctx->state.st_32[i];
		while (++j < 4)
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(ctx->dgst, s);
			// ft_putstr(s);
		}
	}
	// ft_putstr("\n");
	return (EXIT_SUCCESS);
}

int				ft_dgst_result64(t_dgst_ctx *ctx)
{
	int		i;
	int		j;
	char	s[512];
	uint8_t	*p;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < ctx->len_state)
	{
		j = -1;
        if (ctx->endian == FT_DGST_ENDIAN_BIG)
		    ctx->state.st_64[i] = swap_uint64(ctx->state.st_64[i]); 
		p = (uint8_t *)&ctx->state.st_64[i];
		while (++j < 8)
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_strcat(ctx->dgst, s);
			// ft_putstr(s);
		}
	}
	// ft_putstr("\n");
	return (EXIT_SUCCESS);
}
