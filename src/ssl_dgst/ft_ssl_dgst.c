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


// int     dispatch_padding(t_dgst_ctx *ctx, int ft_ssl_dgstcmd)
// {
//     static int (* const padding[FT_DGST_CMD])(t_dgst_ctx *) = {
//         ft_ssl_dgst_md5_init, 
//         ft_ssl_dgst_sha1_init,
//         ft_ssl_dgst_sha256_init
//     };

//     /* Call the function and return result */
//     return (*padding[ft_ssl_dgstcmd])(ctx);	
// }



int     ft_ssl_parse_type_dgst(char *s)
{
    const char *ft_ssl_dgst_cmd[FT_DGST_CMD] = {
        "md5",
        "sha1",
        "sha256"
    };
    int i;

    i = -1;
    while (++i < FT_DGST_CMD)
        if (ft_strcmp(s, ft_ssl_dgst_cmd[i]) == 0)
            return (i);
    return (-1);
}