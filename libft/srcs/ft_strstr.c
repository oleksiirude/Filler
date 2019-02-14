/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:16:34 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/05 12:58:06 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t k;
	size_t buf;
	size_t count;

	if (!*needle || !(ft_strcmp(haystack, needle)))
		return ((char*)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	i = 0;
	count = 0;
	while (haystack[i])
	{
		k = 0;
		buf = i;
		while (haystack[i++] == needle[k++])
			if (!needle[k])
				return (&((char*)haystack)[buf]);
		i = count++;
	}
	return (NULL);
}
