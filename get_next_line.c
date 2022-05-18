/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:21:37 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/30 15:16:18 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(char *tmp)
{
	unsigned int	i;
	unsigned int	j;
	char			*rest;

	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	j = 0;
	rest = (char *)malloc(sizeof(char) * (ft_strlen(tmp) - i));
	if (!rest)
		return (NULL);
	i++;
	while (tmp[i])
		rest[j++] = tmp[i++];
	rest[j] = '\0';
	free(tmp);
	return (rest);
}

char	*get_line(char *tmp)
{
	unsigned int	i;
	char			*line;

	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_buf(char *tmp, int fd)
{
	char		*buf;
	int			ret;
	long		taille_buf;

	taille_buf = BUFFER_SIZE;
	ret = 1;
	buf = malloc(sizeof(char) * (taille_buf + 1));
	if (!buf)
		return (NULL);
	while (ret != 0 && !ft_strchr(tmp, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1 || (ret == 0 && !*tmp))
		{
			free(tmp);
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		tmp = ft_gnl_strjoin(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!tmp)
		tmp = ft_strdup("");
	tmp = read_buf(tmp, fd);
	if (!tmp)
		return (NULL);
	line = get_line(tmp);
	tmp = get_rest(tmp);
	return (line);
}
