/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viacheslav <viacheslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:51:39 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/05/06 16:19:51 by vtrofyme       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char **buff_read, char **line)
{
	size_t	i;
	char	*new_buff;

	i = 0;
	new_buff = NULL;
	while ((*(*buff_read + i) != '\n') && (*(*buff_read + i) != '\0'))
		i++;
	if (*(*buff_read + i) == '\n')
	{
		i++;
		*line = ft_substr(*buff_read, 0, i);
		new_buff = ft_strdup(*buff_read + i);
	}
	else
		*line = ft_strdup(*buff_read);
	free(*buff_read);
	*buff_read = NULL;
	return (new_buff);
}

ssize_t	read_file(int fd, char **buffer, char **buff_read, char **line)
{
	char	*temp;
	ssize_t	n;

	n = 1;
	while (!ft_strchr(*buff_read, '\n') && n)
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[n] = '\0';
		temp = *buff_read;
		*buff_read = ft_strjoin(temp, *buffer);
		free(temp);
	}
	free(*buffer);
	*buffer = NULL;
	*buff_read = get_line(buff_read, line);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (n);
}

int	free_static_var(int fd, char **buff_read)
{
	if (fd == -5)
	{
		if (*buff_read)
		{
			free(*buff_read);
			*buff_read = NULL;
		}
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*buff_read;
	char			*buffer;
	char			*line;
	ssize_t			n;

	if (free_static_var(fd, &buff_read))
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buff_read)
		buff_read = ft_strdup("");
	n = read_file(fd, &buffer, &buff_read, &line);
	if (n == 0 && !line)
		return (NULL);
	return (line);
}
