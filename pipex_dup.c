/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:38:32 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/13 17:38:51 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		set_pipe(int fd[2], int index)
{
	if (index == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
	}
	else if (index == 1)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
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
	{
		exit(p_error(redir->arg, NULL, 1));
		// TODO: Handle permission denied and File Doesn't exist
	}
	if (redir->type == left)
		dup2(fd, 0);
	else if (redir->type == right)
		dup2(fd, 1);
	free(redir);
	return (0);
}
