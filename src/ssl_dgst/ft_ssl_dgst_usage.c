#include "ft_ssl_dgst.h"

void     ft_ssl_dgst_usage(char *cmd)
{
    ft_putstr_fd("usage: ", STDERR_FILENO);
    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putstr_fd(" [-pqr] [-s string] [files ...] \n", STDERR_FILENO);
}
