/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:06:15 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/24 16:06:24 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int		i;
	unsigned int		len;

	i = 0;
	if (!dst)
		return (0);
	len = ft_strlen((char *)(src));
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			*(dst + i) = *((unsigned char *)(src + i));
			i++;
		}
		*(dst + i) = CNULL;
	}
	return (len);
}
