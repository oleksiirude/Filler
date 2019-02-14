/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:24:51 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/02 15:29:45 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = ((unsigned char*)s);
	while (n--)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
