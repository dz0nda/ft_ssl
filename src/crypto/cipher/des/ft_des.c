/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/07/21 23:28:07 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

int 	ft_des_get_encoded_len(int msg_len) {
	int padByte = 8 - msg_len % 8;
	return (msg_len + padByte);
}

int		ft_des_pad(char *msg, int msg_len, char **cipher) {
	int padByte = 8 - msg_len % 8;
	int len = msg_len + padByte;

	*cipher = (char *)malloc(len + 1);
	ft_memset((*cipher), '\0', len + 1);
	ft_memcpy((*cipher), msg, msg_len);
	ft_memset(&(*cipher)[msg_len], padByte, padByte);
	return (len);
}

int 	ft_des(char *key, char *msg, int msg_len, char **cipher)
{
	t_des ctx;

	ft_memset(&ctx, 0, sizeof(ctx));
	
	ft_memcpy(&ctx.nkey, key, 8);

	int len = ft_des_pad(msg, msg_len, cipher);

	ft_des_gensubkeys(ctx.nkey, ctx.ks, 0);

	int i = 0;
	while (i < len) {
		ft_des_exec(&(*cipher)[i], ctx.ks, &(*cipher)[i]);
		i += 8;
	}

	return (len);
	// printf("%s\n", *cipher);

}

int 	ft_des_cbc(char *key, char *msg, int msg_len, char **cipher, char *iv)
{
	t_des ctx;

	ft_memset(&ctx, 0, sizeof(ctx));
	
	ft_memcpy(&ctx.nkey, key, 8);

	int len = ft_des_pad(msg, msg_len, cipher);

	ft_des_gensubkeys(ctx.nkey, ctx.ks, 0);

	int i = 0;
	while (i < len) {
		int j = -1;
		while (++j < 8) {
			(*cipher)[i + j] ^= iv[j];
		}
		
		ft_des_exec(&(*cipher)[i], ctx.ks, &(*cipher)[i]);
		ft_memcpy(iv, &(*cipher)[i], 8);
		
		i += 8;
	}

	return (len);
	// printf("%s\n", *cipher);

}

int 	ft_des_decode(char *key, char *msg, int msg_len,char **cipher)
{
	printf("des decode:\n");
	t_des ctx;

	int len = msg_len;

	// t_uchar *dst = *cipher; 

	 *cipher = (char *)ft_memalloc(len);

	ft_memcpy(cipher[0], msg, len);

	ft_memset(&ctx, 0, sizeof(ctx));
	
	ft_memcpy(&ctx.nkey, key, 8);

	ft_des_gensubkeys(ctx.nkey, ctx.ks, 1);



	int i = 0;
	while (i < len) {
		ft_des_exec(&(*cipher)[i], ctx.ks, &(*cipher)[i]);
		i += 8;
	}

	char padByte = (*cipher)[len - 1];
	ft_memset(&(*cipher)[len - padByte], '\0', padByte);
}