#include "../ft_ssl_dgst.h"

int				ft_ssl_dgst_output_q(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *md)
{
	(void)cmd_name;
	(void)cmd_arg;
	(void)cmd_arg_len;
	ft_putendl(md);
	return (EXIT_SUCCESS);
}