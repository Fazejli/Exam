/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:17:57 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/20 17:29:07 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_args(char *line)
{
	int	i = 0;

	if (!line[i])
		return (1);
	while (line[i])
	{
		if (line[i] != '(' && line[i] != ')' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(char *line)
{
	int	i = 0;
	int open = 0;
	int close = 0;

	while (line[i])
	{
		if (line[i] == '(')
			open++;
		else if (line[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}

void	backtrack(char *str, int i, int to_rem, int removed)
{
	char	tmp;

	if (i == ft_strlen(str))
	{
		if (!is_valid(str) && to_rem == removed)
			puts(str);
		return ;
	}
	if (removed > to_rem)
		return ;
	if (str[i] == '(' || str[i] == ')')
	{
		tmp = str[i];
		str[i] = ' ';
		backtrack(str, i + 1, to_rem, removed + 1);
		str[i] = tmp;
		backtrack(str, i + 1, to_rem, removed);
	}
	else
		backtrack(str, i + 1, to_rem, removed);
}

int	main(int ac, char **av)
{
	if (ac != 2 || check_args(av[1]))
		return (1);
	if (!is_valid(av[1]))
	{
		puts(av[1]);
		return (0);
	}
	backtrack(av[1], 0, is_valid(av[1]), 0);
	return (0);
}