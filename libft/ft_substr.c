#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;
	char *ptr;

	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s)
	{
		if (start <= 0 && len > 0)
		{
			*str = *s;
			str++;
			len--;
		}
		s++;
		if (start != 0)
			start--;
	}
	*str = '\0';
	return (ptr);
}
