#include "cub3d.h"

static int		scan_pass(char *line, char **pass)
{
	int n;

	if (*pass != NULL)
		return (1);
	line = line + skip_sp(line);
	n = 0;
	while (line[n] != ' ' && line[n] != '\t' && line[n] != '\r' && line[n])
		n++;
	line[n] = 0;
	*pass = ft_strdup(line);
	if (open(*pass, O_RDONLY) == -1)
		return (1);
	if (!ft_strnstr(*pass, ".xpm", ft_strlen(*pass)))
		return (1);
	(void)pass;
	return (0);
}

static int		scan_two_num(char *line, int *f_num, int *s_num)
{
	if (*s_num != -1 || *f_num != -1)
		return (1);
	line = line + skip_sp(line);
	*f_num = ft_atoi(line);
	line = line + skip_sp(line);
	line = line + skip_num(line);
	*s_num = ft_atoi(line);
	line = line + skip_sp(line);
	line = line + skip_num(line);
	if (*s_num <= 0 || *f_num <= 0 || *line != '\0')
	{
		*s_num = 1;
		return (1);
	}
	return (0);
}

static int		scan_three_num(char *line, int *num)
{
	int	f_num;
	int	s_num;
	int	t_num;

	line = line + skip_sp(line);
	f_num = ft_atoi(line);
	line = line + skip_num(line);
	line = line + skip_sp(line);
	*line == ',' ? line++ : 0;
	line = line + skip_sp(line);
	s_num = ft_atoi(line);
	line = line + skip_num(line);
	line = line + skip_sp(line);
	*line == ',' ? line++ : 0;
	line = line + skip_sp(line);
	t_num = ft_atoi(line);
	line = line + skip_sp(line);
	line = line + skip_num(line);
	if (!(0 <= f_num && f_num <= 255 && 0 <= s_num && s_num <= 255 \
		&& 0 <= t_num && t_num <= 255) || *num != -1 || *line != '\0')
		return (1);
	*num = (f_num * 65536) + (s_num * 256) + (t_num);
	return (0);
}

static int		scan_flag(t_mapkey *keys, char *line)
{
	int n;
	int res;

	n = skip_sp(line);
	res = 0;
	if (!ft_strncmp(&line[n], "R", 1))
		res = scan_two_num(&line[n + 1], &(keys->r_width), &(keys->r_hight));
	else if (!ft_strncmp(&line[n], "NO", 2))
		res = scan_pass(&line[n + 2], &(keys->no_pass));
	else if (!ft_strncmp(&line[n], "SO", 2))
		res = scan_pass(&line[n + 2], &(keys->so_pass));
	else if (!ft_strncmp(&line[n], "WE", 2))
		res = scan_pass(&line[n + 2], &(keys->we_pass));
	else if (!ft_strncmp(&line[n], "EA", 2))
		res = scan_pass(&line[n + 2], &(keys->ea_pass));
	else if (!ft_strncmp(&line[n], "S", 1))
		res = scan_pass(&line[n + 1], &(keys->s_pass));
	else if (!ft_strncmp(&line[n], "F", 1))
		res = scan_three_num(&line[n + 1], &(keys->f_color));
	else if (!ft_strncmp(&line[n], "C", 1))
		res = scan_three_num(&line[n + 1], &(keys->c_color));
	else if (ft_strncmp(&line[n], "1", 1) && line[n] != 0)
		res = 1;
	(void)keys;
	return (res);
}

int				scan_file(char *pass, t_mapkey *keys, t_player *player)
{
	int		err;
	int		fd;
	char	*line;
	t_list	*map;

	fd = open(pass, O_RDONLY);
	map = NULL;
	init_mapkey(keys);
	while ((get_next_line(fd, &line)) > 0)
	{
		err = scan_flag(keys, line);
		err += scan_map(keys, line, &map);
		if (err != 0)
			break ;
		free(line);
	}
	free(line);
	if (err || check_map(map))
	{
		scan_free(map, keys);
		return (1);
	}
	keys->map = ch_int_map(map, keys, player);
	free_map(map);
	return (0);
}
