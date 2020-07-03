# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 23:36:16 by dzonda            #+#    #+#              #
#    Updated: 2020/07/03 17:31:13 by dzonda           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SUBDIR = \
			crypto/dgst \
			crypto/sha \
			ssl/ssl_core \
			ssl/ssl_shell \
			ssl/ssl_cipher \
			ssl/ssl_dgst \
			ssl/ssl_dgst/err \
			ssl/ssl_dgst/opt \
			ssl/ssl_dgst/output \
			ssl/ssl_dgst/parser \
			ssl/ssl_stdrd

SUBFILE = \
			ssl/ssl_core/ft_ssl.c \
			ssl/ssl_core/ft_ssl_core_dist.c \
			ssl/ssl_core/ft_ssl_core.c \
			ssl/ssl_core/ft_ssl_help.c \
			\
			ssl/ssl_shell/ft_ssl_shell.c \
			\
			crypto/dgst/ft_dgst.c \
			crypto/dgst/ft_dgst_init.c \
			crypto/dgst/ft_dgst_update.c \
			crypto/dgst/ft_dgst_final.c \
			crypto/dgst/ft_dgst_debug.c \
			crypto/dgst/ft_dgst_utils.c \
			crypto/sha/ft_md5.c \
			crypto/sha/ft_sha1.c \
			crypto/sha/ft_sha224.c \
			crypto/sha/ft_sha256.c \
			crypto/sha/ft_sha384.c \
			crypto/sha/ft_sha512.c \
			\
			ssl/ssl_dgst/ft_ssl_dgst.c \
			ssl/ssl_dgst/ft_ssl_dgst_dist.c \
			ssl/ssl_dgst/err/ft_ssl_dgst_err.c \
			ssl/ssl_dgst/err/ft_ssl_dgst_err_usage.c \
			ssl/ssl_dgst/opt/ft_ssl_dgst_opt_dist.c \
			ssl/ssl_dgst/opt/ft_ssl_dgst_opt_p.c \
			ssl/ssl_dgst/opt/ft_ssl_dgst_opt_s.c \
			ssl/ssl_dgst/opt/ft_ssl_dgst_opt_outp.c \
			ssl/ssl_dgst/output/ft_ssl_dgst_output_q.c \
			ssl/ssl_dgst/output/ft_ssl_dgst_output_r.c \
			ssl/ssl_dgst/output/ft_ssl_dgst_output.c \
			ssl/ssl_dgst/parser/ft_ssl_dgst_parse_opt.c \
			ssl/ssl_dgst/parser/ft_ssl_dgst_parse_arg.c \
			\
			ssl/ssl_cipher/ft_ssl_cipher.c \
			ssl/ssl_cipher/ft_ssl_cipher_dist.c \
			\
			ssl/ssl_stdrd/ft_ssl_stdrd.c \
			ssl/ssl_stdrd/ft_ssl_stdrd_dist.c
