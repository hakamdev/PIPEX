/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:12:41 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/13 20:31:43 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	g_status;

static void	handle_errors(t_cmd *cmd, t_bool ispath, int _errno)
{
	if (_errno == 13)
		exit(p_error(cmd->argv[0], NULL, 126));
	else if (_errno == 8)
		exit(p_error(cmd->argv[0], NULL, 1));
	else if (ispath || getenv("PATH") == NULL)
		exit(p_error(cmd->argv[0], NULL, 127));
	else
		exit(p_error(cmd->argv[0], "command not found", 127));
}

static void	exec_from_path(t_cmd *cmd, char **env)
{
	int		i;
	char	**paths;

	paths = get_paths(getenv("PATH"), cmd->argv[0]);
	i = -1;
	while (paths[++i])
	{
		execve(paths[i], cmd->argv, env);
		if (errno != 2)
			break ;
	}
}

static pid_t	execute(t_cmd *cmd, char **env, int fd[2], int index)
{
	int		i;
	pid_t	pid;
	char	**paths;

	pid = fork();
	if (pid < 0)
		exit(p_error(NULL, NULL, 1));
	if (pid == 0)
	{
		set_pipe(fd, index);
		if (cmd->redir != NULL)
			set_redirection(cmd->redir);
		if (is_path(cmd->argv[0]))
			execve(cmd->argv[0], cmd->argv, env);
		else
			exec_from_path(cmd, env);
		handle_errors(cmd, false, errno);
	}
	return (pid);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid[2];
	t_cmd	*cmd1;
	t_cmd	*cmd2;

	if (ac != 5)
		return (1);
	cmd1 = create_cmd(av, 0);
	cmd2 = create_cmd(av, 1);
	if (pipe(fd) < 0)
		exit(p_error(NULL, NULL, 1));
	pid[0] = execute(cmd1, env, fd, 0);
	pid[1] = execute(cmd2, env, fd, 1);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], &g_status, 0);
	waitpid(pid[1], &g_status, 0);
	return (WEXITSTATUS(g_status));
}
