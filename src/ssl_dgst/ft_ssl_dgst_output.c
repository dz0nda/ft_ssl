#include "ft_ssl_dgst.h"

int				ft_ssl_dgst_output(t_dgst *dgst, char *data, int len)
{
	int i;

	i = -1;
	while (dgst->cmd_name[++i] != '\0')
		ft_putchar(ft_toupper(dgst->cmd_name[i]));
	// ft_putstr(dgst->cmd_name);
	ft_putstr(" (");
	if (data == NULL)
		ft_putstr("*stdin");
	else if (len == 0)
		ft_putstr(data);
	else
	{
		ft_putchar('\"');
		ft_putstr(data);
		ft_putchar('\"');
	}
	ft_putstr(") = ");
	ft_putendl(dgst->dist.ctx.dgst);
}

int				ft_ssl_dgst_output_q(t_dgst *dgst, char *data, int len)
{
	ft_putendl(dgst->dist.ctx.dgst);
}

int				ft_ssl_dgst_output_r(t_dgst *dgst, char *data, int len)
{
	ft_putstr(dgst->dist.ctx.dgst);
	ft_putchar(' ');
	if (data == NULL)
		ft_putstr("*stdin");
	else if (len == 0)
	{
		ft_putchar('*');
		ft_putstr(data);
	}
	else
	{
		ft_putchar('\"');
		ft_putstr(data);
		ft_putchar('\"');
	}
}

