#include "ft_dgst.h"

static void			ft_md5_final_show(t_md5_ctx *ctx)
{
	int i;

	i = -1;
	printf("Final show: \n");
	while (++i < 4)
		printf("hash[%d] = %x ", i, ctx->state[i]);
	printf("\n");
}

int				ft_md5_final(t_md5_ctx *ctx, unsigned char *md)
{
	int		i;
	int		j;
	char	s[12];
	uint8_t	*p;

	i = -1;
	ft_md5_final_show(ctx);
	while (++i < 4)
	{
		j = -1;
		// ctx->state[i] = swap_uint32(ctx->state[i]); 
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

static void			ft_sha1_final_show(t_sha1_ctx *ctx)
{
	int i;

	i = -1;
	printf("Final show: \n");
	while (++i < 5)
		printf("hash[%d] = %x ", i, ctx->state[i]);
	printf("\n");
}

int				ft_sha1_final(t_sha1_ctx *ctx, unsigned char *md)
{
	int		i;
	int		j;
	char	s[12];
	uint8_t	*p;

	i = -1;
	ft_sha1_final_show(ctx);
	while (++i < 5)
	{
		j = -1;
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


static void			ft_sha256_final_show(t_sha256_ctx *ctx)
{
	int i;

	i = -1;
	printf("Final show: \n");
	while (++i < 8)
		printf("hash[%d] = %x ", i, ctx->state[i]);
	printf("\n");
}

int				ft_sha256_final(t_sha256_ctx *ctx, unsigned char *md)
{
	int		i;
	int		j;
	char	s[12];
	uint8_t	*p;

	i = -1;
	ft_sha256_final_show(ctx);
	while (++i < 8)
	{
		j = -1;
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