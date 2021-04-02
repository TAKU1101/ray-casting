#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next_lst;

	if (!*lst)
		return ;
	while ((*lst)->next)
	{
		next_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_lst;
	}
	ft_lstdelone(*lst, del);
	*lst = 0;
}
