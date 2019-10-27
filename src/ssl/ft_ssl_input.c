#include    "ft_ssl.h"

int        ft_ssl_getInput_shell(int fd, int len, char *buffer)
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
		if ((bytes_read = read(fd, &c, 1)) < 0)
			break;
		if (c[0] == '\n')
			break ;
		bytes_total += bytes_read;
        ft_strcat(buffer, c);
        // ft_putchar(c[0]);
        ft_memset(c, 0, sizeof(c));
    }
	return (bytes_total);
}

int 	ft_ssl_splitBuffer(t_ftssl_sh *sh, char *buffer)
{
    int read_strings = 0;
    char *buf_ptr = buffer;

    while ( *buf_ptr && read_strings < FTSSL_SHMAX_ARG ) {
        char temp_buf[FTSSL_SHMAX_ARG] = {0};
        char *temp_ptr = temp_buf;

        while (*buf_ptr && ft_isspace(*buf_ptr))
            ++buf_ptr;
		if (*buf_ptr == '\0')
			return (EXIT_FAILURE);
		if ( *buf_ptr == '"' )
		{
			while ( *++buf_ptr && *buf_ptr != '"' )
				*temp_ptr++ = *buf_ptr++;
			if (*buf_ptr)
				++buf_ptr;
		}
		else {
			while (*buf_ptr && !ft_isspace(*buf_ptr))
				*temp_ptr++ = *buf_ptr++;
		}
		if ((sh->argv[read_strings] = ft_strdup(temp_buf)) == NULL)
			return (EXIT_FAILURE);
        }

    for ( size_t i = 0; sh->argv[i]; ++i ) {
        printf("String %zu: %s\n", i + 1, sh->argv[i]);
        free(sh->argv[i]);
    }
}

int		ft_ssl_getInput(t_ftssl *ssl)
{
	char 	buffer[FTSSL_MAX_INPUT_SHELL];

	ft_memset(buffer, 0, sizeof(buffer));
	ft_putstr("ftSSL> ");
	ft_ssl_getInput_shell(0, FTSSL_MAX_INPUT_SHELL, buffer);
	ft_ssl_splitBuffer(&ssl->sh, buffer);
}