# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src_ssl.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 23:36:16 by dzonda            #+#    #+#              #
#    Updated: 2021/08/09 08:51:57 by user42           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

include src/ssl/ssl_core/src_ssl_core.mk
include src/ssl/ssl_dgst/src_ssl_dgst.mk
include src/ssl/ssl_cipher/src_ssl_cipher.mk

SUBDIRS_SSL = \
			ssl \
			${SUBDIRS_SSL_CORE} \
			${SUBDIRS_SSL_DGST} \
			${SUBDIRS_SSL_CIPHER}

SUBFILES_SSL = \
			ssl/ft_ssl.c \
			${SUBFILES_SSL_CORE} \
			${SUBFILES_SSL_DGST} \
			${SUBFILES_SSL_CIPHER}