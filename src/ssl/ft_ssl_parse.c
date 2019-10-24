#include "ft_ssl.h"

int    ft_ssl_parse_flags_md(char c)
{
    const char *flags = "pqrs";
    size_t  nbflags;
    int i;

    nbflags = strlen(flags);
    i = -1;
    while (++i < nbflags)
        if (flags[i] == c)
            return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

int     ft_ssl_check_cmd(char *cmd)
{
    const char *ftssl_cmd[FT_SSL_DGST_CMD] = { "md5", "sha1", "sha256" };
    int i;

    i = -1;
    while (++i < FT_SSL_DGST_CMD)
        if (ft_strcmp(cmd, ftssl_cmd[i]) == 0)
            break;
    return (i);
}

int		ft_ssl_parse(int argc, char *argv[])
{
	int pqrs[4];
    int  i, files;
    FILE *inf, *outf;

    memset(pqrs, 0, sizeof(pqrs));
    while (++i < argc)
    {
        if (argv[i][0] == '-')
        {
            while (*++argv[i])
            {
                if (ft_ssl_parse_flags_md(*argv[i]) == EXIT_FAILURE)
                    return (ft_ssl_parse_flag_unknown(*argv[i]));
                else
                    printf("flag '%c' recognized \n", *argv[i]);
            }
        }
        else
        {
            printf("'%s' will be considered as a file\n", argv[i]);
        }
    }
	return (EXIT_SUCCESS);
}