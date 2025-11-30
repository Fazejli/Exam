#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_write(char *str, int start, int end)
{
	int	i;

	i = start;
	while (str[i] && i <= end)
	{
		while (str[i] == ' ')
		{
			if (str[i + 1] && str[i + 1] != ' ')
				write(1, " ", 1);
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
}


int	main(int ac, char **av)
{
	int	i;
	int	len;

	if (ac == 2)
	{
		i = 0;
		len = ft_strlen(av[1]) - 1;
		while (av[1][i] == ' ')
			i++;
		while (av[1][len] == ' ')
			len--;
		ft_write(av[1], i, len);
	}
	write(1, "\n", 1);
	return (0);
}