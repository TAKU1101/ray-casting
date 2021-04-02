#include "cub3d.h"

static void		set_wall_line(int len, t_game_data *data, \
								int *map, t_line_data *l_data)
{
	int	i;
	int	j;
	int	f;
	int r;

	if_init(&i, &f, data, len);
	jif_init(&j, &i, &f, data);
	while (i < f)
	{
		r = l_data->line_n + (l_data->w * (int)(((double)l_data->h / \
														(double)len) * j));
		if (l_data->i + (data->mapkey.r_width * i) < 0 || data->mapkey.r_hight \
			* data->mapkey.r_width < l_data->i + (data->mapkey.r_width * i) \
			|| r < 0 || l_data->h * l_data->w < r + 1)
		{
			i++;
			j++;
			continue ;
		}
		map[l_data->i + (data->mapkey.r_width * i)] = l_data->img[r];
		i++;
		j++;
	}
	set_sp_line(data, map, l_data);
}

static int		wall_d_x(t_line_data *l_data, t_game_data *data, int q)
{
	float	n;
	int		s_sign;
	int		c_sign;
	float	x;
	float	y;

	init_sign(&c_sign, &s_sign, q);
	l_data->x = l_data->x + 1.0;
	init_xy_pos(l_data, &x, &y, q);
	if (data->mapkey.map[(int)roundf(data->player.pos_y + y)]\
						[(int)roundf(data->player.pos_x + x)] == 1)
	{
		n = (((l_data->x - 1) / cos(l_data->r)) * c_sign);
		init_line_x(l_data, data, n, q);
		n = data->mapkey.r_hight / \
				(cos(fabsf(data->player.dir - l_data->r)) * n);
		set_wall_line((int)roundf(n), data, data->img.data, l_data);
		return (1);
	}
	if (data->mapkey.map[(int)roundf(data->player.pos_y + y)]\
						[(int)roundf(data->player.pos_x + x)] == 2)
		set_line_sp(l_data, data, roundf(data->player.pos_x + x), \
									roundf(data->player.pos_y + y));
	return (0);
}

static int		wall_d_y(t_line_data *l_data, t_game_data *data, int q)
{
	float	n;
	int		s_sign;
	int		c_sign;
	float	x;
	float	y;

	init_sign(&c_sign, &s_sign, q);
	l_data->y = l_data->y + 1.0;
	init_xy_pos(l_data, &x, &y, q);
	if (data->mapkey.map[(int)roundf(data->player.pos_y + y)]\
						[(int)roundf(data->player.pos_x + x)] == 1)
	{
		n = (((l_data->y - 1) / sin(l_data->r)) * s_sign);
		init_line_y(l_data, data, n, q);
		n = data->mapkey.r_hight / \
				(cos(fabsf(data->player.dir - l_data->r)) * n);
		set_wall_line((int)roundf(n), data, data->img.data, l_data);
		return (1);
	}
	if (data->mapkey.map[(int)roundf(data->player.pos_y + y)]\
						[(int)roundf(data->player.pos_x + x)] == 2)
		set_line_sp(l_data, data, roundf(data->player.pos_x + x), \
									roundf(data->player.pos_y + y));
	return (0);
}

static void		wall_distance(float r, t_game_data *data, int q, int i)
{
	t_line_data	l_data;
	int			c_sign;
	int			s_sign;

	l_data.i = i;
	l_data.r = r;
	init_xy(&l_data, q, data);
	init_sign(&c_sign, &s_sign, q);
	l_data.next = NULL;
	while (1)
	{
		if (((l_data.x / cos(r)) * c_sign) < ((l_data.y / sin(r)) * s_sign))
		{
			if (wall_d_x(&l_data, data, q))
				return ;
		}
		else
		{
			if (wall_d_y(&l_data, data, q))
				return ;
		}
	}
}

void			set_wall(int *img_data, t_game_data *data)
{
	double	start;
	double	x;
	double	h;
	int		i;
	float	n;

	start = init_radian(data->player.dir, &h, data->mapkey.r_width, \
								data->mapkey.r_hight);
	i = 0;
	while (i < data->mapkey.r_width)
	{
		x = data->player.dir + atan((start - (h * i)));
		reload_r_d(&x);
		if (0 <= x && x < (M_PI / 2))
			wall_distance(x, data, 1, i);
		else if ((M_PI / 2) <= x && x < M_PI)
			wall_distance(x, data, 2, i);
		else if (((M_PI * -1) <= x && x < ((M_PI / 2) * -1)))
			wall_distance(x, data, 3, i);
		else if (((M_PI / 2) * -1) <= x && x < 0)
			wall_distance(x, data, 4, i);
		i++;
	}
	(void)n;
	(void)img_data;
}
