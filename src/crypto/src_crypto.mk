SUBDIRS_CRYPTO = \
			crypto/cipher \
			crypto/cipher/base64 \
			crypto/cipher/des \
			\
			crypto/dgst \
			crypto/dgst/md5 \
			crypto/dgst/sha \
			crypto/dgst/udgst

SUBFILES_CRYPTO = \
			crypto/dgst/md5/ft_md5_utils.c \
			crypto/dgst/md5/ft_md5.c \
			\
			crypto/dgst/sha/ft_sha1_utils.c \
			crypto/dgst/sha/ft_sha1.c \
			crypto/dgst/sha/ft_sha256_utils.c \
			crypto/dgst/sha/ft_sha224.c \
			crypto/dgst/sha/ft_sha256.c \
			crypto/dgst/sha/ft_sha512_utils.c \
			crypto/dgst/sha/ft_sha384.c \
			crypto/dgst/sha/ft_sha512.c \
			crypto/dgst/sha/ft_sha512256.c \
			crypto/dgst/udgst/ft_udgst.c \
			\
			crypto/cipher/base64/ft_base64.c \
			crypto/cipher/base64/ft_base64_decode.c \
			crypto/cipher/base64/ft_base64_debug.c \
			\
			crypto/cipher/des/ft_des.c \
			crypto/cipher/des/ft_pbkdf.c