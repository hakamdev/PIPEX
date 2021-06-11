/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:18:45 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/01 16:33:44 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bingo(const char *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static char	*alloc_cpy(const char *from, char *to, size_t start, size_t end)
{
	int		i;

	i = 0;
	if (start >= end)
	{
		if (!(to = malloc(1)))
			return (NULL);
	}
	else
	{
		if (!(to = malloc(end - start + 2)))
			return (NULL);
		while (start <= end)
			to[i++] = from[start++];
	}
	to[i] = CNULL;
	return (to);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	char	*ss;
	int		start;
	int		end;
	int		i;

	i = 0;
	if (!set)
		return (ft_strdup(s1));
	if (!s1 || *s1 == CNULL)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (bingo(set, s1[start]) && s1[start])
		start++;
	while (bingo(set, s1[end]) && end > 0)
		end--;
	ss = NULL;
	return (alloc_cpy(s1, ss, start, end));
}
