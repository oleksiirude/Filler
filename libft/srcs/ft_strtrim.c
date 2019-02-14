/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:10:48 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/08 20:46:52 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_checker(char const *s)
{
	if (*s == ' ' || *s == '\t' || *s == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*ww;

	if (!s)
		return (NULL);
	if (!*s)
		return (ww = ft_strdup(""));
	len = ft_strlen(s) - 1;
	i = 0;
	while (ft_checker(&s[i]))
		i++;
	while (ft_checker(&s[len]) && len)
		len--;
	if (i > len)
		return (ww = ft_strdup(""));
	return (ww = ft_strsub(s, i, len - (i - 1)));
}
