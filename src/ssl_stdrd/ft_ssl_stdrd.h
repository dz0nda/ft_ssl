/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_stdrd.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 22:13:18 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 10:10:14 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_STDRD_H
# define FT_SSL_STDRD_H

# include "../ft_ssl_global.h"

typedef enum		e_standard_command_enum
{
	FT_STDRD_CMD
}					t_stdrd_cmd_e;

int					ft_ssl_stdrd(int argc, char *argv[]);

#endif
