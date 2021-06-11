/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:11:25 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/05 17:15:50 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrevcpy(char *dest, char *src, int n)
{
	while (n >= 0)
	{
		*((char *)dest + n) = *((char *)src + n);
		n--;
	}
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*sc;
	char	*dst;

	sc = (char *)src;
	dst = (char *)dest;
	if (((char *)dst == NULL && (char *)sc == NULL) || n == INULL)
		return (dst);
	if (dst < sc)
		ft_memcpy(dst, sc, n);
	else if (sc < dst)
		ft_memrevcpy(dst, sc, n - 1);
	return (dst);
}
