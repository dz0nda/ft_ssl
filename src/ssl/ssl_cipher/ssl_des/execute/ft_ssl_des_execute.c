/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/17 12:25:41 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

char 	msg[] = { 0x40, 0x03, 0x06, 0x0e, 0x8d, 0xb0, 0xd2, 0x6f, 0xfd, 0xf2, 0xe1, 0x74, 0x49, 0x29, 0x22, 0xf8 }; // "abcdefgh"; //"0123456789ABCDEF";
// char 	msg[] = { 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68 }; // "abcdefgh"; //"0123456789ABCDEF";

int		msg_len = 0;

// int		ft_ssl_des_exec_base64(t_ssl_des *ctx, int argc, char *argv[]) {

// }

#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 16
#endif
 
void hexdump(void *mem, unsigned int len)
{
        unsigned int i, j;
        
        for(i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++)
        {
                /* print offset */
                if(i % HEXDUMP_COLS == 0)
                {
                        printf("0x%06x: ", i);
                }
 
                /* print hex data */
                if(i < len)
                {
                        printf("%02x ", 0xFF & ((char*)mem)[i]);
                }
                else /* end of block, just aligning for ASCII dump */
                {
                        printf("   ");
                }
                
                /* print ASCII dump */
                if(i % HEXDUMP_COLS == (HEXDUMP_COLS - 1))
                {
                        for(j = i - (HEXDUMP_COLS - 1); j <= i; j++)
                        {
                                if(j >= len) /* end of block, not really printing */
                                {
                                        putchar(' ');
                                }
                                else if(isprint(((char*)mem)[j])) /* printable char */
                                {
                                        putchar(0xFF & ((char*)mem)[j]);        
                                }
                                else /* other char */
                                {
                                        putchar('.');
                                }
                        }
                        putchar('\n');
                }
        }
}

static int		ft_ouptput(char *file, char *output, int breaker)
{
	int		fd;
	int		i;
	int		length;

	fd = 1;
	i = 0;
	length = breaker;
	if (file != NULL && (fd = open(file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
		return (0);

  // if (breaker > 0) {
  //     while (i + breaker < length) {
  //       write(fd, &output[i], breaker);
  //       write(fd, "\n", 1);
  //       i += breaker;
  //     }
  // }

  write(fd, &output[i], length);
  // if (breaker) write(fd, "\n", 1);

	return (length);
}


int		ft_ssl_des_exec(t_ssl_des *ctx, int argc, char *argv[])
{
	static t_ssl_des_d		ftssl_des[2] = {
		{ FT_SSL_DES_ENC, ft_des },
		{ FT_SSL_DES_DEC, ft_des_decode },
	
	};
	char *cipher = NULL;
	char 	*input = NULL;
	int		input_len = 0;

	if (ctx->opt.input == NULL)
		ctx->opt.input = argv[ctx->argi];
	input_len = ft_get_input(ctx->opt.input, &input);

	ft_ssl_des_exec_pre_process(ctx);

        printf("key: %s\n", ctx->opt.key);
        printf("iv: %s\n", ctx->opt.iv);
        

        int len = ft_des_cbc(ctx->opt.key, input, input_len, &cipher, ctx->opt.iv);
	// int len = ftssl_des[ctx->opt.mode].des_mode(ctx->opt.key, input, input_len, &cipher);

	// hexdump(cipher, len);

	if (ft_strlen(ctx->opt.salt)) {
		// char *tmp = ft_strdup(cipher); // here !
                char *tmp = ft_memalloc(len);
                ft_memcpy(tmp, cipher, len);
		free(cipher);
		cipher = ft_memalloc(len + 16 + 1);
		ft_memset(cipher, '\0', len + 16 + 1);
		ft_memcpy(&cipher[0], "Salted__", 8);
		ft_memcpy(&cipher[8], ctx->opt.salt, 8);
		ft_memcpy(&cipher[16], tmp, len);
		free(tmp);
		len +=  16;
	}

	// hexdump(cipher, len);

	ft_ouptput(ctx->opt.output, cipher, len);

	return (EXIT_SUCCESS);
}