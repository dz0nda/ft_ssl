#include "ft_dgst.h"

int				ft_dgst_result(t_dgst_ctx *ctx)
{
	int		i;
	int		j;
	char	s[512];
	uint8_t	*p;

	i = -1;
	while (++i < 8)
	{
		j = -1;
        if (ctx->endian == FT_DGST_ENDIAN_BIG)
		    ctx->state64[i] = swap_uint64(ctx->state64[i]); 
		p = (uint8_t *)&ctx->state64[i];
		while (++j < 8)
		{
			ft_bzero(s, sizeof(s));
			ft_itoa64(p[j], s, 16);
			// ft_strcat(ctx->dgst, s);
			ft_putstr(s);
		}
	}
	// ft_putstr("\n");
	return (EXIT_SUCCESS);
}
