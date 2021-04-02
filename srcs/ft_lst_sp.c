#include "cub3d.h"

t_sp	*ft_lstnew_sp(int h, int w)
{
	t_sp	*p;

	if (!(p = (t_sp *)malloc(sizeof(t_sp))))
		return (0);
	p->h_n = h;
	p->w_n = w;
	p->next = NULL;
	return (p);
}

void	ft_lstadd_front_sp(t_sp **lst, t_sp *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstclear_sp(t_sp **lst)
{
	t_sp *next_lst;

	if (!*lst)
		return ;
	while ((*lst)->next)
	{
		next_lst = (*lst)->next;
		ft_lstdelone_sp(*lst);
		*lst = next_lst;
	}
	ft_lstdelone_sp(*lst);
	*lst = 0;
}

void	ft_lstdelone_sp(t_sp *lst)
{
	free(lst);
}
