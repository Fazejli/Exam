/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:15:58 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/21 14:16:03 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	sort_str(char *str)
{
	int	i = 0;
	int	j = 0;
	char temp;

	if (ft_strlen(str) == 0)
		return ;
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	permut(char *str, char *perm, int *used, int index, int len)
{
	int	i = 0;

	if (index == len)
	{
		perm[len] = '\0';
		puts(perm);
		return ;
	}
	while (i < len)
	{
		if (!used[i])
		{
			used[i] = 1;
			perm[index] = str[i];
			permut(str, perm, used, index + 1, len);
			used[i] = 0;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	len;
	char	perm[100];
	int		used[100];

	if (ac != 2 || (ac == 2 && !av[1]))
		return (1);
	len = ft_strlen(av[1]);
	for(int i = 0; i < len; i++)
		used[i] = 0;
	sort_str(av[1]);
	permut(av[1], perm, used, 0, len);
	return (0);
}
