#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sig;
	int	res;

	i = 0;
	sig = 1;
	res = 0;
	if (str[0] == '-')
	{
		sig = -1;
		i = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sig * res);
}

void	print_hex(int nbr)
{
	char *digit;

	digit = "0123456789abcdef";
	if (nbr >= 16)
		print_hex(nbr / 16);
	write(1, &digit[nbr % 16], 1);
}

int	main(int ac, char **av)
{

	int		nbr;

	if (ac == 2)
	{
		nbr = ft_atoi(av[1]);
		if (nbr >= 1)
			print_hex(nbr);
	}
	write(1, "\n", 1);
	return (0);
}