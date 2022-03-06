/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 03:43:56 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/06 22:30:50 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOOLS_H
#define FT_TOOLS_H

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <readpassphrase.h>

// # include <bsd/readpassphrase.h>

#include "../../libft/libft.h"

// GET INPUT

# define FT_IN_404       404
# define FT_IN_NOT_FOUND "Not found"

typedef struct s_input {
    int len;
    char* data;
    char* err;
} t_in;


int ft_get_input(char* file, char** input);
int ft_get_input_404(char* err);

int ft_write_output(char* file, char* output, int breaker);
int ft_isdir(char* arg);
int ft_isopt(char* opt);
int ft_isreg(char* arg);
int ft_ishexstr(const char* str);
int ft_get_random(char* dst, int size);
int ft_get_pass(char* dst, int size);

#endif
