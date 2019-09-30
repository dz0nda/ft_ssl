/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stradel.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/11 14:25:36 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 11:38:16 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_str.h"

void	ft_stradel(char ***array)
{
	int i;

	i = -1;
	if (*array)
	{
		while ((*array)[++i])
			ft_strdel(&(*array)[i]);
		free(*array);
		*array = NULL;
	}
}