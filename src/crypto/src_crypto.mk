SUBDIRS_CRYPTO = \
			crypto \
			crypto/md5 \
			crypto/sha \
			crypto/udgst \
			crypto/b64 \
			crypto/kdf \
			crypto/des

SUBFILES_CRYPTO = \
			crypto/md5/ft_md5_utils.c \
			crypto/md5/ft_md5.c \
			\
			crypto/sha/ft_sha1_utils.c \
			crypto/sha/ft_sha1.c \
			crypto/sha/ft_sha256_utils.c \
			crypto/sha/ft_sha224.c \
			crypto/sha/ft_sha256.c \
			crypto/sha/ft_sha512_utils.c \
			crypto/sha/ft_sha384.c \
			crypto/sha/ft_sha512.c \
			crypto/sha/ft_sha512256.c \
			\
			crypto/udgst/ft_udgst.c \
			\
			crypto/b64/ft_b64_enc.c \
			crypto/b64/ft_b64_dec.c \
			crypto/b64/ft_b64_tools.c \
			\
			crypto/kdf/ft_kdf.c \
			\
			crypto/des/ft_des_ecb.c \
			crypto/des/ft_des_cbc.c \
			crypto/des/ft_des_pad.c \
			crypto/des/ft_des_subkeys.c \
			crypto/des/ft_des_exec.c \
			crypto/des/ft_des_f.c \
			crypto/des/ft_des_tools.c