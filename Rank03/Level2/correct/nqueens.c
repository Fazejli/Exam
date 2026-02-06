#include "n_queens.h"

int	is_safe(int *position, int current_row, int current_col)
{
    int prev_col;
    int prev_row;

    prev_col = 0;
    while (prev_col < current_col)
    {
        prev_row = position[prev_col];
        if (prev_row == current_row)
            return (0);
        if (prev_col + prev_row == current_col + current_row)
            return (0);
        if (prev_col - prev_row == current_col - current_row)
            return (0);
        prev_col++;
    }
    return (1);
}
void	solve(int *position, int col, int i)
{
    int row;
    int j;
    
    row = 0;
    if (i == col) // toutes les col sont remplies
    {
        j = 0;
        while (j < i)
        {
            if (j > 0)
                fprintf(stdout, " ");
            fprintf(stdout, "%d", position[j]);
            j++;
        }
        fprintf(stdout, "\n");
        return ;
    }
    while (row < i) //essayer ligne par ligne 
    {
        if (is_safe(position, row, col))
        {
            position[col] = row;
            solve(position, col + 1, i);
        }
        row++;
    }
}

int	main(int ac, char **av)
{
    int n;
    int *ptr;

    if (ac != 2)
        return (1);
    n = atoi(av[1]);
    if (n == 0)
        return (0);
    if (n == 2 || n == 3)
        return (fprintf(stderr, "\n"), 1);
    ptr = malloc(sizeof(int) * n);
    if (!ptr)
        return (1);
    solve(ptr, 0, n);
    free(ptr);
    return (0);
}