# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 23:36:16 by dzonda            #+#    #+#              #
#    Updated: 2021/05/03 21:12:03 by dzonda           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

include src/crypto/src_crypto.mk
include src/ssl/src_ssl.mk

SUBDIR = ${SUBDIRS_CRYPTO} ${SUBDIRS_SSL}
SUBFILE = ${SUBFILES_CRYPTO} ${SUBFILES_SSL}
