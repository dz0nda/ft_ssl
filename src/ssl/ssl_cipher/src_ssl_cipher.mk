SUBDIRS_SSL_CIPHER = \
			ssl/ssl_cipher \
			ssl/ssl_cipher/ssl_b64 \
			ssl/ssl_cipher/ssl_b64/options \
			ssl/ssl_cipher/ssl_b64/execute \
			ssl/ssl_cipher/ssl_des \
			ssl/ssl_cipher/ssl_des/options \
			ssl/ssl_cipher/ssl_des/execute

SUBFILES_SSL_CIPHER = \
			ssl/ssl_cipher/ft_ssl_cipher.c \
			\
			ssl/ssl_cipher/ssl_b64/ft_ssl_b64.c \
			ssl/ssl_cipher/ssl_b64/options/ft_ssl_b64_parse.c \
			ssl/ssl_cipher/ssl_b64/options/ft_ssl_b64_options.c \
			ssl/ssl_cipher/ssl_b64/execute/ft_ssl_b64_exec.c \
			\
			ssl/ssl_cipher/ssl_des/ft_ssl_des.c \
			ssl/ssl_cipher/ssl_des/options/ft_ssl_des_options.c \
			ssl/ssl_cipher/ssl_des/options/ft_ssl_des_parse.c \
			ssl/ssl_cipher/ssl_des/execute/ft_ssl_des_execute.c \
			ssl/ssl_cipher/ssl_des/execute/ft_ssl_des_execute_init.c