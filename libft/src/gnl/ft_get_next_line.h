/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:47:05 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/16 13:05:39 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include "../ft_libft_global.h"
# include "../str/ft_str.h"

# define GNL_BUFF_SIZE 3

// # include <string.h>
// # include <stdlib.h>
// # include <unistd.h>
// # include <sys/types.h>
// # include <sys/stat.h>
// # include <fcntl.h>

typedef struct		s_line
{
	int				fd;
	char			*str;
	size_t			index;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
