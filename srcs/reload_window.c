#include "cub3d.h"

static void		set_back(int *img_data, t_game_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < ((data->mapkey).r_hight))
	{
		j = 0;
		while (j < ((data->mapkey).r_width))
		{
			if (i < (((data->mapkey).r_hight) / 2))
				img_data[(i * (data->mapkey).r_width) + j] = \
					(data->mapkey).c_color;
			else
				img_data[(i * (data->mapkey).r_width) + j] = \
					(data->mapkey).f_color;
			j++;
		}
		i++;
	}
	(void)img_data;
}

void			init_window(t_game_data *data)
{
	set_back(data->img.data, data);
	set_wall(data->img.data, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}

void			init_window_save(t_game_data *data)
{
	set_back(data->img.data, data);
	set_wall(data->img.data, data);
}

void			reload_window(t_game_data *data)
{
	init_window(data);
	(void)data;
}
