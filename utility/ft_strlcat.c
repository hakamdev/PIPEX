/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:40:39 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/27 17:11:36 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int				i;
	int				k;
	int				lens;
	int				lend;

	i = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	k = (size - lend - 1);
	if (k >= 0)
	{
		dst += lend;
		while (i < k && src[i])
			*dst++ = src[i++];
		*dst = CNULL;
		return (lens + lend);
	}
	return (lens + size);
}
