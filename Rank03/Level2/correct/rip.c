/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:17:57 by fadzejli          #+#    #+#             */
/*   Updated: 2026/02/04 17:24:02 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_SOLUTIONS 10
#define MAX_LEN 20

char solutions[MAX_SOLUTIONS][MAX_LEN];
int solution_count = 0;

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_strcpy(char *dst, char *src)
{
	int i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_args(char *line)
{
	int	i = 0;

	if (!line[i])
		return (1);
	while (line[i])
	{
		if (line[i] != '(' && line[i] != ')')
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
		else if (line[i] != ' ')  // Ignorer les espaces
			return (1);
		i++;
	}
	return (open + close);
}

int solution_exists(char *str)
{
	int i = 0;
	while (i < solution_count)
	{
		if (ft_strcmp(solutions[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

void add_solution(char *str)
{
	if (!solution_exists(str) && solution_count < MAX_SOLUTIONS)
	{
		ft_strcpy(solutions[solution_count], str);
		solution_count++;
	}
}

void	backtrack(char *str, int i, int to_rem, int removed)
{
	char	tmp;

	if (i == ft_strlen(str))
	{
		if (!is_valid(str) && to_rem == removed)
			add_solution(str);
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
	char copy[MAX_LEN];
	int i;
	
	solution_count = 0;
	if (ac != 2 || check_args(av[1]))
		return (1);
	if (!is_valid(av[1]))
	{
		puts(av[1]);
		return (0);
	}
	ft_strcpy(copy, av[1]);
	backtrack(copy, 0, is_valid(av[1]), 0);
	i = 0;
	while (i < solution_count)
	{
		puts(solutions[i]);
		i++;
	}
	
	return (0);
}