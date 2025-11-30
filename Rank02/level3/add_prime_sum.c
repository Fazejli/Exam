#include <unistd.h>


int	is_prime(int nbr)
{
	int	i;

	i = 2;
	if (nbr < 2)
		return (0);
	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sig;

	i = 0;
	res = 0;
	sig = 1;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sig);
}

void	ft_putnbr(int nbr)
{
	char digit;

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	digit = nbr % 10 + 48;
	write(1, &digit, 1);
}

int	main(int ac, char **av)
{
	int nbr;
	int	sum;
	int	i;

	if (ac == 2)
	{
		sum = 0;
		i = 2;
		nbr = ft_atoi(av[1]);
		if (nbr > 0)
		{
			while (i <= nbr)
			{
				if (is_prime(i))
					sum += i;
				i++;
			}
			ft_putnbr(sum);
		}
	}
	write(1, "0\n", 1);
	return (0);
}
