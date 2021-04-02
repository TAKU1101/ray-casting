#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	else
	{
		del(lst->content);
		free(lst);
	}
}
