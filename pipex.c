/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:12:41 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/11 21:47:43 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_substr2(char *str, int from, int to)
{
	int i;
	int len;
	char *sub;

	i = 0;
	if (!str)
		return (NULL);
	len = strlen(str);
	if (from < 0 || from >= to || from >= len || to > len)
		return (NULL);
	sub = (char *)malloc((to - from + 1) * sizeof(char));
	while (from < to)
		sub[i++] = str[from++];
	sub[i] = '\0';
	return (sub);
}

t_redir *create_redir(t_type type, char *arg)
{
	t_redir *r = malloc(sizeof(t_redir));
	if (!r)
		exit(1000000); // TODO: EMALLOC
	r->arg = arg;
	r->type = type;
	return (r);
}

t_cmd	*create_cmd(char **av, int index)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		exit(10000); // TODO: EMALLOC
	
	if (index == 0)
		cmd->argv = ft_split(av[2], ' ');
	else if (index == 1)
		cmd->argv = ft_split(av[3], ' ');
	if (index == 0)
		cmd->redir = create_redir(left, av[1]);
	else if (index == 1)
		cmd->redir = create_redir(right, av[4]);
	return (cmd);
}

int		set_pipe(int fd[2], int index)
{
	if (index == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
	}
	else if (index == 1)
	{
		dup2(fd[0], 0);
		close(fd[1]);
	}
	return (0);
}

int		set_redirection(t_redir *redir)
{
	int		fd;
	
	if (redir->type == left)
		fd = open(redir->arg, O_RDONLY);
	else if (redir->type == right)
		fd = open(redir->arg, O_CREAT | O_TRUNC | O_WRONLY,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		exit(100000); // TODO: Handle permission denied and File Doesn't exist
	if (redir->type == left)
		dup2(fd, 0);
	else if (redir->type == right)
		dup2(fd, 1);
	free(redir);
	return (0);
}

t_bool	is_path(char *cmd) {
	int		i;

	i = -1;
	while (cmd[++i])
		if (cmd[i] == '/')
			return true;
	return (false);	
}

int		get_path_num(char *path_str)
{
	int		i;
	int		num;

	num = 5;
	if (!path_str)
		return (num);
	i = -1;
	while (path_str[++i])
	{
		if (path_str[i] == ':')
			num++;
	}
	return (num);
}

char	*append_cmd_to_path(char *path, char *cmd)
{
	int		i;
	int		j;
	char	*out;
	const	int len = strlen(path) + strlen(cmd) + 2;
	
	i = 0;
	j = 0;
	out = (char *)malloc(len * sizeof(char));
	while (path[i])
		out[j++] = path[i++];
	out[j++] = '/';
	i = 0;
	while (cmd[i])
		out[j++] = cmd[i++];
	out[j] = '\0';
	free(path);
	return (out);
}

char	**get_paths(char *path_str, char *cmd)
{
	char **paths;
	char *path;
	int end;
	int start;
	int	count;

	count = 0;
	end = -1;
	start = 0;
	paths = malloc(sizeof(char *) * get_path_num(path_str));
	if (!paths)
		exit(100000); // TODO: EMALLOC
	if (path_str != NULL && path_str[0] != '\0')
	{
		if (path_str[0] == ':')
			paths[count++] = append_cmd_to_path(strdup("."), cmd);
		while (path_str[++end])
		{
			if (path_str[end] == ':')
			{
				path = ft_substr2(path_str, start, end);
				if (path != NULL)
					paths[count++] = append_cmd_to_path(path, cmd);
				else
					paths[count++] = append_cmd_to_path(strdup("."), cmd);
				start = end + 1;
			}
		}
		path = ft_substr2(path_str, start, end);
		if (path != NULL)
			paths[count++] = append_cmd_to_path(path, cmd);
		else
			paths[count++] = append_cmd_to_path(strdup("."), cmd);
	}
	else
		paths[count++] = append_cmd_to_path(strdup("."), cmd);
	paths[count] = NULL;
	return (paths);
}

int		execute(t_cmd *cmd, char **env, int fd[2], int index)
{
	int		i;
	pid_t	pid;
	char	**paths;

	pid = fork();
	if (pid < 0)
		exit(1000000); // TODO: Fork failed
	if (pid == 0)
	{
		set_pipe(fd, index);
		if (cmd->redir != NULL)
			set_redirection(cmd->redir);
		if (is_path(cmd->argv[0]))
		{
			execve(cmd->argv[0], cmd->argv, env);
			exit(10000); // TODO: File not found or permission Denied
		}
		paths = get_paths(getenv("PATH"), cmd->argv[0]);
		i = -1;
		while (paths[++i])
			execve(paths[i], cmd->argv, env);
		exit(10000); // TODO: Command not found
	}
	return (pid);
}

int		main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid[2];
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	int		status;

	if (ac != 5)
		return (1);
	cmd1 = create_cmd(av, 0);
	cmd2 = create_cmd(av, 1);

	if (pipe(fd) < 0)
		exit(10000); // TODO: PIPE failed

	pid[0] = execute(cmd1, env, fd, 0);
	pid[1] = execute(cmd2, env, fd, 1);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], &status, WNOHANG);
	waitpid(pid[1], &status, WNOHANG);
	return (13);
}