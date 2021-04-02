#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	if (!(p = (t_list *)malloc(sizeof(t_list))))
		return (0);
	p->content = content;
	p->next = NULL;
	return (p);
}
