/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:21:28 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/23 22:42:47 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	i;
	void			*obj;

	i = 0;
	if (!(obj = malloc(count * size)))
		return (INULL);
	while (i < (count * size))
		*((unsigned char *)obj + i++) = CNULL;
	return (obj);
}
