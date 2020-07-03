/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_core.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:10:56 by dzonda            #+#    #+#             */
/*   Updated: 2020/03/05 20:37:46 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_CORE_H
# define FT_SSL_CORE_H

# include "../ssl_dgst/ft_ssl_dgst.h"
# include "../ssl_cipher/ft_ssl_cipher.h"
# include "../ssl_stdrd/ft_ssl_stdrd.h"

# define FTSSL_SHMAX_CMD        8192
# define FTSSL_SHMAX_BUFFER     8192


# define FTSSL_SHMODE_DISABLED  0
# define FTSSL_SHMODE_ENABLED   1


typedef int     	    t_ftssl_dist_check(char *dist_name);
typedef int			      t_ftssl_dist(int cmd_key, char *cmd_name, int argc, char *argv[]);


typedef enum				  s_ftssl_dist_enum
{
    FTSSL_DGST,
    FTSSL_CIPHER,
    FTSSL_STDRD, 
    FTSSL_CORE,
    FTSSL_DIST_MAX
}							        e_ftssl_dist;

typedef enum				e_core_command_enum
{
	FT_HELP,
	FT_CORE_CMD
}							t_core_cmd_e;

typedef struct  			s_ftssl_core_dist
{
    char    				*dist_name;
    t_core_cmd_e    		dist_key;
}               			t_ftssl_core_dist;

typedef struct				s_ftssl_core_usage_dist
{
	char									*dist_title;
	t_ftssl_dist_check		*dist_check;
}							t_ftssl_core_usage_dist;

typedef struct		s_ftssl_shell
{
	int							argc;
	char						*argv[FTSSL_SHMAX_CMD];
}									t_ftssl_sh;

typedef struct		    s_ftssl_dist_table
{
	int						      key_dist;
	t_ftssl_dist_check  *dist_check;
	int						      dist_dispatch_max;
	t_ftssl_dist		    *dist_ft;
}					            t_ftssl_dist_t;

typedef struct		    s_ftssl
{
	int									key_dist;
	int						      shmode;
	int						      err;
	t_ftssl_sh		      sh;
}					            t_ftssl;


// int					ft_ssl_dispatch(int argc, char *argv[]);

/*
 *	Shell
 */

int					ft_ssl_shell(t_ftssl_sh *sh);
int					ft_ssl_shell_reset(t_ftssl_sh *sh);
int					ft_ssl_shell_init(t_ftssl_sh *sh, int argc, const char *argv[]);

/*
 *	Core
 */

int					ft_ssl_core(int cmd_key, char *cmd_name, int argc, char *argv[]);
int     		ft_ssl_core_dispatch_dist(char *dist_name);
int					ft_ssl_usage(void);

#endif
