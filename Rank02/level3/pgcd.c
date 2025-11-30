#include <stdio.h>
#include <stdlib.h>

int	pgcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a =  a - b;
		else
			b = b - a;
	}
	return (a);
}

int	main(int ac, char **av)
{
	int	nbr1;
	int	nbr2;

	if (ac == 3)
	{
		nbr1 = atoi(av[1]);
		nbr2 = atoi(av[2]);
		if (nbr1 > 0 && nbr2 > 0)
			printf("%d", pgcd(nbr1, nbr2));
	}
	printf("\n");
	return (0);
}