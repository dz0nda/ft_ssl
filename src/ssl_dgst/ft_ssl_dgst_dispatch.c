#include "ft_ssl_dgst.h"

int     ft_dgst_dispatcher(char *cmd_name)
{
    const t_dgst_cmd_d dispatcher[FT_DGST_CMD] = {
        { FT_MD5, "md5" },
        { FT_SHA1, "sha1" },
        { FT_SHA256, "sha256" }
    };
    int cmd_key;

    cmd_key = -1;
    while (++cmd_key < FT_DGST_CMD)
        if (ft_strcmp(cmd_name, dispatcher[cmd_key].cmd_name) == 0)
            return (cmd_key);
    return (-1);
}
