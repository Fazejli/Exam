#include "stdlib.h"

void	make_arr(char *res, char *str, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (str[i] == ' ')
			break ;
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return ;
}

int		count_char(char *str, int nbr)
{
	int	len;

	len = 0;
	while (str[nbr])
	{
		if (str[nbr] && str[nbr] != ' ')
			len++;
		if (!str[nbr] || str[nbr] == ' ')
			break ;
		nbr++;
	}
	return (len);
}

int		count_space(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

char **ft_split(char *str)
{
	int	i;
	int	index;
	int	len;
	int	count;
	char **res;

	i = 0;
	index = 0;
	if (!str[i])
		return (NULL);
	count = count_space(str);
	res = malloc(sizeof(char*) * count + 1);
	if (!res)
		return (NULL);
	while (index < count)
	{
		while (str[i] == ' ')
			i++;
		len = count_char(str, i);
		res[index] = malloc(sizeof(char) * len + 1);
		if (!res[index])
		{
			index = 0;
			while (index < count)
				free(res[index++]);
			free(res);
			return (NULL);
		}
		make_arr(res[index], str + i, len);
		i = i + len;
		index++;
	}
	res[index] = NULL;
	return (res);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**result;
	int		i;
	(void)ac;

	result = ft_split(av[1]);
	if (!result)
	{
		printf("Erreur : ft_split a retourné NULL\n");
		return (1);
	}
	i = 0;
	while (result[i])
	{
		printf("mot[%d] = \"%s\"\n", i, result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return(0);
}*/
