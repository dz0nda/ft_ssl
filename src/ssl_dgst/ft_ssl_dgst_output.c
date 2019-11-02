#include "ft_ssl_dgst.h"

int				ft_ssl_dgst_result(t_dgst_ctx *ctx)
{
	int		i;
	int		j;
	char	s[12];
	uint8_t	*p;

	i = -1;
	// ft_md5_final_show(ctx);
	while (++i < ctx->len_state)
	{
		j = -1;
        if (ctx->endian == FT_DGST_ENDIAN_BIG)
		    ctx->state[i] = swap_uint32(ctx->state[i]); 
		p = (uint8_t *)&ctx->state[i];
		while (++j < 4)
		{
			ft_bzero(s, sizeof(s));
			ft_itoa(p[j], s, 16);
			ft_putstr(s);
		}
	}
	ft_putstr("\n");
	return (EXIT_SUCCESS);
}

// int				ft_ssl_dgst_output(t_dgst_ctx *ctx)
// {
//     printf("cmd_name %s", ctx->cm)
// }

