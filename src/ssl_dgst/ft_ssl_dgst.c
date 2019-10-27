#include "ft_ssl_dgst.h"

char	*ft_ssl_input_fd(int fd)
{
	int len = 512;
	int i = -1;
    char c[2];
    int bytes_read;
	char buffer[513];
	
	ft_memset(buffer, 0, sizeof(buffer));
	ft_memset(c, 0, sizeof(c));
	while (++i < len)
	{
		if ((bytes_read = read(fd, &c, 1)) < 0)
			break;
		if (c[0] == '\n')
			break ;
        ft_strcat(buffer, c);
        // ft_putchar(c[0]);
        ft_memset(c, 0, sizeof(c));
    }
	return (ft_strdup(buffer));
}

char	*ft_ssl_input_string(char *s)
{
	ft_putendl(s);
	return (ft_strdup(s));
}

// char	*ft_ssl_input_dispatch(t_input_u *input, int type)
// {
// 	if (type == FT_INPUT_FILE)
// 		return (ft_ssl_input_fd(input->fd));
// 	if (type == FT_INPUT_STRING)
// 		return (ft_ssl_input_string(input->s));
// }

static void			ft_init_showdgst(t_md5_ctx *ctx)
{
	int i;

	i = -1;
	printf("Init show: \n");
	while (++i < 4)
		printf("hash[%d] = %x ", i, ctx->state[i]);
	printf("\n");
}


int     dispatch_padding(t_dgst_ctx *ctx, int ft_ssl_dgstcmd)
{
    static int (* const padding[FT_SSL_DGST_CMD])(t_dgst_ctx *) = {
        ft_ssl_dgst_md5_init, 
        ft_ssl_dgst_sha1_init,
        ft_ssl_dgst_sha256_init
    };

    /* Call the function and return result */
    return (*padding[ft_ssl_dgstcmd])(ctx);	
}

int     ft_ssl_parse_type_dgst(char *s)
{
    const char *ft_ssl_dgst_cmd[FT_SSL_DGST_CMD] = {
        "md5",
        "sha1",
        "sha256"
    };
    int i;

    i = -1;
    while (++i < FT_SSL_DGST_CMD)
        if (ft_strcmp(s, ft_ssl_dgst_cmd[i]) == 0)
            return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}