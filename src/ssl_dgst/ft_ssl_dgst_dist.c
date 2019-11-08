/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_dist.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 13:37:33 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 21:44:54 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"
 
int     ft_ssl_dgst_set_outp(t_ftssl_dgst_outp *outp, int outp_flag)
{
    t_ftssl_dgst_outp outp_table[FT_SSL_DGST_OUTP_FLAG] = {
        { FT_SSL_DGST_FLAG_Q,  ft_ssl_dgst_result_q },
        { FT_SSL_DGST_FLAG_R,  ft_ssl_dgst_result_r },
        { FT_SSL_DGST_OUTP_FLAG, ft_ssl_dgst_result }
    };
    int i;

    i = -1;
    if (outp->outp_flag != FT_SSL_DGST_FLAG_Q)
        while (++i < FT_SSL_DGST_OUTP_FLAG)
            if (outp_flag == outp_table[i].outp_flag)
            {
                outp->outp_flag = outp_table[i].outp_flag;
                outp->outp_dist = outp_table[i].outp_dist;
                break;
            }
    return(); 
}