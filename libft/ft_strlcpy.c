#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *srcs, size_t len)
{
	char		*dp;
	const char	*sp;
	size_t		n;

	dp = dest;
	sp = srcs;
	n = len;
	if (n != 0)
		while (--n > 0)
			if ((*dp++ = *sp++) == '\0')
				break ;
	if (n == 0)
	{
		if (len != 0)
			*dp = '\0';
		while (*sp++)
			;
	}
	return (sp - srcs - 1);
}
