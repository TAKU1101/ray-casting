#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t len)
{
	const char *p1;
	const char *p2;

	p1 = buf1;
	p2 = buf2;
	while (len)
	{
		if (*p1 != *p2)
			return (*(unsigned char *)p1 - *(unsigned char *)p2);
		p1++;
		p2++;
		len--;
	}
	return (0);
}
