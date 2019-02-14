/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:09:27 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/06 17:24:46 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char *s11;
	const unsigned char *s22;

	i = 0;
	s11 = (const unsigned char*)s1;
	s22 = (const unsigned char*)s2;
	while ((s11[i] || s22[i]) && n)
	{
		if (s11[i] == s22[i])
			i++;
		else
			return (s11[i] - s22[i]);
		n--;
	}
	return (0);
}
