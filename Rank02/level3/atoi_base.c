
int	is_base(char c, int baselen)
{
	if (baselen == 10)
	{
		if (c >= '0' && c <= '9')
			return (1);
		return (0);
	}
	else
	{
		if (c >= '0' && c <= '9')
			return (1);
		if (c >= 'a' && c < 'a' + (baselen - 10))
			return (1);
		if (c >= 'A' && c < 'A' + (baselen - 10))
			return (1);
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int sig;
	int	i;

	i = 0;
	res = 0;
	sig = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] && is_base(str[i], str_base) != 0)
	{
		res = res * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		i++;
	}
	return (res * sig);
}

#include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi_base("12fdb3", 16));
	return (0);
}