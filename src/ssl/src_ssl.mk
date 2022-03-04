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

include src/ssl/core/src_core.mk
include src/ssl/dgst/src_dgst.mk
include src/ssl/enc/src_enc.mk

SUBDIRS_SSL = \
			ssl \
			${SUBDIRS_CORE} \
			${SUBDIRS_DGST} \
			${SUBDIRS_ENC}

SUBFILES_SSL = \
			ssl/ft_ssl.c \
			${SUBFILES_CORE} \
			${SUBFILES_DGST} \
			${SUBFILES_ENC}