#include "cub3d.h"

static int	check_line(char *f_line, char *s_line, int f_len, int s_len)
{
	int			i;

	i = 1;
	while (i < (f_len - 1))
	{
		if (ft_strchr("02EWSN", f_line[i]))
		{
			if (!ft_strchr("012EWSN", f_line[i + 1]) || \
				!ft_strchr("012EWSN", f_line[i - 1]))
				return (1);
			if ((i + 2) > s_len)
				return (1);
			if (!ft_strchr("012EWSN", s_line[i + 1]) || \
				!ft_strchr("012EWSN", s_line[i]) || \
				!ft_strchr("012EWSN", s_line[i - 1]))
				return (1);
		}
		i++;
	}
	if (f_line[i] != '1')
		return (1);
	return (0);
}

static void	check_player(char *line, int *p_flag)
{
	while (*line)
	{
		if (ft_strchr("WESN", *line))
			(*p_flag)++;
		line++;
	}
}

int			check_map(t_list *map)
{
	char	*f_line;
	char	*s_line;
	int		p_flag;
	int		err;

	err = 0;
	p_flag = 0;
	if (!map)
		return (1);
	if (sp_and_one(map->content))
		return (1);
	while ((map)->next)
	{
		f_line = (map)->content;
		s_line = ((map)->next)->content;
		map = (map)->next;
		err = check_line(f_line, s_line, ft_strlen(f_line), ft_strlen(s_line));
		err += check_line(s_line, f_line, ft_strlen(s_line), ft_strlen(f_line));
		check_player(f_line, &p_flag);
		if (err)
			return (1);
	}
	check_player(s_line, &p_flag);
	return (sp_and_one(s_line) || (p_flag != 1)) ? 1 : 0;
}
