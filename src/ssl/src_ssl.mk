SUBDIRS_SSL = \
			ssl \
			ssl/ssl_core \
			ssl/ssl_cipher \
			ssl/ssl_cipher/ssl_base64 \
			ssl/ssl_cipher/ssl_des \
			ssl/ssl_dgst

SUBFILES_SSL = \
			ssl/ft_ssl.c \
			\
			ssl/ssl_cipher/ft_ssl_cipher.c \
			\
			ssl/ssl_cipher/ssl_base64/ft_ssl_base64.c \
			ssl/ssl_cipher/ssl_base64/ft_ssl_base64_options.c \
			ssl/ssl_cipher/ssl_base64/ft_ssl_base64_errors.c \
			\
			ssl/ssl_cipher/ssl_des/ft_ssl_des.c \
			ssl/ssl_cipher/ssl_des/ft_ssl_des_options.c \
			ssl/ssl_cipher/ssl_des/ft_ssl_des_errors.c \
			\
			ssl/ssl_core/ft_ssl_core_dist.c \
			ssl/ssl_core/ft_ssl_core.c \
			ssl/ssl_core/ft_ssl_help.c \
			ssl/ssl_core/ft_ssl_shell.c \
			\
			ssl/ssl_dgst/ft_ssl_dgst.c \
			ssl/ssl_dgst/ft_ssl_dgst_options.c \
			ssl/ssl_dgst/ft_ssl_dgst_output.c \
			ssl/ssl_dgst/ft_ssl_dgst_errors.c