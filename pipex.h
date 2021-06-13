/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:10:53 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/13 19:43:12 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "utility/utility.h"
# include <err.h>
# include <errno.h>

typedef	enum e_bool
{
	false = 0,
	true = 1
}				t_bool;

typedef	enum e_type
{
	left = 0,
	right = 1
}				t_type;

typedef	struct s_redir
{
	t_type	type;
	char	*arg;
}				t_redir;

typedef struct s_cmd
{
	char	**argv;
	int		argc;
	t_redir	*redir;
}				t_cmd;

int		set_pipe(int fd[2], int index);
int		set_redirection(t_redir *redir);

t_redir *create_redir(t_type type, char *arg);
t_cmd	*create_cmd(char **av, int index);

t_bool	is_path(char *cmd);
int		get_path_num(char *path_str);
char	**get_paths(char *path_str, char *cmd);
char	*append_cmd_to_path(char *path, char *cmd);
char	*get_path(char *path_str, char *cmd, int *start, int end);

#endif