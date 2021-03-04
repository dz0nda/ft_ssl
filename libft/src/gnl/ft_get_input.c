/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:43:12 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/18 16:36:09 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

int		ft_get_input(char *file, char **input)
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
