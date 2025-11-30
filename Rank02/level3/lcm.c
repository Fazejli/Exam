/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:05:41 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/13 15:17:53 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int max;

	if (a > b)
		max = a;
	else
		max = b;
	if (a == 0 || b == 0)
		return (0);
	while (max > 0)
	{
		if (max % a == 0 && max % b == 0)
			return (max);
		max++;
	}
}

#include <stdio.h>
int main() {
    int n1, n2;
    printf("Entrez deux nombres : ");
    scanf("%d %d", &n1, &n2);

    printf("Le PPCM de %d et %d est %d\n", n1, n2, lcm(n1, n2));
    return 0;
}