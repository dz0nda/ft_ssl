SUBDIRS_CIPHER = \
			crypto/cipher \
			crypto/cipher/b64 \
			crypto/cipher/kdf \
			crypto/cipher/des \

SUBFILES_CIPHER = \
			crypto/cipher/b64/ft_b64_enc.c \
			crypto/cipher/b64/ft_b64_dec.c \
			crypto/cipher/b64/ft_b64_tools.c \
			\
			crypto/cipher/kdf/ft_kdf.c \
			\
			crypto/cipher/des/ft_des_ecb.c \
			crypto/cipher/des/ft_des_cbc.c \
			crypto/cipher/des/ft_des_pad.c \
			crypto/cipher/des/ft_des_subkeys.c \
			crypto/cipher/des/ft_des_exec.c \
			crypto/cipher/des/ft_des_f.c \
			crypto/cipher/des/ft_des_tools.c