/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:33:49 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/24 16:09:40 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	lens;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	lens = ft_strlen(s);
	if (start > lens)
		len = 0;
	if (!(ss = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len && start < lens)
		*(ss + i++) = *(s + start++);
	*(ss + i) = CNULL;
	return (ss);
}
