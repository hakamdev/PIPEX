/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:43:04 by ehakam            #+#    #+#             */
/*   Updated: 2021/06/13 18:14:57 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <err.h>
# include <errno.h>
# include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr2(char *str, int from, int to);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);

int		p_error(char *arg, char *message, int code);

#endif
