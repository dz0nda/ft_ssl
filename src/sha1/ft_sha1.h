#ifndef FT_SHA1_H
# define FT_SHA1_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# include "../../lib/libft/libft.h"
# include "../ssl_utils/ft_ssl_utils.h"

# define FT_SHA1_MODBYTE    64
# define FT_SHA1_MODBITS    512
# define FT_SHA1_BYTE       8

typedef enum    s_sha1_enum
{
  FT_SHA1_MBS = 64,
  FT_SHA1_HS = 32,
  FT_SHA1_HBS = 256
}               t_sha1_e;

typedef struct	s_sha1_context
{
  uint32_t		state[5];
}				        t_sha1_ctx;

int               ft_sha1(const unsigned char *d, unsigned long n, unsigned char *md);
char		          *ft_sha1_padding(const unsigned char *d, unsigned long n);
int				        ft_sha1_update(t_sha1_ctx *ctx, const void *data, unsigned long len);
int				        ft_sha1_final(t_sha1_ctx *ctx, unsigned char *md);

uint32_t		      ft_sha1_sigma0a(uint32_t word);
uint32_t		      ft_sha1_sigma1a(uint32_t word);
uint32_t		      ft_sha1_sigma0b(uint32_t word);
uint32_t		      ft_sha1_sigma1b(uint32_t word);



#endif

// 68b3 29da
// 9893 e340
// 99c7 d8ad
// 5cb9 c940