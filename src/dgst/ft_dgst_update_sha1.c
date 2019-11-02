#include "ft_dgst.h"

static int			ft_sha1_process_fk(uint32_t fk[2], int j, int b, int c, int d)
{
	if (j < 20)
	{
		fk[0] = (b & c) | ((~b) & d);
		fk[1] = 0x5A827999;
	}
	else if (j < 40)
	{
		fk[0] = b ^ c ^ d;
		fk[1] = 0x6ED9EBA1;
	}
    else if (j < 60)
	{
		fk[0] = (b & c) | (b & d) | (c & d);
		fk[1] = 0x8F1BBCDC;
	}
	else
	{
		fk[0] = b ^ c ^ d;
		fk[1] = 0xCA62C1D6;
	}
	return (EXIT_SUCCESS);
}

static void			ft_sha1_update_process(uint32_t *state, uint32_t *w)
{
	int 	i;
	uint32_t fk[2];
    uint32_t tmp;

	i = -1;
	if (FT_DGST_DEBUG)
		ft_putstr("\n == Operations == \n");
	while (++i < 80)
	{
		ft_sha1_process_fk(fk, i, state[1], state[2], state[3]);
		tmp = ft_rotate_left(state[0], 5) + fk[0] + state[4] + fk[1] + w[i];
		state[4] = state[3];
		state[3] = state[2];
		state[2] = ft_rotate_left(state[1], 30);
		state[1] = state[0];
		state[0] = tmp;
		if (FT_DGST_DEBUG)
			ft_dgst_update_process_debug(state, i, 5);
	}
}

static void          ft_sha1_update_break(uint32_t *w, const void *data)
{
    int i;
    uint32_t    rotator;
    uint32_t	*m;

    i = -1;
    rotator = 0;
    m = (uint32_t *)data;
    while (++i < 16)
        w[i] = swap_uint32(m[i]);
    while (i < 80)
    {
        rotator = (w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16]);
        w[i] = ft_rotate_left(rotator, 1);
        i++;
    }
	if (FT_DGST_DEBUG)
		ft_dgst_update_words_debug(w, 80);
}

int					ft_dgst_update_sha1(t_dgst_ctx *ctx)
{
	int			i;
	int			j;
    uint32_t    w[80];
	uint32_t	state[5];

	i = 0;
	j = -1;
	ft_memset(w, 0, sizeof(w));
	ft_memset(state, 0, sizeof(state));
	while (i < ctx->len_block)
	{
        ft_sha1_update_break(w, ctx->block);
		ft_memcpy(state, ctx->state, sizeof(state));
		ft_sha1_update_process(state, w);
		j = -1;
		while (++j < ctx->len_state)
			ctx->state[j] += state[j];
		if (FT_DGST_DEBUG)
			ft_dgst_state_debug(ctx->state, ctx->len_state);
		i += ctx->len_mbs;
	}
	return (EXIT_SUCCESS);
}
