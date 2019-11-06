#include "ft_dgst.h"

int				ft_dgst_result(t_dgst_ctx *ctx)
{
	int		i;
	int		j;
	char	s[512];
	uint8_t	*p;

int total = 0;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < 8)
	{
				printf("total : %d\n", total);
		j = -1;
        if (ctx->endian == FT_DGST_ENDIAN_BIG)
		    ctx->state64[i] = swap_uint64(ctx->state64[i]); 
		p = (uint8_t *)&ctx->state64[i];
		while (++j < 8)
		{
			printf("size buffer : %d\n", sizeof(ctx->dgst));
			printf("len buffer : %d\n", ft_strlen(ctx->dgst));
			printf("total : %d\n", p[j]);
			ft_putendl(ctx->dgst);
			total++;
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			printf("s[%s]\n", s);
			ft_strcat(ctx->dgst, s);
			// ft_putstr(s);
		}
	}
	// ft_putstr("\n");
	return (EXIT_SUCCESS);
}
