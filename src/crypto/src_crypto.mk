include src/crypto/dgst/src_dgst.mk
include src/crypto/cipher/src_cipher.mk

SUBDIRS_CRYPTO = \
			crypto \
			${SUBDIRS_DGST} \
			${SUBDIRS_CIPHER}

SUBFILES_CRYPTO = \
			${SUBFILES_DGST} \
			${SUBFILES_CIPHER}