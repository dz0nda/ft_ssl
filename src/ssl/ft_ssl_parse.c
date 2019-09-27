#include "ft_ssl.h"

int   ft_ssl_usage(void)
{
    ft_putstr("usage: ft_ssl command [command opts] [command args");
    return (EXIT_FAILURE);
}

int   ft_ssl_error(const char *cmd)
{
  ft_putstr("ft_ssl: Error: '");
  ft_putstr(cmd);
  ft_putstr("' is an invalid command.");
  return (EXIT_FAILURE);
}

