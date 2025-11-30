/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:44:11 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/18 15:15:50 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static int	buff_pos = 0;
	static int	char_read = 0;
	static char	buffer[BUFFER_SIZE];
	char		line[1000000];
	int			i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buff_pos >= char_read)
		{
			char_read = read(fd, buffer, BUFFER_SIZE);
			buff_pos = 0;
			if (char_read == 0)
				break ;
		}
		line[i++] = buffer[buff_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}
/*
int	main(int ac, char **av)
{
	int fd;
	char *line;

	if (ac != 2)
	{
		printf("%s\n", "Check your args");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		else
			break ;
		free(line);
	}
	close(fd);
	return (0);
}*/
