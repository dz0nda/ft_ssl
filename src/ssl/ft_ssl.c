#include "ft_ssl.h"

int		main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	const unsigned char arg[64] = "abcdeedcba";

	unsigned char md[16];
	size_t        len;

	ft_bzero(md, sizeof(md));
	len = ft_strlen((const char *)arg);
	ft_md5(arg, len, md);
	printf("MD5(%s)\n", md);
	return 0;
}
