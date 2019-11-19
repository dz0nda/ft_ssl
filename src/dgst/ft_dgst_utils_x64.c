
#include "ft_dgst.h"



char        *ft_dgst_result_x64(t_dgst_ctx *ctx, char *cmd_dgst)
{
	unsigned int		i;
	int		j;
	char	s[6];
	uint8_t	*p;

	i = -1;
	ft_bzero(ctx->dgst, sizeof(ctx->dgst));
	while (++i < ctx->sts)
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
