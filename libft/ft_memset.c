#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = b;
	while (len)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}
