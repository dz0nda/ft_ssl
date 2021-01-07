/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:05:36 by dzonda            #+#    #+#             */
/*   Updated: 2020/12/22 23:46:20 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

static int			ft_isopt(t_ftssl_dgst_args args)
{
	if (args.iarg < args.argc)
		if (*args.argv[args.iarg] == '-' && args.argv[args.iarg][1] != '\0')
			return (1);
	return (0);
}

int 		ft_isemptyarg(int iarg, int argc, char *md)
{
	if (iarg == argc && ft_strlen(md) == 0)
		return (1);
	return (0);
}

int 		ft_isarg(int iarg, int argc)
{
	if (iarg < argc)
		return (1);
	return (0);
}

int		ft_ssl_dgst_get_input(char *file, char **input)
{
	int fd;
	char *tmp;
	char buf[4096];
	int  nbuf = 0;
	int length = 0;

	fd = 0;
	tmp = NULL;
	if (file != NULL && (fd = open(file, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	while ((nbuf = read(fd, buf, 4096)) > 0)
	{
		tmp = ft_strnew(length);
		ft_memcpy(tmp, *input, length);
		ft_strdel(&(*input));
		*input = ft_strnew(length + nbuf);
		ft_memcpy(*input, tmp, length);
		ft_memcpy(*input + length, buf, nbuf);
		length += nbuf;
		ft_strdel(&tmp);
	}

	return (length);
}

int			ft_ssl_dgst_exec_file(t_ftssl_dgst *ftssl_dgst)
{
	char *s = NULL;
	char *tmp = NULL;
	int length = 0;

	s = NULL;
	length = ft_ssl_dgst_get_input(ftssl_dgst->cmd_arg, &s);
	if (ftssl_dgst->cmd_arg != NULL && ftssl_dgst->outp_key != FTSSL_DGST_OUTP_QUIET)
		ftssl_dgst->outp_key = FTSSL_DGST_OUTP_FILE;
	tmp = ftssl_dgst->cmd_arg;
 	ftssl_dgst->cmd_arg = s;
	ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
	ft_hash(ftssl_dgst->cmd_key, (uint8_t *)ftssl_dgst->cmd_arg, length, ftssl_dgst->md);
 	ftssl_dgst->cmd_arg = tmp;
	ft_ssl_dgst_output(ftssl_dgst);
	ft_strdel(&s);
	return (EXIT_SUCCESS);
}

int			ft_ssl_dgst_exec(t_ftssl_dgst *ftssl_dgst)
{
	ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
	ft_hash(ftssl_dgst->cmd_key, (uint8_t *)ftssl_dgst->cmd_arg, ft_strlen(ftssl_dgst->cmd_arg), ftssl_dgst->md);
	ft_ssl_dgst_output(ftssl_dgst);

	return (EXIT_SUCCESS);
}

int     ft_ssl_dgst(int argc, char *argv[])
{
	t_ftssl_dgst			ftssl_dgst;

	ft_memset(&ftssl_dgst, 0, sizeof(ftssl_dgst));
	if (ft_ssl_dgst_dist(argc, argv, &ftssl_dgst) == FT_SSL_DGST_NOT_FOUND)
		return (FT_SSL_DGST_NOT_FOUND);
	while (ft_isopt(ftssl_dgst.args))
	{
		if (ft_ssl_dgst_option(&ftssl_dgst) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ftssl_dgst.args.iarg++;
	}
	if (ft_isemptyarg(ftssl_dgst.args.iarg, ftssl_dgst.args.argc, ftssl_dgst.md))
		return (ft_ssl_dgst_exec_file(&ftssl_dgst));
	while (ft_isarg(ftssl_dgst.args.iarg, ftssl_dgst.args.argc))
	{
		ftssl_dgst.cmd_arg = ftssl_dgst.args.argv[ftssl_dgst.args.iarg];
		if (ft_isreg(ftssl_dgst.cmd_arg))
			ft_ssl_dgst_exec_file(&ftssl_dgst);
		else if (ft_isdir(ftssl_dgst.cmd_arg))
			ft_ssl_dgst_error(FTSSL_DGST_ERR_DIR, &ftssl_dgst);
		else
			ft_ssl_dgst_error(FTSSL_DGST_ERR_FILE, &ftssl_dgst);
		ftssl_dgst.args.iarg++;
	}
	return (EXIT_SUCCESS);
}
