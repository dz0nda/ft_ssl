#include "ft_ssl_dgst.h"

void     ft_ssl_dgst_usage(char *cmd)
{
    ft_putstr("usage: ");
    ft_putstr(cmd);
    ft_putstr(" [-pqr] [-s string] [files ...]");
    ft_putendl(": \n");
}
