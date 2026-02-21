#include "microshell.h"

void mess_error(char *str)
{
    while (*str)
        write(2, str++, 1);
}

int cd(char **av, int i)
{
    if (i != 2)
    {
        mess_error("error: cd: bad arguments\n");
        return (1);
    }
    if (chdir(av[1]) < 0)
    {
        mess_error("error: cd: cannot change directory to ");
        mess_error(av[1]);
        mess_error("\n");
        return (1);
    }
    return 0;
}
void set_pipe(int has_pipe, int *fd, int end)
{
    if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
    {
        mess_error("error: fatal\n");
        exit(1);
    }
}

int exec(char **av, int i, char **env)
{
    int has_pipe;
    int fd[2];
    int pid;
    int status;

    has_pipe = av[i] && !strcmp(av[i], "|");
    if (!has_pipe && !strcmp(*av, "cd"))
        return (cd(av, i));
    if (has_pipe && pipe(fd) == -1)
    {
        mess_error("error: fatal\n");
        exit(1);
    }
    if ((pid = fork()) == -1)
    {
        mess_error("error: fatal\n");
        exit(1);
    }
    if (!pid)
    {
        av[i] = 0;
        set_pipe(has_pipe, fd, 1);
        execve(*av, av, env);
        mess_error("error: can not execute\n");
        mess_error(*av);
        mess_error("\n");
        exit(1);
    }
    waitpid(pid, &status, 0);
    set_pipe(has_pipe, fd, 0);
    return(WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char **av, char **env)
{
    int i = 0;
    int status = 0;
    (void)ac;
    
    while (av[i])
    {
        av += i + 1;
        i = 0;
        while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
            i++;
        if (i)
            status = exec(av, i, env);
    }
    return (status);
}
