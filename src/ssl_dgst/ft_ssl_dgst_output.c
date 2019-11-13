#include "ft_ssl_dgst.h"

int				ft_ssl_dgst_output(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *md)
{
	int i;

	i = -1;
	if (cmd_arg != NULL)
	{
		while (cmd_name[++i] != '\0')
			ft_putchar(ft_toupper(cmd_name[i]));
		ft_putstr(" (");
	}
	if (cmd_arg_len == 0)
		ft_putstr(cmd_arg);
	else
	{
		ft_putchar('\"');
		if (cmd_arg[ft_strlen(cmd_arg) - 1] == '\n')
			cmd_arg[ft_strlen(cmd_arg) - 1] = '\0';
		ft_putstr(cmd_arg);
		ft_putchar('\"');
	}
	if (cmd_arg != NULL)
		ft_putstr(") = ");
	ft_putendl(md);
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output_q(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *md)
{
	ft_putendl(md);
	return (EXIT_SUCCESS);
}

int				ft_ssl_dgst_output_r(char *cmd_name, char *cmd_arg, int cmd_arg_len, char *md)
{
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
