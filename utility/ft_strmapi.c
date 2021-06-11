/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:35:52 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/24 16:06:48 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ss;
	char			*out;

	i = 0;
	ss = (char *)s;
	if (s == NULL)
		return (NULL);
	if (!(out = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (i < ft_strlen(ss))
	{
		out[i] = f(i, ss[i]);
		i++;
	}
	out[i] = CNULL;
	return (out);
}
