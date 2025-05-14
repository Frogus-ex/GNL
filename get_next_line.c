/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:52:31 by tlorette          #+#    #+#             */
/*   Updated: 2025/05/14 16:20:45 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free (text);
	free (temp);
}

char	*store_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		i++;
	}
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*ft_read_line(int fd, char *line)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	if (!line)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (line);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		line = ft_join_free(line, buffer);
		if (strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	if (!fd)
		return (NULL);
}
