/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:36:18 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/13 17:36:31 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int		p_error(char *arg, char *message, int code)
{
	write(2, "pipex: ", 7);
	if (arg)
	{
		write(2, arg, ft_strlen(arg));
		write(2, ": ", 2);
	}
	if (message)
		write(2, message, ft_strlen(message));
	else
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (code);
}