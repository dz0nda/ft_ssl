SUBDIRS_ENC = \
			ssl/enc \
			ssl/enc/ssl_b64 \
			ssl/enc/ssl_b64/options \
			ssl/enc/ssl_b64/execute \
			ssl/enc/ssl_des \
			ssl/enc/ssl_des/options \
			ssl/enc/ssl_des/execute

SUBFILES_ENC = \
			ssl/enc/ft_enc.c \
			\
			ssl/enc/ssl_b64/ft_ssl_b64.c \
			ssl/enc/ssl_b64/options/ft_ssl_b64_parse.c \
			ssl/enc/ssl_b64/options/ft_ssl_b64_options.c \
			ssl/enc/ssl_b64/execute/ft_ssl_b64_exec.c \
			\
			ssl/enc/ssl_des/ft_ssl_des.c \
			ssl/enc/ssl_des/options/ft_ssl_des_options.c \
			ssl/enc/ssl_des/options/ft_ssl_des_parse.c \
			ssl/enc/ssl_des/execute/ft_ssl_des_exec_key.c \
			ssl/enc/ssl_des/execute/ft_ssl_des_exec_enc.c \
			ssl/enc/ssl_des/execute/ft_ssl_des_exec_dec.c