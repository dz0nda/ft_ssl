#include "ft_md5.h"

void				ft_md5_final(t_ft_md5_ctx *ctx, unsigned char *md)
{
	int				ijk[3];
	char			s[12];
	uint8_t			*p;
	unsigned char	*pmd = md;

	ijk[0] = -1;
	while (++ijk[0] < 4)
	{
		ijk[1] = -1;
		p = (uint8_t *)&ctx->state[ijk[0]];
		while (++ijk[1] < 4)
		{
			ijk[2] = -1;
			ft_bzero(s, sizeof(s));
			ft_itoa(p[ijk[1]], s, 16);
			ft_putstr(s);
			while (s[++ijk[2]] != '\0')
			{
				*pmd = s[ijk[2]];
				++pmd;
			}
		}
					ft_putstr("\n");

	}
	ft_putstr("\n");
}
