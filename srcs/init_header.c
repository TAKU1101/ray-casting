#include "cub3d.h"

static void	write_zero(unsigned char *buf, int start, int end)
{
	int i;

	i = start;
	while (i <= end)
	{
		buf[i] = 0;
		i++;
	}
}

static void	set_buf(int i, int n, unsigned char *buf)
{
	ft_memcpy(buf + i, &n, sizeof(n));
}

void		init_header(unsigned char *header, t_game_data *data)
{
	int				real_w;

	real_w = data->mapkey.r_width * 3 + data->mapkey.r_width % 4;
	write_zero(header, 0, 54);
	header[0] = 'B';
	header[1] = 'M';
	set_buf(2, HEADER_SIZE + (data->mapkey.r_hight * real_w), header);
	set_buf(10, HEADER_SIZE, header);
	set_buf(14, HEADER_INFO_SIZE, header);
	set_buf(18, data->mapkey.r_width, header);
	set_buf(22, data->mapkey.r_hight, header);
	set_buf(26, 1, header);
	set_buf(28, 24, header);
	set_buf(34, data->mapkey.r_hight * real_w, header);
	set_buf(38, 1, header);
	set_buf(42, 1, header);
}
