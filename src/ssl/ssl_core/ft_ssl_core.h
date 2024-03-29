/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_core.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:10:56 by dzonda            #+#    #+#             */
/*   Updated: 2021/02/22 11:53:02 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_CORE_H
# define FT_SSL_CORE_H

# include "../ssl_dgst/ft_ssl_dgst.h"
# include "../ssl_cipher/ft_ssl_cipher.h"

# define FTSSL_SHMAX_CMD        8192
# define FTSSL_SHMAX_BUFFER     8192

# define FTSSL_SHMODE_DISABLED  0
# define FTSSL_SHMODE_ENABLED   1

# define FT_SSL_DIST_NOT_FOUND  -42

typedef int			t_ftssl_dist(int argc, char *argv[]);

typedef enum		e_ftssl_dist_enum
{
	FTSSL_DGST,
	FTSSL_CIPHER,
	FTSSL_CORE,
	FTSSL_DIST
}					t_ftssl_dist_enum;

typedef enum		e_core_dist_enum
{
	FT_SSL_HELP,
	FT_SSL_CORE_DIST
}					t_core_dist_e;

typedef struct		s_ftssl_shell
{
	int				argc;
	char			*argv[FTSSL_SHMAX_CMD];
}					t_ftssl_sh;

typedef struct		s_ftssl_core_usage_dist
{
	char			*dist_title;
	t_ftssl_dist	*dist_ft;
}					t_ftssl_core_usage_dist;

typedef struct		s_ftssl_core_dist
{
	char			*dist_name;
	int				dist_key;
}					t_ftssl_core_dist;

int					ft_ssl_core(int argc, char *argv[]);
int					ft_ssl_core_dist(int argc, char *argv[]);
int					ft_ssl_usage(void);

int					ft_ssl_shell(t_ftssl_sh *sh);
int					ft_ssl_shell_reset(t_ftssl_sh *sh);
int					ft_ssl_shell_init(t_ftssl_sh *sh, int argc,
	const char *argv[]);

#endif
