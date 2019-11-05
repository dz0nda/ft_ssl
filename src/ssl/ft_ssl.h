/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 20:10:56 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 04:42:10 by dzonda      ###    #+. /#+    ###.fr     */
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

typedef int         t_ftssl_dist(int, char *[]);

typedef enum        s_ftssl_dist_enum
{
    FTSSL_HELP,
    FTSSL_DGST,
    FTSSL_CIPHER,
    FTSSL_STDRD,
    FTSSL_DIST_E
}                   t_ftssl_dist_e;

typedef struct      s_ftssl_dist_table
{
    int             key_dist;
    char            *dist_name[FTSSL_SHMAX_CMD];
    t_ftssl_dist    *dist_ft;    
}                   t_ftssl_dist_t;

typedef struct      s_ftssl_shell
{
    int             argc;
    char            *argv[FTSSL_SHMAX_CMD];
}                   t_ftssl_sh;

typedef struct      s_ftssl
{
    int             shmode;
    t_ftssl_sh      sh;
}                   t_ftssl;

int                 ft_ssl_init(t_ftssl *fssl, int argc, const char *argv[]);

int		            ft_ssl_dist_exec(int argc, char *argv[]);

int		            ft_ssl_usage(int argc, char *argv[]);
int                 ft_ssl_error(int argc, char *argv[]);

int                 ft_ssl_shell(t_ftssl_sh *sh);

#endif
