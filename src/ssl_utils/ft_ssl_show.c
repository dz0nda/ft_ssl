# include "ft_ssl_utils.h"

void			ft_init_show(t_ssl_ctx *ctx)
{
	int i;

	i = -1;
	printf("Init show: \n");
	while (++i < 4)
		printf("hash[%d] = %u ", i, ctx->state[i]);
	printf("\n");
}
