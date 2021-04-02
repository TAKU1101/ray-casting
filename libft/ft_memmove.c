#include "libft.h"

void	*ft_memmove(void *dest, const void *srcs, size_t len)
{
	char		*p1;
	const char	*p2;
	size_t		i;

	p1 = dest;
	p2 = srcs;
	if (dest == (void *)0 && srcs == (void *)0)
		return (0);
	if (p1 > p2)
		while (len--)
			*(p1 + len) = *(p2 + len);
	else
	{
		i = 0;
		while (i < len)
		{
			*(p1 + i) = *(p2 + i);
			i++;
		}
	}
	return (dest);
}
