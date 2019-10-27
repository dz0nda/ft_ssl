#include "ft_ssl_cipher.h"

void     ft_ssl_usage_cipher(void)
{
    ft_putstr("Cipher commands: \n");
    ft_putstr("base64, des \n");
}

int     ft_ssl_parse_type_cipher(char *s)
{
    const char *ft_ssl_cipher_cmd[FT_SSL_CIPHER_CMD] = {
        "base64",
        "des"
    };
    int i;

    i = -1;
    while (++i < FT_SSL_CIPHER_CMD)
        if (ft_strcmp(s, ft_ssl_cipher_cmd[i]) == 0)
            return (0);
    return (1);
}

// int				        ft_cipher(t_cipher *ctx)
// {
//     printf("ïm in cipher\n");
// 	return (EXIT_SUCCESS);
// }