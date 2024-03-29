/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:12:33 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/03 20:58:02 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_core.h"

static void		ft_ssl_shell_parse(t_ftssl_sh *sh, char *buffer)
{
	int		i;
	char	tmp[FTSSL_SHMAX_BUFFER];
	char	*tmp_ptr;

	i = 0;
	while (*buffer && i < FTSSL_SHMAX_CMD)
	{
		ft_bzero(tmp, sizeof(tmp));
		tmp_ptr = tmp;
		while (*buffer && ft_isspace(*buffer))
			buffer++;
		if (*buffer == '\0')
			break ;
		if (*buffer == '"')
		{
			while (*buffer++ && *buffer != '"')
				*tmp_ptr++ = *buffer;
			(*buffer != '\0') ? buffer++ : 0;
		}
		else
			while (*buffer && !ft_isspace(*buffer))
				*tmp_ptr++ = *buffer++;
		sh->argv[i++] = ft_strdup(tmp);
	}
	sh->argc = i;
}

int				ft_ssl_shell_reset(t_ftssl_sh *sh)
{
	int i;

	i = -1;
	while (++i < sh->argc)
		ft_strdel(&sh->argv[i]);
	sh->argc = 0;
	return (EXIT_SUCCESS);
}

int				ft_ssl_shell_init(t_ftssl_sh *sh, int argc, const char *argv[])
{
	int i;

	i = -1;
	sh->argc = argc;
	while (++i < sh->argc && i < FTSSL_SHMAX_CMD)
		sh->argv[i] = ft_strdup(argv[i]);
	return (EXIT_SUCCESS);
}

int				ft_ssl_shell(t_ftssl_sh *sh)
{
	char buffer[FTSSL_SHMAX_BUFFER];

	ft_bzero(buffer, sizeof(buffer));
	ft_ssl_shell_reset(sh);
	ft_putstr("ftSSL> ");
	if (read(0, buffer, FTSSL_SHMAX_BUFFER - 1) < 1)
		return (EXIT_FAILURE);
	ft_ssl_shell_parse(sh, buffer);
	return (EXIT_SUCCESS);
}
