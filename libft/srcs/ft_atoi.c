/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 20:37:44 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/13 15:06:32 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		minus;
	size_t	res;

	res = 0;
	minus = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str)
	{
		while (*str >= '0' && *str <= '9')
			res = 10 * res + (*str++ - '0');
		if (res > 9223372036854775807 && minus == -1)
			return (0);
		if (res > 9223372036854775807)
			return (-1);
		return ((int)res * minus);
	}
	return (0);
}
