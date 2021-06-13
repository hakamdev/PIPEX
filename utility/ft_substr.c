/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:33:49 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/13 20:39:59 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

char	*ft_substr2(char *str, int from, int to)
{
	int		i;
	int		len;
	char	*sub;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (from < 0 || from >= to || from >= len || to > len)
		return (NULL);
	sub = (char *)malloc((to - from + 1) * sizeof(char));
	if (!sub)
		exit(1);
	while (from < to)
		sub[i++] = str[from++];
	sub[i] = '\0';
	return (sub);
}
