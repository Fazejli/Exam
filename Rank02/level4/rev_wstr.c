#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int start, int end)
{
	while (str[start] && start <= end)
	{
		if (str[start] == ' ')
			start++;
		write(1, &str[start], 1);
		start++;
	}
}

void	rev_wstr(char *str, int words)
{
	int	index;
	int	start;
	int	end;

	end = ft_strlen(str) - 1;
	while (str[end] && words > 0)
	{
		if (end >= 0 && str[end] == ' ')
			end--;
		start = end;
		while (start > 0 && str[start] != ' ')
			start--;
		ft_putstr(str, start, end);
		words--;
		if (words >= 1)
			write(1, " ", 1);
		end = start;
	}
}

int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1])
			count++;
		else if (str[i] != ' ' && !str[i + 1])
			count++;
		i++;
	}
	return (count);
}


int	main(int ac, char **av)
{
	int	words;

	if (ac == 2)
	{
		words = count_words(av[1]);
		if (words > 0)
			rev_wstr(av[1], words);
	}
	write(1, "\n", 1);
	return (0);
}