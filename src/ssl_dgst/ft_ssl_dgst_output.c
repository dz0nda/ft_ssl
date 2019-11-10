#include "ft_ssl_dgst.h"

int				ft_ssl_dgst_output(t_ftssl_dgst *ftssl_dgst)
{
	int i;

	i = -1;
	while (ftssl_dgst->ctx.cmd_name[++i] != '\0')
		ft_putchar(ft_toupper(ftssl_dgst->ctx.cmd_name[i]));
	ft_putstr(" (");
	if (ftssl_dgst->ctx.cmd_arg == NULL)
		ft_putstr("*stdin");
	else if (ftssl_dgst->ctx.cmd_arg_len == 0)
	{
		ft_putchar('*');
		ft_putstr(ftssl_dgst->ctx.cmd_arg);
	}
	else
	{
		ft_putchar('\"');
		ft_putstr(ftssl_dgst->ctx.cmd_arg);
		ft_putchar('\"');
	}
	ft_putstr(") = ");
	ft_putendl(ftssl_dgst->ctx.cmd_dgst);
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output_q(t_ftssl_dgst *ftssl_dgst)
{
	ft_putendl(ftssl_dgst->ctx.cmd_dgst);
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output_r(t_ftssl_dgst *ftssl_dgst)
{
	ft_putstr(ftssl_dgst->ctx.cmd_dgst);
	ft_putchar(' ');
	if (ftssl_dgst->ctx.cmd_arg == NULL)
		ft_putstr("*stdin");
	else if (ftssl_dgst->ctx.cmd_arg_len == 0)
	{
		ft_putchar('*');
		ft_putstr(ftssl_dgst->ctx.cmd_arg);
	}
	else
	{
		ft_putchar('\"');
		ft_putstr(ftssl_dgst->ctx.cmd_arg);
		ft_putchar('\"');
	}
	return (EXIT_SUCCESS);
}
