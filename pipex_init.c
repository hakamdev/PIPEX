/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:37:42 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/13 20:36:50 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_redir	*create_redir(t_type type, char *arg)
{
	t_redir	*r;

	r = malloc(sizeof(t_redir));
	if (!r)
		exit(1);
	r->arg = arg;
	r->type = type;
	return (r);
}

t_cmd	*create_cmd(char **av, int index)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		exit(1);
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
