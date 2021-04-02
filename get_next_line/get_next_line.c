#include "get_next_line.h"

void	change_null(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str[i] = '\0';
}

int		set_line(int fd, char *buf, char **line, char **save)
{
	char	*tmp;
	int		r;

	while ((r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (!*line)
			*line = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(*line, buf);
			free(*line);
			*line = ft_strdup(tmp);
			free(tmp);
		}
		if (ft_strchr(buf, '\n') != NULL)
		{
			tmp = ft_strchr(buf, '\n');
			ft_memmove(*save, tmp, ft_strlen(tmp) + 1);
			change_null(*line);
			break ;
		}
	}
	return (r);
}

int		set_line_save(int fd, char *buf, char **line, char **save)
{
	char	*tmp;
	int		n;
	int		r;

	if (**save)
	{
		n = ft_strlen(&(*save)[1]);
		ft_memmove(*save, &(*save)[1], n + 1);
		*line = ft_strdup(*save);
	}
	if (ft_strchr(*save, '\n'))
	{
		tmp = ft_strchr(*line, '\n');
		ft_memmove(*save, tmp, ft_strlen(tmp) + 1);
		change_null(*line);
		r = 1;
	}
	else
		r = set_line(fd, buf, line, save);
	if (!*line)
		*line = ft_strdup("");
	return (r);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			r;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!save)
	{
		if (!(save = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		*save = 0;
	}
	buf[BUFFER_SIZE] = '\0';
	r = 0;
	*line = 0;
	r = set_line_save(fd, buf, line, &save);
	free(buf);
	if (r <= 0)
	{
		free(save);
		save = 0;
	}
	return (r <= 0 ? r : 1);
}
