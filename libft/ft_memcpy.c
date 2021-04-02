#include "libft.h"

void	*ft_memcpy(void *dest, const void *srcs, size_t len)
{
	char *p;

	p = dest;
	if (dest == (void *)0 && srcs == (void *)0)
		return (0);
	while (len-- > 0)
	{
		*(char *)(dest++) = *(char *)(srcs++);
	}
	return (p);
}
