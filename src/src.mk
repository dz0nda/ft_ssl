# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzonda <dzonda@student.le-101.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 23:36:16 by dzonda            #+#    #+#              #
#    Updated: 2020/02/29 23:36:17 by dzonda           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SUBDIR = \
			dgst \
			dgst/hash \
			ssl \
			ssl_cipher \
			ssl_dgst \
			ssl_dgst/err \
			ssl_dgst/opt \
			ssl_dgst/output \
			ssl_dgst/parser \
			ssl_stdrd

SUBFILE = \
			ssl/ft_ssl.c \
			ssl/ft_ssl_init.c \
			ssl/ft_ssl_shell.c \
			ssl/ft_ssl_dist.c \
			ssl/ft_ssl_core.c \
			\
			dgst/ft_dgst.c \
			dgst/ft_dgst_init.c \
			dgst/ft_dgst_update.c \
			dgst/ft_dgst_final.c \
			dgst/ft_dgst_debug.c \
			dgst/ft_dgst_utils.c \
			dgst/hash/ft_md5.c \
			dgst/hash/ft_sha1.c \
			dgst/hash/ft_sha224.c \
			dgst/hash/ft_sha256.c \
			dgst/hash/ft_sha384.c \
			dgst/hash/ft_sha512.c \
			\
			ssl_dgst/ft_ssl_dgst.c \
			ssl_dgst/ft_ssl_dgst_dist.c \
			ssl_dgst/err/ft_ssl_dgst_err.c \
			ssl_dgst/err/ft_ssl_dgst_err_usage.c \
			ssl_dgst/opt/ft_ssl_dgst_opt_dist.c \
			ssl_dgst/opt/ft_ssl_dgst_opt_p.c \
			ssl_dgst/opt/ft_ssl_dgst_opt_s.c \
			ssl_dgst/opt/ft_ssl_dgst_opt_outp.c \
			ssl_dgst/output/ft_ssl_dgst_output_q.c \
			ssl_dgst/output/ft_ssl_dgst_output_r.c \
			ssl_dgst/output/ft_ssl_dgst_output.c \
			ssl_dgst/parser/ft_ssl_dgst_parse_opt.c \
			ssl_dgst/parser/ft_ssl_dgst_parse_arg.c \
			\
			ssl_cipher/ft_ssl_cipher.c \
			ssl_cipher/ft_ssl_cipher_dist.c \
			\
			ssl_stdrd/ft_ssl_stdrd.c \
			ssl_stdrd/ft_ssl_stdrd_dist.c
