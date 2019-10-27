#include "ft_ssl.h"

static int        ft_ssl_shell_read(int fd, int len, char *buffer)
{
    int i;
    char c[2];
    int bytes_read;
    int bytes_total;

    i = -1;
	ft_memset(c, 0, sizeof(c));
    bytes_read = 0;
	bytes_total = 0;
	while (++i < len)
	{
		if ((bytes_read = read(fd, &c, 1)) < 1)
			break;
		if (c[0] == '\n')
			break ;
		bytes_total += bytes_read;
        ft_strcat(buffer, c);
        ft_memset(c, 0, sizeof(c));
    }
	return (bytes_total);
}

static int 	    ft_ssl_shell_parse(t_ftssl_sh *sh, char *buffer)
{
	int i = 0;
	char buffer_temp[FTSSL_MAX_INPUT_SHELL];
	char *buffer_temp_ptr;

	i = 0;
    while (buffer[i] && sh->argc < FTSSL_SHMAX_ARG ) 
	{
		ft_memset(buffer_temp, 0, sizeof(buffer_temp));
		buffer_temp_ptr = buffer_temp;
        while (buffer[i] && ft_isspace(buffer[i]))
            i++;
		if (buffer[i]== '\0')
			return (EXIT_FAILURE);
		if (buffer[i] == '"')
		{
			while (buffer[i++] && buffer[i] != '"' )
				*buffer_temp_ptr++ = buffer[i];
			if (buffer[i])
				i++;
		}
		else
			while (buffer[i] && !ft_isspace(buffer[i]))
				*buffer_temp_ptr++ = buffer[i++];
		if ((sh->argv[sh->argc] = ft_strdup(buffer_temp)) == NULL)
			return (EXIT_FAILURE);
		sh->argc++;
    }
}

int		        ft_ssl_shell(t_ftssl_sh  *sh)
{
	char 	buffer[FTSSL_MAX_INPUT_SHELL];

	ft_memset(buffer, 0, sizeof(buffer));
	ft_putstr("ftSSL> ");
	ft_ssl_shell_read(0, FTSSL_MAX_INPUT_SHELL, buffer);
	ft_ssl_shell_parse(sh, buffer);
    return (EXIT_SUCCESS);
}
