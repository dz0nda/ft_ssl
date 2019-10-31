#include "ft_ssl_dgst.h"

int				ft_md5_padding(unsigned char *d, int n)
{
	size_t		i;
	uint64_t	ibits;

	i = ft_strlen((const char *)d);
	ibits = i * 8;
	d[i] = 0x80;
	while (++i < (n - FT_BYTE))
		d[i] = 0;
	while (i < n)
	{
		d[i++] = ibits % 256;
		ibits /= 256;
	}
	hexdump(d, n);
}

int			ft_ssl_dgst_final(t_dgst_ctx *ctx)
{
  	ft_putendl("im in final");

	// ft_md5_padding((unsigned char *)ctx->block, ctx->len_mbs);

	int n = ft_get_size_aligned(ctx->len_block + 8, 64);
	printf("n aligned = %d\n", n);
	int i = ctx->len_block;
	uint64_t ibits = ctx->len_input * 8;

	ctx->block[i] = 0x80;
	while (++i < (n - 8))
		ctx->block[i] = 0;
	while (i < n)
	{
		ctx->block[i++] = ibits % 256;
		ibits /= 256;
	}
	hexdump(ctx->block, n);
	return (EXIT_SUCCESS);
}


int				ft_ssl_dgst_result(t_dgst_ctx *ctx)
{
	int		i;
	int		j;
	char	s[12];
	uint8_t	*p;

	i = -1;
	// ft_md5_final_show(ctx);
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
