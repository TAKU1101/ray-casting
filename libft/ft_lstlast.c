#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *lst_i;

	if (!lst)
		return (lst);
	lst_i = lst;
	while (lst_i->next)
	{
		lst_i = lst_i->next;
	}
	return (lst_i);
}
