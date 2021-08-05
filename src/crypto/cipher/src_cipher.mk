SUBDIRS_CIPHER = \
			crypto/cipher \
			crypto/cipher/base64 \
			crypto/cipher/des \

SUBFILES_CIPHER = \
			crypto/cipher/base64/ft_base64.c \
			crypto/cipher/base64/ft_base64_decode.c \
			crypto/cipher/base64/ft_base64_tools.c \
			\
			crypto/cipher/des/ft_des.c \
			crypto/cipher/des/ft_des_subkeys.c \
			crypto/cipher/des/ft_des_exec.c \
			crypto/cipher/des/ft_des_f.c \
			crypto/cipher/des/ft_des_tools.c \
			crypto/cipher/des/ft_pbkdf.c