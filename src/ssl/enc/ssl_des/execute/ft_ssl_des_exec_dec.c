/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des_exec_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/08/12 18:15:16 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_des.h"

int ft_ssl_des_exec_dec(t_ssl_des_ctx ctx, t_ssl_des_opt opt) {
  char *cipher = NULL;
  char *input = NULL;
  int input_len = 0;
  int len = 0;

  input_len = ft_get_input(opt.input, &input);
  
  if (input_len == 0 || input == NULL) {
    ft_putstr_fd(opt.input, STDERR_FILENO);
    ft_putstr_fd(": No such file or diectory\n", STDERR_FILENO);
    return (FT_EXFAIL);
  }

  if (opt.encode == FT_DES_B64_CODE) {
    input[--input_len] = '\0';

    int dst_len = ft_b64_get_decoded_len((t_uchar *)input, input_len);

    char *dst = (char *)ft_memalloc(dst_len + 1);

    ft_b64_dec((t_uchar *)dst, dst_len, (t_uchar *)input, input_len);

    free(input);

    input = dst;
    input_len = dst_len;
  }

  if (ctx.mode_key == FT_DES_ECB)
    len = ft_des_ecb_decrypt(opt.key, input, input_len, &cipher);
  else if (ctx.mode_key == FT_DES_CBC) {
    len = ft_des_cbc_decrypt(opt.key, input, input_len, &cipher, opt.iv);
  }

  ft_ouptput(opt.output, cipher, len);

  return (FT_EXOK);
}