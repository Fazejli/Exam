/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:16:50 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/20 14:37:13 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*tmp;
int	tmp_size;

void	print_subset()
{
	int	i;

	i = 0;
	while (i < tmp_size)
	{
		printf("%d", tmp[i]);
		if (i < tmp_size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	find_subset(int *ptr, int nbr, int size, int index, int sum)
{
	int	i;

	if (sum == nbr)
	{
		print_subset();
		return ;
	}
	i = index;
	while (i < size)
	{
		tmp[tmp_size] = ptr[i];
		tmp_size++;
		find_subset(ptr, nbr, size, i + 1, sum + ptr[i]);
		tmp_size--;
		i++;
	}
}


int		main(int ac, char **av)
{
	int	nbr;
	int	*ptr;
	int	size;
	int	i;

	if (ac < 3)
		return (1);
	i = 0;
	size = ac - 2;
	nbr = atoi(av[1]);
	if (size == 0 && nbr != 0)
		return (printf("\n"), 0);
	ptr = malloc(sizeof(int) * size);
	if (!ptr)
		return (1);
	while (i < size)
	{
		ptr[i] = atoi(av[i + 2]);
		i++;
	}
	tmp_size = 0;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (free(ptr), 1);
	find_subset(ptr, nbr, size, 0, 0);
	free(tmp);
	free(ptr);
	return (0);
}
