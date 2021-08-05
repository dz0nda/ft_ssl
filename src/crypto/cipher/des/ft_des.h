/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/07/21 23:16:16 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DES_H
# define FT_DES_H

# include "../../../ft_ssl_global.h"

# include "../../dgst/udgst/ft_udgst.h"

#define FT_BYTE_LEN 8

# define EVP_MAX_MD_SIZE 64     /* SHA512 */
# define PKCS5_SALT_LEN 8



typedef unsigned char ubyte;
typedef ubyte subkey_t[17][6]; /* 17 sets of 48 bits */

typedef struct		s_des
{
	int		iblock;
	char 	salt[8];
	char 	key[16];
	char 	iv[16];
	int pad;
	uint64_t nkey;
	subkey_t ks;
}					t_des;


int 	ft_des(char *key, char *msg, int msg_len, char **cipher);
int 	ft_des_cbc(char *key, char *msg, int msg_len, char **cipher, char *iv);
int 	ft_des_decode(char *key, char *msg, int msg_len, char **cipher);



void ft_des_gensubkeys(t_uint64 key, subkey_t ks, int reverse);
void ft_des_f(ubyte *r, ubyte *ks, ubyte *sp);

void ft_set_bit(t_uint8 *dst, int index, int value);
int  ft_get_bit(const t_uint8 *src, int index);
uint64_t hex2int(char *hex);
void printBits(size_t const size, void const * const ptr);

void 	ft_des_exec(const t_uchar *msg, subkey_t ks, char *cipher);

#endif
