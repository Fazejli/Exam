#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int    mess_error(char *str)
{
    if (str)
        fprintf(stderr, "Error: %s\n", str);
    else
        perror("Error: ");
    return (1);
}

int ft_strncmp(char *s1, char *s2, int len)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i] && i != len - 1)
        i++;
    return (s1[i] - s2[i]);
}

void    filter(char *set, char *line)
{
    int i = 0;
    int j = 0;
    int len;

    len = strlen(set);
    while (line[i])
    {
        if (!ft_strncmp(set, &line[i], len))
        {
            j = 0;
            while (j < len)
            {
                write(1, "*", 1);
                i++;
                j++;
            }
        }
        else
        {
            write(1, &line[i], 1);
            i++;
        }
    }
}

int main(int ac, char **av)
{
    int temp;
    char buffer[101];

    if (ac != 2 || (ac == 2 && !av[1]))
        return (mess_error("Incorrect usage."));
    temp = read(0, buffer, 100);
    if (temp < 0)
        return (mess_error(NULL));
    else
    {
        buffer[temp] = '\0';
        filter(av[1], buffer);
    }
    return (0);
}