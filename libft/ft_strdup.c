#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *p;
	char *rp;

	p = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	rp = p;
	if (!p)
		return (NULL);
	while (*s1)
	{
		*p = *s1;
		s1++;
		p++;
	}
	*p = '\0';
	return (rp);
}
