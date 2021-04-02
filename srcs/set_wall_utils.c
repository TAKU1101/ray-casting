#include "cub3d.h"

void			if_init(int *i, int *f, t_game_data *data, int len)
{
	*i = (data->mapkey.r_hight - len) / 2;
	*f = data->mapkey.r_hight - (data->mapkey.r_hight - len) / 2;
}

void			jif_init(int *j, int *i, int *f, t_game_data *data)
{
	*j = 0;
	if (*i < 0)
	{
		*j = *i * -1;
		*i = 0;
		*f = data->mapkey.r_hight;
	}
}
