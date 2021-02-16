/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_dgst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:05:36 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/04 16:58:09 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_get_input(char *file, char **input)
{
	int		fd;
	char	*tmp;
	char	buf[4096];
	int		nbuf;
	int		length;

	fd = 0;
	tmp = NULL;
	ft_bzero(buf, 4096);
	nbuf = 0;
	length = 0;
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

int		ft_ssl_dgst_exec_file(t_ftssl_dgst *ftssl_dgst, char *cmd_arg)
{
	char	*s;
	char	*tmp;
	int		length;

	s = NULL;
	tmp = NULL;
	length = 0;
	ftssl_dgst->cmd_arg = cmd_arg;
	length = ft_ssl_dgst_get_input(ftssl_dgst->cmd_arg, &s);
	if (ftssl_dgst->cmd_arg != NULL
	&& ftssl_dgst->outp_key != FTSSL_DGST_OUTP_QUIET)
		ftssl_dgst->outp_key = FTSSL_DGST_OUTP_FILE;
	tmp = ftssl_dgst->cmd_arg;
	ftssl_dgst->cmd_arg = s;
	ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
	ft_ssl_dgst_dist_execute((uint8_t *)s, length, ftssl_dgst->md, ftssl_dgst);
	ftssl_dgst->cmd_arg = tmp;
	ft_ssl_dgst_output(ftssl_dgst);
	ft_strdel(&s);
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst(int argc, char *argv[])
{
	t_ftssl_dgst			ftssl_dgst;

	ft_memset(&ftssl_dgst, 0, sizeof(ftssl_dgst));
	if (ft_ssl_dgst_dist(argc, argv, &ftssl_dgst) == FT_SSL_DGST_NOT_FOUND)
		return (FT_SSL_DGST_NOT_FOUND);
	argc -= 1;
	argv += 1;
	while (ft_ssl_dgst_option(&ftssl_dgst, argc, argv) == EXIT_SUCCESS)
		ftssl_dgst.argi++;
	if (ftssl_dgst.err == 1)
		return (ft_ssl_dgst_error(FTSSL_DGST_ERR_OPT, &ftssl_dgst));
	if (ftssl_dgst.argi == argc && ft_strlen(ftssl_dgst.md) == 0)
		return (ft_ssl_dgst_exec_file(&ftssl_dgst, NULL));
	while (ftssl_dgst.argi < argc)
	{
		if (ft_isreg(argv[ftssl_dgst.argi]))
			ft_ssl_dgst_exec_file(&ftssl_dgst, argv[ftssl_dgst.argi]);
		else if (ft_isdir(argv[ftssl_dgst.argi]))
			ft_ssl_dgst_error(FTSSL_DGST_ERR_DIR, &ftssl_dgst);
		else
			ft_ssl_dgst_error(FTSSL_DGST_ERR_FILE, &ftssl_dgst);
		ftssl_dgst.argi++;
	}
	return (EXIT_SUCCESS);
}
