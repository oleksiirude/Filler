/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:14:53 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/08 16:21:23 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_filler2arr(char **str, char const *s, char c, size_t i)
{
	size_t p;
	size_t k;
	size_t st;

	k = 0;
	p = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		st = i;
		while (s[i] != c && s[i] && ++k)
			i++;
		if (!(str[p] = (char*)ft_memalloc(k)))
			return (NULL);
		k = 0;
		while (s[st] != c && s[st])
			str[p][k++] = s[st++];
		str[p++][k] = 0;
		k = 0;
	}
	str[p] = NULL;
	return (str);
}

static char	**ft_create2arr(char **str, char const *s, char c, size_t i)
{
	size_t lns;

	lns = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			lns++;
		while (s[i] != c && s[i])
			i++;
	}
	if (!(str = (char**)ft_memalloc(sizeof(char*) * (lns + 1))))
		return (NULL);
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**str;

	i = 0;
	str = NULL;
	if (!s)
		return (NULL);
	if (!(str = ft_create2arr(str, s, c, i)))
		return (NULL);
	if (!(str = ft_filler2arr(str, s, c, i)))
		return (NULL);
	return (str);
}
