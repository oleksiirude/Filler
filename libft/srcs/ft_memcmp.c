/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:24:05 by olrudenk          #+#    #+#             */
/*   Updated: 2018/10/30 15:06:33 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		if (((const unsigned char*)s1)[i] ==
				(((const unsigned char*)s2)[i]))
			i++;
		else
			return (((const unsigned char*)s1)[i] -
					(((const unsigned char*)s2)[i]));
	}
	return (0);
}
