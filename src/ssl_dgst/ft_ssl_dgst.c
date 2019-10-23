#include "ft_ssl_dgst.h"

static void			ft_init_showdgst(t_md5_ctx *ctx)
{
	int i;

	i = -1;
	printf("Init show: \n");
	while (++i < 4)
		printf("hash[%d] = %x ", i, ctx->state[i]);
	printf("\n");
}


int     dispatch_padding(t_dgst_ctx_u *ctx, int ft_ssl_dgstcmd)
{
    static int (* const padding[FT_SSL_DGST_CMD])(void *) = 
    {
        { ft_ssl_dgst_md5_init, ft_ssl_dgst_sha1_init, ft_ssl_dgst_sha256_init },
        { 0, 0, 0 },
        { 0, 0, 0 }
    };

    /* Call the function and return result */
    return (*padding[ft_ssl_dgstcmd])(ctx);	
}

int				        ft_dgst(const unsigned char *d, unsigned long n, unsigned char *md)
{
	t_dgst_ctx	ctx;

	dispatch_padding(&ctx, FT_MD5);
    ft_init_showdgst(&ctx.dgst_ctx);
	return (EXIT_SUCCESS);
}