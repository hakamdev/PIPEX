/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:37:19 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/24 00:05:54 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*ss;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ss = malloc(len1 + len2 + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
	{
		*(ss + i) = *((char *)(s1 + i));
		i++;
	}
	while (j < len2)
		*(ss + i++) = *((char *)(s2 + j++));
	*(ss + i) = CNULL;
	return (ss);
}
