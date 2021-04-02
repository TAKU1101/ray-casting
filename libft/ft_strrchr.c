#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char *p;

	p = str;
	while (*p)
		p++;
	while (p >= str)
	{
		if (*p == (char)c)
			return ((char *)p);
		p--;
	}
	return (0);
}
