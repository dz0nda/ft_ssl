#include "ft_ssl.h"

int		ft_ssl_usage(void)
{
	void (*usage[FT_SSL_TYPE - 1])(void) = {
		ft_ssl_usage_stdrd, ft_ssl_usage_dgst, ft_ssl_usage_cipher
	};
	int i;

	i = -1;
	while (++i < FT_SSL_TYPE - 1)
	{
		ft_putstr("\n");
		usage[i]();
	}
	// ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
	return (EXIT_FAILURE);
}