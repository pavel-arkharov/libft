/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:10:23 by parkharo          #+#    #+#             */
/*   Updated: 2021/12/19 19:31:58 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	extract_cache(char **newline, char **cache, char **line)
{
	*newline = NULL;
	if (*cache)
	{
		*newline = ft_strchr(*cache, '\n');
		if (*newline)
		{
			**newline = '\0';
			*newline += 1;
			*line = ft_strdup(*cache);
			ft_strcpy(*cache, *newline);
		}
		else
		{
			*line = ft_strdup(*cache);
			ft_strclr(*cache);
		}
	}
	else
		*line = ft_strnew(1);
	if (*line == NULL)
			return (0);
	return (1);
}

static int	update_cache(char **newline, char **cache, char *buf)
{
	char	*tmp;

	*newline = ft_strchr(buf, '\n');
	if (*newline)
	{
		**newline = '\0';
		*newline += 1;
		tmp = *cache;
		*cache = ft_strdup(*newline);
		free(tmp);
		if (*cache == NULL)
			return (0);
	}
	return (1);
}

static int	join_free(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free (tmp);
	if (!*line)
		return (0);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*cache[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	char		*newline;

	if (fd < 0 || !line || fd >= MAX_FD)
		return (-1);
	ret = extract_cache(&newline, &cache[fd], line);
	if (!ret)
		return (-1);
	while (ret && !newline)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (!(update_cache(&newline, &cache[fd], buf)))
			return (-1);
		if (!(join_free(line, buf)))
			return (-1);
	}
	if (ret || ft_strlen(*line))
		return (1);
	free(*line);
	return (0);
}
