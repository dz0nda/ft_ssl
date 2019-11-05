#include "ft_ssl_dgst.h"

int				ft_ssl_dgst_output(t_dgst *dgst)
{
	// ft_putstr(dgst->cmd_name);
	// ft_putstr("() = ");
	// ft_putendl(dgst->ctx.dgst);
}

int				ft_ssl_dgst_output_q(t_dgst *dgst)
{
	ft_putendl(dgst->ctx.dgst);
}

int				ft_ssl_dgst_output_r(t_dgst *dgst)
{
	ft_putstr(dgst->ctx.dgst);
	ft_putendl(" cmd");
}

