#include "ft_ssl_cipher.h"

int     ft_ssl_cipher_dispatcher(char *cmd_name)
{
    const t_cipher_cmd_d dispatcher[FT_SSL_CIPHER_CMD] = {
        { FT_BASE64, "base64" },
        { FT_DES, "des" }
    };
    int i;

    i = -1;
    while (++i < FT_SSL_CIPHER_CMD)
        if (ft_strcmp(cmd_name, dispatcher[i].cmd_name) == 0)
            return (i);
    return (-1);
}
