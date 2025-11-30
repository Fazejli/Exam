/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:40:13 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/17 14:28:03 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

void	mess_error(void)
{
	perror("Error: ");
	exit(1);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i != n - 1)
		i++;
	return (s1[i] - s2[i]);
}

void	filter(char *dest, char *src)
{
	int	i;
	int	j;
	int	len;

	len = strlen(src);
	i = 0;
	while (dest[i])
	{
		if (ft_strncmp(src, &dest[i], len) == 0)
		{
			j = 0;
			while (j != len)
			{
				write(1, "*", 1);
				i++;
				j++;
			}
		}
		else
		{
			write(1, &dest[i], 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	char	*new;
	char	buffer[100];
	int		temp;

	if (ac != 2 || (ac == 2 && !av[1]))
		mess_error();
	temp = 1;
	while (temp > 0)
	{
		temp = read(0, buffer, 100);
		if (temp < 0)
			return (mess_error(), 1);
		new = malloc(sizeof(char) * temp + 1);
		if (!new)
		{
			free(new);
			return (mess_error(), 1);
		}
		new = buffer;
		new[100] = '\0';
	}
	if (new)
		filter(new, av[1]);
	return (0);
}
