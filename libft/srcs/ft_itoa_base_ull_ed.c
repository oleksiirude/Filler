/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull_ed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:57:16 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/29 15:42:41 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lensize(unsigned long long value, int base)
{
	size_t	len;

	len = 0;
	while (value >= (unsigned long long)base)
	{
		value /= base;
		len++;
	}
	return (len);
}

char			*ft_fill(size_t l, unsigned long long v, char *arr, int b)
{
	unsigned int	tmp;

	while (v >= (unsigned int)b)
	{
		tmp = v % b;
		if (tmp > 9)
			arr[l--] = 'a' + (tmp - 10);
		else
			arr[l--] = tmp + '0';
		v /= b;
	}
	if (v > 9)
		arr[l] = 'a' + (v - 10);
	else
		arr[l] = v + '0';
	return (arr);
}

char			*ft_itoa_base_ull_ed(unsigned long long value, int base)
{
	size_t				len;
	char				*arr;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_lensize(value, base);
	arr = (char*)malloc(sizeof(char) * len + 1);
	arr[len + 1] = 0;
	return (ft_fill(len, value, arr, base));
}
