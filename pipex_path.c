/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:39:17 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/13 20:34:53 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	is_path(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		if (cmd[i] == '/')
			return (true);
	return (false);
}

int	get_path_num(char *path_str)
{
	int	i;
	int	num;

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
	int			i;
	int			j;
	char		*out;
	const int	len = ft_strlen(path) + ft_strlen(cmd) + 2;

	i = 0;
	j = 0;
	out = (char *)malloc(len * sizeof(char));
	if (!out)
		exit(1);
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

char	*get_path(char *path_str, char *cmd, int *start, int end)
{
	char	*path;

	path = ft_substr2(path_str, *start, end);
	if (path != NULL)
		path = append_cmd_to_path(path, cmd);
	else
		path = append_cmd_to_path(ft_strdup("."), cmd);
	*start = end + 1;
	return (path);
}

char	**get_paths(char *path_str, char *cmd)
{
	char	**paths;
	int		end;
	int		start;
	int		count;

	count = 0;
	end = -1;
	start = 0;
	paths = malloc(sizeof(char *) * get_path_num(path_str));
	if (!paths)
		exit(1);
	if (path_str != NULL && path_str[0] != '\0')
	{
		while (path_str[++end])
			if (path_str[end] == ':')
				paths[count++] = get_path(path_str, cmd, &start, end);
		paths[count++] = get_path(path_str, cmd, &start, end);
	}
	else
		paths[count++] = append_cmd_to_path(ft_strdup("."), cmd);
	paths[count] = NULL;
	return (paths);
}
