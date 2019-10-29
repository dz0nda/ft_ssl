#include "ft_ssl_dgst.h"

int     ft_dgst_dispatcher(char *cmd_name)
{
    const t_dgst_cmd_d dispatcher[FT_DGST_CMD] = {
        { FT_MD5, "md5" },
        { FT_SHA1, "sha1" },
        { FT_SHA256, "sha256" }
    };
    int i;

    i = -1;
    while (++i < FT_DGST_CMD)
        if (ft_strcmp(cmd_name, dispatcher[i].cmd_name) == 0)
            return (i);
    return (-1);
}
