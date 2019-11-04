/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sha1.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 23:11:52 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 23:16:56 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_dgst.h"

int			ft_sha1_init(t_dgst_ctx *ctx)
{
	ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xc3d2e1f0;
	return (EXIT_SUCCESS);
}

static void     ft_sha1_transform_word(uint32_t *w, const void *data)
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

static void     ft_sha1_transform_fk(uint32_t fk[2], int j, int b, int c, int d)
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
}

int				ft_sha1_transform(t_dgst_ctx *ctx)
{
	int      i;
    uint32_t state[5];
    uint32_t w[80];
	uint32_t fk[2];
    uint32_t tmp;

	i = -1;
    ft_memcpy(state, ctx->state, sizeof(state));
    ft_sha1_transform_word(w, ctx->block);
	while (++i < 80)
	{
		ft_sha1_transform_fk(fk, i, state[1], state[2], state[3]);
		tmp = ft_rotate_left(state[0], 5) + fk[0] + state[4] + fk[1] + w[i];
		state[4] = state[3];
		state[3] = state[2];
		state[2] = ft_rotate_left(state[1], 30);
		state[1] = state[0];
		state[0] = tmp;
	}
    i = -1;
    while (++i < ctx->len_state)
        ctx->state[i] += state[i];
	return (EXIT_SUCCESS);
}
