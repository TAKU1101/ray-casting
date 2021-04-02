#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t len)
{
	unsigned char	*p1;

	p1 = (unsigned char *)buf;
	while (len)
	{
		if (*p1 == (unsigned char)ch)
			return (p1);
		p1++;
		len--;
	}
	return (NULL);
}
