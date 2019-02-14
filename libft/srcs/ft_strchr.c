/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:32:41 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/02 16:05:16 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s == (char)c)
			return ((char*)s);
		else
			s++;
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
