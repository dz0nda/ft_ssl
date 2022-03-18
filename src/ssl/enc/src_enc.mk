SUBDIRS_ENC = \
			ssl/enc \
			ssl/enc/cli \
			ssl/enc/ssl_b64 \
			ssl/enc/ssl_b64/options \
			ssl/enc/ssl_b64/execute \
			ssl/enc/ssl_des \
			ssl/enc/ssl_des/options \
			ssl/enc/ssl_des/execute

SUBFILES_ENC = \
			ssl/enc/ft_enc.c \
			ssl/enc/ft_enc_key.c \
			ssl/enc/ft_enc_errors.c \
			ssl/enc/ft_enc_old.c \
			ssl/enc/cli/ft_enc_options.c \
			ssl/enc/cli/ft_enc_ciphers.c \
			ssl/enc/cli/ft_enc_help.c