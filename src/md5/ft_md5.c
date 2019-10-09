#include "ft_md5.h"
#include <ctype.h>

#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 16
#endif
 
void hexdump(void *mem, unsigned int len)
{
	unsigned int i, j;
	
	for(i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++)
	{
					/* print offset */
					if(i % HEXDUMP_COLS == 0)
					{
									printf("0x%06x: ", i);
					}

					/* print hex data */
					if(i < len)
					{
									printf("%02x ", 0xFF & ((char*)mem)[i]);
					}
					else /* end of block, just aligning for ASCII dump */
					{
									printf("   ");
					}
					
					/* print ASCII dump */
					if(i % HEXDUMP_COLS == (HEXDUMP_COLS - 1))
					{
									for(j = i - (HEXDUMP_COLS - 1); j <= i; j++)
									{
													if(j >= len) /* end of block, not really printing */
													{
																	putchar(' ');
													}
													else if(isprint(((char*)mem)[j])) /* printable char */
													{
																	putchar(0xFF & ((char*)mem)[j]);        
													}
													else /* other char */
													{
																	putchar('.');
													}
									}
									putchar('\n');
					}
	}
}

static int			ft_md5_init(t_ft_md5_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_ft_md5_ctx));
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xefcdab89;
	ctx->state[2] = 0x98badcfe;
	ctx->state[3] = 0x10325476;
	return (EXIT_SUCCESS);
}

unsigned char		*ft_md5(const unsigned char *d, unsigned long n, unsigned char *md)
{
	char			*dpad;
	unsigned long	nalign;
	t_ft_md5_ctx	ctx;

	dpad = NULL;
	nalign = ft_get_size_aligned((n + FT_MD5_BYTE), FT_MD5_MODBYTE);
	ft_md5_init(&ctx);
	if ((dpad = ft_md5_padding(d, nalign)) == NULL)
		return (NULL);
	hexdump(dpad, (unsigned int)nalign);
	ft_md5_update(&ctx, (const void *)dpad, nalign);
	ft_md5_final(&ctx, md);
	ft_strdel(&dpad);
	return (md);
}
