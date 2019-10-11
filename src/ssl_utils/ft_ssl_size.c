# include "ft_ssl_utils.h"

size_t		ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}