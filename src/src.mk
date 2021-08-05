# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 23:36:16 by dzonda            #+#    #+#              #
#    Updated: 2021/06/11 10:22:39 by dzonda           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

include src/tools/src_tools.mk
include src/crypto/src_crypto.mk
include src/ssl/src_ssl.mk

SUBDIR = ${SUBDIRS_TOOLS} ${SUBDIRS_CRYPTO} ${SUBDIRS_SSL}
SUBFILE = ${SUBFILES_TOOLS} ${SUBFILES_CRYPTO} ${SUBFILES_SSL}
