#include "../ft_ssl_dgst.h"

int				ft_ssl_dgst_output_r(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *md)
{
	(void)cmd_name;
	ft_putstr(md);
	if (cmd_arg != NULL)
		ft_putchar(' ');
	if (cmd_arg != NULL && cmd_arg_len == 0)
		ft_putstr(cmd_arg);
	else if (cmd_arg != NULL)
	{
		ft_putchar('\"');
		ft_putstr(cmd_arg);
		ft_putstr("\"");
	}
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}