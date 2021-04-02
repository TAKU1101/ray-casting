#include "libft.h"

void	*ft_memccpy(void *dest, const void *srcs, int c, size_t len)
{
	char		*p1;
	const char	*p2;

	p1 = dest;
	p2 = srcs;
	while (len)
	{
		*(unsigned char *)p1 = *(unsigned char *)p2;
		if (*(unsigned char *)p2 == (unsigned char)c)
			break ;
		p1++;
		p2++;
		len--;
	}
	if (len != 0)
		return (++p1);
	else
		return (0);
}
