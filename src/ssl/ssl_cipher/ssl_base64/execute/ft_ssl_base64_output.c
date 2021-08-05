/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_base64_output.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/06/14 11:06:05 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_base64.h"
#include <limits.h>
#include <arpa/inet.h>
#include <errno.h>

int		ft_ssl_base64_output(t_ssl_base64 *ctx, int argc, char *argv[])
{
	static t_ssl_base64_d		ftssl_base64[2] = {
		{ FT_SSL_BASE64_ENCODE, ft_base64_encode },
		{ FT_SSL_BASE64_DECODE, ft_base64_decode },
	};
	char 	*msg = NULL;
	int		msg_len = 0;
	unsigned char *buffer = (unsigned char *)malloc(FT_SSL_BASE64_BUF_LEN);
	ft_bzero(buffer, FT_SSL_BASE64_BUF_LEN);


	if (ctx->opt.input == NULL)
		ctx->opt.input = argv[ctx->argi];
	msg_len = ft_get_input(ctx->opt.input, &msg);
	// printf("msg: %s\n", msg);
	// printf("msg_len: %d\n", msg_len);
	if (msg == NULL || msg_len < 1)
		return (EXIT_FAILURE);
	ftssl_base64[ctx->opt.mode].base64_mode(msg, buffer);
	ft_strdel(&msg);

	int fd = 1;
  // printf("%s\n", ctx->opt.output);
	if (ctx->opt.output != NULL) {	
		fd = open(ctx->opt.output, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
		if (fd == -1) {
			fprintf(stderr, "Error to open/create file");
			return (EXIT_FAILURE);
		}
  }

    int i = 0;
    int buf_len = ft_strlen(buffer);
  if (ctx->opt.mode == FT_SSL_BASE64_ENCODE) {

    while (i + 64 < buf_len) {
      write(fd, &buffer[i], 64);
      write(fd, "\n", 1);
      i += 64;
    }

    write(fd, &buffer[i], buf_len - i);
    write(fd, "\n", 1);
  } else {
    write(fd, &buffer[0], buf_len);
    // ft_putstr_fd(fd, buffer);
  }

  // free(&buffer);
  ft_strdel(&buffer);
  if (ctx->opt.output != NULL)
    close(fd);	


	return (EXIT_SUCCESS);
}