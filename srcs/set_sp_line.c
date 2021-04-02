#include "cub3d.h"

static int	is_continue(t_game_data *data, t_line_data *l_data, int i, int r)
{
	return (l_data->i + (data->mapkey.r_width * i) < 0 || data->mapkey.r_hight \
			* data->mapkey.r_width < l_data->i + (data->mapkey.r_width * i) \
			|| r < 0 || data->imgs.s_w * data->imgs.s_h < 0);
}

static void	set_sp_line_st(t_game_data *data, int *map, \
									t_line_data *l_data, t_sp *sp)
{
	int i;
	int j;
	int f;
	int r;

	i = (data->mapkey.r_hight - sp->h_n) / 2;
	f = data->mapkey.r_hight - (data->mapkey.r_hight - sp->h_n) / 2;
	j = 0;
	while (i < f)
	{
		r = sp->w_n + (data->imgs.s_w * (int)roundf(((double)data->imgs.s_h / \
								(double)sp->h_n) * j));
		if (is_continue(data, l_data, i, r))
		{
			i++;
			j++;
			continue ;
		}
		r = (sp->w_n == data->imgs.s_w) ? r - 1 : r;
		if (data->imgs.s_img.data[r])
			map[l_data->i + (data->mapkey.r_width * i)] = \
						data->imgs.s_img.data[r];
		i++;
		j++;
	}
}

void		set_sp_line(t_game_data *data, int *map, t_line_data *l_data)
{
	t_sp	*sp;
	t_sp	*start;

	if (l_data->next)
	{
		sp = l_data->next;
		start = sp;
		while (sp)
		{
			set_sp_line_st(data, map, l_data, sp);
			sp = sp->next;
		}
		ft_lstclear_sp(&start);
	}
}
