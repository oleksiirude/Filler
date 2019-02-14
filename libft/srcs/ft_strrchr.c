/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:53:22 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/11 14:13:47 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t k;

	i = -1;
	k = 0;
	while (s[++i])
		if (s[i] == c)
			k = i;
	if (s[k] == c)
		return ((&((char*)s)[k]));
	if (s[i] == c)
		return (&((char*)s)[i]);
	return (NULL);
}
