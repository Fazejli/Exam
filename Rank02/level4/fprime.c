/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:09:36 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/13 15:12:26 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	nbr;
	int	i;

	if (ac == 2)
	{
		nbr = atoi(av[1]);
		if (nbr == 1)
		{
			printf("1\n");
			return (0);
		}
		i = 2;
		if (nbr > 1)
		{
			while (i <= nbr)
			{
				if (nbr % i == 0)
				{
					printf("%d", i);
					nbr = nbr / i;
					if (nbr > 1)
						printf("*");
				}
				else
					i++;
			}
		}
	}
	printf("\n");
	return (0);
}
