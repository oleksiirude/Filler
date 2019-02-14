/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:09:27 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/06 17:07:56 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char *s11;
	const unsigned char *s22;

	i = 0;
	s11 = (const unsigned char*)s1;
	s22 = (const unsigned char*)s2;
	while (s11[i] || s22[i])
		if (s11[i] == s22[i])
			i++;
		else
			return (s11[i] - s22[i]);
	return (0);
}
