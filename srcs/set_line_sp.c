#include "cub3d.h"

static float	init_x(float ab, float cb)
{
	if (ab < 0 && cb >= 0)
		return (atan(cb / ab) * -1);
	else if (ab >= 0 && cb >= 0)
		return (M_PI - atan(cb / ab));
	else if (ab >= 0 && cb < 0)
		return ((M_PI + atan(cb / ab)) * -1);
	else if (ab < 0 && cb < 0)
		return (atan(cb / ab) * -1);
	return (0.0);
}

void			set_line_sp(t_line_data *l_data, t_game_data *data, \
														float x, float y)
{
	float	ac;
	float	cd;
	float	ad;
	float	ce;
	float	x1;

	x1 = init_x(data->player.pos_x - (x + 0.5), data->player.pos_y - (y + 0.5));
	ac = fabs((data->player.pos_x - (x + 0.5)) / cos(x1));
	if (ac == 0.0)
		ac = fabs((data->player.pos_y - (y + 0.5)) / sin(x1));
	cd = ac * sin(data->player.dir - x1);
	ad = ac * cos(data->player.dir - x1);
	ce = cd + ad * tan(l_data->r - data->player.dir);
	if (-0.5 <= ce && ce <= 0.5)
		ft_lstadd_front_sp(&(l_data->next), \
		ft_lstnew_sp((int)roundf((data->mapkey.r_hight / ad)), \
		(int)roundf((ce * -1 + 0.5) * data->imgs.s_w)));
}
