#ifndef FT_SSL_H
# define FT_SSL_H

# include "../md5/ft_md5.h"
# include "../sha1/ft_sha1.h"
# include "../sha256/ft_sha256.h"


/*
 *    Hash sizes:
 *      MD5       16 byte / 128 bit
 *      SHA-1     20 byte / 160 bit
 *      SHA-256   32 byte / 256 bit
 *      SHA-512   64 byte / 512 bit
 */

typedef struct	s_ft_ssl
{

}				t_ft_ssl;


int				ft_ssl_usage(void);
int				ft_ssl_error(const char *cmd);





#endif
