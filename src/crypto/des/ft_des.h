/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2022/03/05 19:11:57 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DES_H
#define FT_DES_H

// #include <bsd/readpassphrase.h>

#include "../../ft_ssl_global.h"
#include "../udgst/ft_udgst.h"

#define FT_BYTE_LEN 8

#define EVP_MAX_MD_SIZE 64 /* SHA512 */
#define PKCS5_SALT_LEN 8

typedef unsigned char ubyte;
typedef ubyte t_des_subkeys[17][6]; /* 17 sets of 48 bits */

typedef struct s_des {
  int iblock;
  char salt[8];
  char key[16];
  char iv[16];
  int pad;
  t_uint64 nkey;
  t_des_subkeys ks;
} t_des;

/*
**	DES-ECB
*/
int ft_des_ecb_encrypt(char* key, char* msg, int msg_len, char** cipher, char* iv);
int ft_des_ecb_decrypt(char* key, char* msg, int msg_len, char** cipher, char* iv);

/*
**	DES-CBC
*/
int ft_des_cbc_encrypt(char* key, char* msg, int msg_len, char** cipher,
  char* iv);
int ft_des_cbc_decrypt(char* key, char* msg, int msg_len, char** cipher,
  char* iv);

/*
**	DES CORE
*/
void ft_des_exec(const t_uchar* msg, t_des_subkeys ks, char* cipher);
void ft_des_f(ubyte* r, ubyte* ks, ubyte* sp);

/*
**	DES KEYS
*/
void ft_des_gensubkeys(t_uint64 key, t_des_subkeys ks, int reverse);

/*
**	DES PAD
*/
int ft_des_pad(char* msg, int msg_len, char** cipher);

/*
**	DES-TOOLS
*/
int ft_des_get_encoded_len(int msg_len);
void ft_set_bit(t_uint8* dst, int index, int value);
int ft_get_bit(const t_uint8* src, int index);
uint64_t hex2int(char* hex);
void printBits(size_t const size, void const* const ptr);
void hexdump(void* mem, unsigned int len);

/*
**	KDF
*/
int ft_des_kdf(char* pass, const unsigned char* salt, char* key, char* iv);

#endif
