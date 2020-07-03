/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_stdrd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:13:18 by dzonda            #+#    #+#             */
/*   Updated: 2020/07/03 17:15:39 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_SSL_STDRD_H
# define FT_SSL_STDRD_H

# include "../../ft_ssl_global.h"

typedef enum		e_standard_command_enum
{
	FT_DGST,
	FT_STDRD_CMD
}					t_stdrd_cmd_e;

typedef struct  s_ftssl_standard_dist
{
    char    *dist_name;
    int     dist_key;
}               t_ftssl_stdrd_dist;


typedef struct  s_ftssl_standard
{
    int                 cmd_key;
    char                *cmd_name;
}               t_ftssl_stdrd;

int					ft_ssl_stdrd(int cmd_key, char *cmd_name, int argc, char *argv[]);
int     			ft_ssl_stdrd_dispatch_dist(char *dist_name);

#endif
