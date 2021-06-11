/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:10:53 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/11 21:14:03 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <err.h>
# include <errno.h>
# include "utility/utility.h"

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

#endif