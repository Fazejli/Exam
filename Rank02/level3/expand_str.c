#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_write(char *str, int start, int len)
{
	int	i;

	i = start;
	while (str[i] && i <= len)
	{
		while (str[i] == ' ')
		{
			if (str[i + 1] && str[i + 1] != ' ')
				write(1, "   ", 3);
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
}



int	main(int ac, char **av)
{
	int	len;
	int	i;

	i = 0;
	if (ac == 2)
	{
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