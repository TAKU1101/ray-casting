#include "cub3d.h"

void	init_line_x(t_line_data *l_data, t_game_data *data, float n, int q)
{
	float	per;

	if (q == 1 || q == 4)
	{
		per = fmod(data->player.pos_y - sin(l_data->r) * n, 1.0);
		l_data->line_n = (int)(per * data->imgs.ea_w);
		l_data->w = data->imgs.ea_w;
		l_data->h = data->imgs.ea_h;
		l_data->img = data->imgs.ea_img.data;
	}
	else if (q == 2 || q == 3)
	{
		per = 1 - fmod(data->player.pos_y - sin(l_data->r) * n, 1.0);
		l_data->line_n = (int)(per * data->imgs.we_w);
		l_data->w = data->imgs.we_w;
		l_data->h = data->imgs.we_h;
		l_data->img = data->imgs.we_img.data;
	}
}

void	init_line_y(t_line_data *l_data, t_game_data *data, float n, int q)
{
	float	per;

	if (q == 1 || q == 2)
	{
		per = fmod(data->player.pos_x + cos(l_data->r) * n, 1.0);
		l_data->line_n = (int)(per * data->imgs.no_w);
		l_data->w = data->imgs.no_w;
		l_data->h = data->imgs.no_h;
		l_data->img = data->imgs.no_img.data;
	}
	else if (q == 3 || q == 4)
	{
		per = 1 - fmod(data->player.pos_x + cos(l_data->r) * n, 1.0);
		l_data->line_n = (int)(per * data->imgs.so_w);
		l_data->w = data->imgs.so_w;
		l_data->h = data->imgs.so_h;
		l_data->img = data->imgs.so_img.data;
	}
}
