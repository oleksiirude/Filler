/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:22:18 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/18 14:11:24 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_filler(int size, unsigned int nbig, char *str)
{
	int tmp;

	tmp = 0;
	while (--size >= 0 && str[size] != '-')
	{
		tmp = nbig % 10;
		str[size] = tmp + '0';
		nbig /= 10;
	}
	return (str);
}

static	int		ft_size(int tmp, int size)
{
	if (!tmp)
		size++;
	else
		while (tmp)
		{
			tmp /= 10;
			size++;
		}
	return (size);
}

char			*ft_itoa(int n)
{
	int				tmp;
	unsigned int	nbig;
	int				size;
	char			*str;

	size = 0;
	nbig = n;
	tmp = n;
	if (n < 0)
	{
		nbig = n * -1;
		size++;
	}
	size = ft_size(tmp, size);
	if (!(str = (char*)ft_memalloc(size + 1)))
		return (NULL);
	str[size + 1] = 0;
	if (n < 0)
		*str = '-';
	ft_filler(size, nbig, str);
	return (str);
}
