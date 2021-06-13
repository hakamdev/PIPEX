/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:40:43 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/13 17:27:52 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		st;
	char	*ss;

	st = ft_strlen(s);
	ss = (char *)malloc(st + 1);
	if (!ss)
		exit(1);
	i = -1;
	while (s[++i])
		ss[i] = s[i];
	ss[i] = '\0';
	return (ss);
}
