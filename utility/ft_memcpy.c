/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:45 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/04 22:31:58 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*sc;
	unsigned char	*dst;

	i = 0;
	sc = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if ((dst == NULL && src == NULL) || n == 0)
		return (dst);
	if (sc == dst)
		return (dst);
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dst);
}
