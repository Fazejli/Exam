#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str, int start, int end)
{
	write(1, " ", 1);
	while (str[start] && start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

void	ft_write(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
		{
			if (str[i + 1] && str[i + 1] != ' ')
				write(1, " ", 1);
			i++;
		}
		if (!str[i])
			return ;
		write(1, &str[i], 1);
		i++;
	}
}

int	count_first(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
			i++;
		if (str[i] == ' ' || !str[i])
			break ;
	}
	return (i);
}

int	main(int ac, char **av)
{
	int		end;
	int		start;
	char	*res;

	if (ac >= 2)
	{
		start = 0;
		end = count_first(av[1]);
		while (av[1][start] && av[1][start] == ' ')
			start++;
		ft_write(av[1] + end);
		ft_putstr(av[1], start, end - 1);
	}
	write(1, "\n", 1);
	return (0);
}