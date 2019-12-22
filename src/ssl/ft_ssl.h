/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 20:10:56 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 14:10:05 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../ssl_dgst/ft_ssl_dgst.h"
# include "../ssl_cipher/ft_ssl_cipher.h"
# include "../ssl_stdrd/ft_ssl_stdrd.h"

# define FTSSL_SHMODE_DISABLED  0
# define FTSSL_SHMODE_ENABLED   1

# define FTSSL_SHMAX_CMD        8192
# define FTSSL_SHMAX_BUFFER     8192

typedef int			t_ftssl_dist(int cmd_key, char *cmd_name, int argc, char *argv[]);
typedef int     	t_ftssl_dist_check(char *dist_name);

typedef enum				e_ftssl_dist_enum
{
	FTSSL_DGST,
	FTSSL_CIPHER,
	FTSSL_STDRD, 
	FTSSL_CORE,
	FTSSL_DIST_E
}							t_ftssl_dist_e;

/*
 *	Core dispatcher
 */

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
	char					*dist_title;
	t_ftssl_dist_check		*dist_check;
}							t_ftssl_core_usage_dist;

/*
 *	ssl shell - need to be in core ?
 */
typedef struct		s_ftssl_shell
{
	int				argc;
	char			*argv[FTSSL_SHMAX_CMD];
}					t_ftssl_sh;

/*
 *	ssl dispatcher
 */

typedef struct		s_ftssl_dist_table
{
	int						key_dist;
	t_ftssl_dist_check		*dist_check;
	int						dist_dispatch_max;
	t_ftssl_dist			*dist_ft;
}					t_ftssl_dist_t;

typedef struct		s_ftssl
{
	int				shmode;
	t_ftssl_sh		sh;
}					t_ftssl;

int					ft_ssl_init(t_ftssl *fssl, int argc, const char *argv[]);

int					ft_ssl_dispatch(int argc, char *argv[]);

/*
 *	Shell
 */

int					ft_ssl_shell(t_ftssl_sh *sh);
void				ft_ssl_shell_reset(t_ftssl_sh *sh);

/*
 *	Core
 */

int					ft_ssl_core(int cmd_key, char *cmd_name, int argc, char *argv[]);
int     			ft_ssl_core_dispatch_dist(char *dist_name);
int					ft_ssl_usage(void);
// int					ft_ssl_error(int argc, char *argv[]);

#endif
