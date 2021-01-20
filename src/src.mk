# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 23:36:16 by dzonda            #+#    #+#              #
#    Updated: 2021/01/20 15:25:57 by dzonda           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SUBDIR = \
			crypto/dgst \
			crypto/dgst/hash \
			ssl \
			ssl/ssl_core \
			ssl/ssl_cipher \
			ssl/ssl_dgst \

SUBFILE = \
			ssl/ft_ssl.c \
			ssl/ssl_core/ft_ssl_core_dist.c \
			ssl/ssl_core/ft_ssl_core.c \
			ssl/ssl_core/ft_ssl_help.c \
			ssl/ssl_core/ft_ssl_shell.c \
			\
			crypto/dgst/ft_dgst.c \
			crypto/dgst/hash/ft_md5_utils.c \
			crypto/dgst/hash/ft_md5.c \
			crypto/dgst/hash/ft_sha1.c \
			crypto/dgst/hash/ft_sha256_utils.c \
			crypto/dgst/hash/ft_sha224.c \
			crypto/dgst/hash/ft_sha256.c \
			crypto/dgst/hash/ft_sha512_utils.c \
			crypto/dgst/hash/ft_sha384.c \
			crypto/dgst/hash/ft_sha512.c \
			crypto/dgst/hash/ft_sha512256.c \
			\
			ssl/ssl_dgst/ft_ssl_dgst.c \
			ssl/ssl_dgst/ft_ssl_dgst_dist.c \
			ssl/ssl_dgst/ft_ssl_dgst_options.c \
			ssl/ssl_dgst/ft_ssl_dgst_output.c \
			ssl/ssl_dgst/ft_ssl_dgst_errors.c \
			\
			ssl/ssl_cipher/ft_ssl_cipher.c \
			ssl/ssl_cipher/ft_ssl_cipher_dist.c \
