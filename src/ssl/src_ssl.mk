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