#include "ft_ssl_dgst.h"

int			ft_ssl_dgst_update_md5(t_dgst_ctx *ctx)
{
    ft_putendl("im in update md5");

    uint32_t	abcd[4];
	uint32_t	*m;
	size_t		i;
	int			j;

	i = 0;
	j = -1;
	ft_memset(abcd, 0, sizeof(abcd));
    m = (uint32_t *)ctx->block;
    // ft_md5_update_show(m);
    j = -1;
    while (++j < ctx->len_state)
        abcd[j] = ctx->state[j];  // ft_memcpy(&abcd[j], &ctx->state[j], sizeof(uint32_t));
    j = -1;
    while (++j < ctx->len_mbs)
        ft_md5_update_process(abcd, m, j);
    j = -1;
    while (++j < ctx->len_state)
        ctx->state[j] += abcd[j];
	return (EXIT_SUCCESS);
}

int			ft_ssl_dgst_update_sha1(t_dgst_ctx *ctx)
{
    ft_putendl("im in update sha1");
	return (EXIT_SUCCESS);
}

int			ft_ssl_dgst_update_sha256(t_dgst_ctx *ctx)
{
    ft_putendl("im in update sha256");
	return (EXIT_SUCCESS);
}