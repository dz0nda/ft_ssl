#include "ft_ssl.h"

int		ft_ssl_error(const char *cmd)
{
	ft_putstr("ft_ssl: Error: '");
	ft_putstr(cmd);
	ft_putstr("' is an invalid command.");
	return (EXIT_FAILURE);
}

int    ft_ssl_parse_flag_unknown(char c)
{
    printf("unknown option '-%c'\n", c);
    return (EXIT_FAILURE);
}

int ft_ssl_parse_flag(char c)
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
                if (ft_ssl_parse_flag(*argv[i]) == EXIT_FAILURE)
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