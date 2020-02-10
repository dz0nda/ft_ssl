/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_err.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 21:22:52 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 23:08:02 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_ssl_dgst.h"

int   ft_ssl_dgst_err_dir(char *cmd, char *arg, int err)
{
    (void)err;

  ft_putstr_fd(cmd, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd(arg, STDERR_FILENO);
  ft_putstr_fd(": Is a directory", STDERR_FILENO);
  return (EXIT_FAILURE);
}

int   ft_ssl_dgst_err_file(char *cmd, char *arg, int err)
{
    (void)err;

  ft_putstr_fd(cmd, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd(arg, STDERR_FILENO);
  ft_putstr_fd("No such file or directory", STDERR_FILENO);
  return (EXIT_FAILURE);
}

int   ft_ssl_dgst_err_opt_arg(char *cmd, char *arg, int err)
{
  (void)err;
  ft_putstr_fd(cmd, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd("option requires an argument -- ", STDERR_FILENO);
  ft_putstr_fd(arg, STDERR_FILENO);
  ft_ssl_dgst_err_usage(cmd);
  return (EXIT_FAILURE);
}

int   ft_ssl_dgst_err_opt(char *cmd, char *arg, int err)
{
    (void)err;

    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putstr_fd("illegal option -- ", STDERR_FILENO);
    ft_putstr_fd(arg, STDERR_FILENO);
    ft_ssl_dgst_err_usage(cmd);
    return (EXIT_FAILURE);
}

int   ft_ssl_dgst_err_unexpected(char *cmd, char *arg, int err)
{
    (void)err;

  ft_putstr_fd(cmd, STDERR_FILENO);
  ft_putstr_fd(": ", STDERR_FILENO);
  ft_putstr_fd(arg, STDERR_FILENO);
  ft_putstr_fd("Unexpected error.", STDERR_FILENO);
  return (EXIT_FAILURE);
}

// int             ft_ssl_dgst_error(char *cmd, char *arg, int err)
// {
//     const char *errors[FTSSL_DGST_ERR] = {
//         "Unexpected error.",
//         "illegal option -- ",
//         "option requires an argument -- ",
//         "No such file or directory"
//     };

//     ft_putstr_fd(cmd, STDERR_FILENO);
//     ft_putstr_fd(": ", STDERR_FILENO);
//     if (err == FTSSL_DGST_ERR_OPT || err == FTSSL_DGST_ERR_ARG)
//         ft_putstr_fd(errors[err], STDERR_FILENO);
//     ft_putstr_fd(arg, STDERR_FILENO);
//     if (err == FTSSL_DGST_ERR_OPT || err == FTSSL_DGST_ERR_ARG)
//         ft_ssl_dgst_usage(cmd);
//     else
//         ft_putstr_fd(errors[err], STDERR_FILENO);
//     return (EXIT_FAILURE);
// }