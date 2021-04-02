#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*p;
	char			*rp;

	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	rp = p;
	while (*s1)
		*(p++) = *(s1++);
	while (*s2)
		*(p++) = *(s2++);
	*p = '\0';
	return (rp);
}
