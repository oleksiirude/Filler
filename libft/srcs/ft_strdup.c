/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:34:14 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/18 13:49:27 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = -1;
	while (++i <= len)
		s2[i] = s1[i];
	s2[i] = 0;
	return (s2);
}
