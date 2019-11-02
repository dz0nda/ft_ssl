#include "ft_ssl_dgst.h"

int		read_file(char *dst, char *src, int len)
{
	static int fd = -1;
	int i;
	int bytes_read;
	char c[64];

	i = -1;
	bytes_read = -1;
			ft_bzero(c, sizeof(c));
	if (access(src, F_OK) == -1)
		return (-1);
	if (fd == -1 && (fd = open(src, O_RDONLY)) == -1)
		return (-1);
	while (++i < len)
	{
        if ((bytes_read = read(fd, &c, 1)) < 1)
            break ;
        ft_strcat(dst, c);
		ft_bzero(c, sizeof(c));
    }
	printf("Block len : %d read : %s.\n", i, dst);
	// bytes_read = read(fd, &c, len);
    // ft_strncpy(dst, c, bytes_read);
	if (i < len && close(fd) == -1)
		return (-1);
	else if (i < len)
		fd = -1;
	return (i);
}

int		read_string(char *dst, char *src, int len)
{
	static int i = 0;
	int j;

	j = 0;
	while (j < len)
	{
		if (src[i] == '\0')
			break;
        dst[j++] = src[i++];
    }
	if (src[i] == '\0')
		i = 0;
	dst[j] = '\0';
	return (j);
}

int		read_input(char *dst, char *src, int len)
{
	static int bytes_read = 1;
	static char buffer[4096];
	char c[2];

	printf("sizeof buffer : %ld\n", sizeof(buffer));
	// ft_bzero(buffer, sizeof(buffer));
	ft_memset(c, 0, sizeof(c));
	if (bytes_read == 1)
		while ((bytes_read = read(0, &c, 1)) > 0)
		{
			ft_strcat(buffer, c);
			ft_bzero(c, sizeof(c));
		}
	return (read_string(dst, buffer, len));
}

int     ft_ssl_dgst_input(t_dgst_ctx *ctx, t_dgst_ipt ipt)
{
	if (ipt.ipt_key == FT_DGST_FILE)
	{
		return (read_file((char *)ctx->block, ipt.ipt_name, ctx->len_mbs));
			// printf("File %s not found or not accessible.\n", ipt.ipt_name);
	}
	if (ipt.ipt_key == FT_DGST_STRING)
		return (read_string((char *)ctx->block, ipt.ipt_name, ctx->len_mbs));
	if (ipt.ipt_key == FT_DGST_INPUT)
		return (read_input((char *)ctx->block, ipt.ipt_name, ctx->len_mbs));
	return (EXIT_SUCCESS);
}

int 	get_input(uint8_t *block, t_dgst_ipt ipt, int len)
{
	if (ipt.ipt_key == FT_DGST_FILE)
	{
		return (read_file((char *)block, ipt.ipt_name, len));
			// printf("File %s not found or not accessible.\n", ipt.ipt_name);
	}
	if (ipt.ipt_key == FT_DGST_STRING)
		return (read_string((char *)block, ipt.ipt_name, len));
	if (ipt.ipt_key == FT_DGST_INPUT)
		return (read_input((char *)block, ipt.ipt_name, len));
	return (EXIT_SUCCESS);
}