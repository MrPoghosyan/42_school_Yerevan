#include "pipex_bonus.h"

void    init_paths(t_pipex *pipex, char **envp)
{
    int     i;
    char    *path_line;

    i = 0;
    while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
        i++;
    if (!envp[i])
    {
        pipex->paths = NULL;
        return ;
    }
    path_line = envp[i] + 5;
    pipex->paths = ft_split(path_line, ':');
}

void    init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
    pipex->here_doc = 0;
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
        if (argc < 6)
            error_exit("Invalid number of arguments", 1);
        pipex->here_doc = 1;
        pipex->limiter = argv[2];
        here_doc(pipex);
    }
    else
    {
        pipex->in_fd = open(argv[1], O_RDONLY);
        if (pipex->in_fd < 0)
            error_exit("Input file error", 1);
    }
    pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pipex->out_fd < 0)
        error_exit("Output file error", 1);
    init_paths(pipex, envp);
}

void    exec_cmd(t_pipex *pipex, char *cmd, char **envp)
{
    char    *path;
    char    **args;

    if (!ft_strchr(cmd, '\'') && !ft_strchr(cmd, '\"'))
    {
    args = ft_split(cmd, ' ');
    if (!args)
        error_exit("Command split error", 1);
    
    path = get_cmd_path(args[0], pipex->paths);
    if (!path)
    {
        free_array(args);
        error_exit("Command not found", 127);
    }
    
    if (execve(path, args, envp) == -1)
    {
        free(path);
        free_array(args);
        error_exit("Execve error", 1);
    }
    }
    else
        exec_command(cmd, envp);
}

void    pipe_handler(t_pipex *pipex, int argc, char **argv, char **envp)
{
    int i;

    i = 2 + pipex->here_doc;
    while (i < argc - 2)
    {
        if (pipe(pipex->pipe_fd) < 0)
            error_exit("Pipe error", 1);
        
        pipex->pid = fork();
        if (pipex->pid < 0)
            error_exit("Fork error", 1);
        
        if (pipex->pid == 0)
        {
            close(pipex->pipe_fd[READ_END]);
            dup2(pipex->in_fd, STDIN_FILENO);
            dup2(pipex->pipe_fd[WRITE_END], STDOUT_FILENO);
            exec_cmd(pipex, argv[i], envp);
        }
        else
        {
            close(pipex->pipe_fd[WRITE_END]);
            close(pipex->in_fd);
            pipex->in_fd = pipex->pipe_fd[READ_END];
            i++;
        }
    }
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;

    if (argc < 5)
        error_exit("Usage: ./pipex <infile> <cmd1> <cmd2> ... <outfile>\n"
                  "Or: ./pipex here_doc <LIMITER> <cmd1> <cmd2> ... <outfile>", 1);
    
    ft_memset(&pipex, 0, sizeof(t_pipex));
    init_pipex(&pipex, argc, argv, envp);
    pipe_handler(&pipex, argc, argv, envp);
    
    // Last command
    pipex.pid = fork();
    if (pipex.pid < 0)
        error_exit("Fork error", 1);
    
    if (pipex.pid == 0)
    {
        dup2(pipex.in_fd, STDIN_FILENO);
        dup2(pipex.out_fd, STDOUT_FILENO);
        exec_cmd(&pipex, argv[argc - 2], envp);
    }
    
    close_fds(&pipex);
    waitpid(pipex.pid, NULL, 0);
    free_array(pipex.paths);
    return (0);
}
