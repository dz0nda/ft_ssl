#include "ft_ssl.h"

int		main(int argc, char const *argv[])
{
	t_ftssl	ssl;

	ft_ssl_init(&ssl);
	// if (argc < 2)
	// 	ft_ssl_shell(&ssl);
	const unsigned char arg[64] = "abc";
	const char *prgm = "md5";

	unsigned char md[16];
	size_t        len;

	ft_bzero(md, sizeof(md));
	len = ft_strlen((const char *)arg);
	ft_dgst(arg, len, md);
	printf("\nMD5(%s)\n", md);
	return 0;
}
