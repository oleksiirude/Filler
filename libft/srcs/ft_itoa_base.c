/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:57:16 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/18 13:12:52 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_lensize(int value, int base, unsigned int *nb)
{
	int				len;
	unsigned int	tmp;

	len = 0;
	*nb = value;
	tmp = *nb;
	if (value < 0)
	{
		tmp = value * -1;
		if (base == 10)
			len++;
	}
	while (tmp >= (unsigned int)base)
	{
		tmp /= base;
		len++;
	}
	if (value < 0)
		*nb = value * -1;
	return (len);
}

static char			*ft_filler(int len, unsigned int nb, char *arr, int base)
{
	unsigned int	tmp;

	while (nb >= (unsigned int)base)
	{
		tmp = nb % base;
		if (tmp > 9)
			arr[len--] = 'A' + (tmp - 10);
		else
			arr[len--] = tmp + '0';
		nb /= base;
	}
	if (nb > 9)
		arr[len] = 'A' + (nb - 10);
	else
		arr[len] = nb + '0';
	return (arr);
}

char				*ft_itoa_base(int value, int base)
{
	int				len;
	char			*arr;
	unsigned int	nb;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_lensize(value, base, &nb);
	if (!(arr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (base == 10 && value < 0)
		*arr = '-';
	arr[len + 1] = 0;
	return (ft_filler(len, nb, arr, base));
}
