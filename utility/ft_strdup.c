/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:40:43 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/24 00:05:12 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ss;
	size_t	st;

	st = ft_strlen(s);
	if (!(ss = (char *)malloc(st + 1)))
		return (NULL);
	ft_memcpy(ss, s, st);
	*(ss + st) = CNULL;
	return (ss);
}
