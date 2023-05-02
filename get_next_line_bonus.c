/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:07:52 by eguler            #+#    #+#             */
/*   Updated: 2022/02/02 12:19:26 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *read_fr_fd, int fd)
{
	int		readbytes;
	char	*buff;

	readbytes = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(read_fr_fd, '\n') && readbytes != 0)
	{
		readbytes = read(fd, buff, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readbytes] = '\0';
		read_fr_fd = ft_strjoin(read_fr_fd, buff);
	}
	free(buff);
	return (read_fr_fd);
}

char	*del_line(char *read_fr_fd)
{
	int		i;
	int		j;
	char	*left_data;

	i = 0;
	while (read_fr_fd[i] != '\n' && read_fr_fd[i])
		i++;
	if (!read_fr_fd[i])
	{
		free(read_fr_fd);
		return (NULL);
	}
	left_data = (char *)malloc(sizeof(char) * (ft_strlen(read_fr_fd) - i + 1));
	i++;
	j = 0;
	while (read_fr_fd[i] != '\0')
	{
		left_data[j] = read_fr_fd[i];
		i++;
		j++;
	}
	left_data[j] = '\0';
	free(read_fr_fd);
	return (left_data);
}

char	*get_line(char *read_fr_fd)
{
	int		i;
	char	*newline;

	i = 0;
	if (!read_fr_fd[i])
		return (NULL);
	while (read_fr_fd[i] != '\n' && read_fr_fd[i])
		i++;
	newline = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (read_fr_fd[i] != '\n' && read_fr_fd[i])
	{
		newline[i] = read_fr_fd[i];
		i++;
	}
	if (read_fr_fd[i] == '\n')
	{
		newline[i] = '\n';
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*read_fr_fd[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_fr_fd[fd] = ft_read(read_fr_fd[fd], fd);
	if (!read_fr_fd[fd])
		return (NULL);
	line = get_line(read_fr_fd[fd]);
	read_fr_fd[fd] = del_line(read_fr_fd[fd]);
	return (line);
}
/*
int main()
{
	int		fd;
	char	*line;
	int i;
	fd = open("selam.txt", O_RDONLY);
	i = 1;
	while(i <= 1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
}
*/
