/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemminarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:41:18 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/18 13:18:33 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_elemminarr(int const *arr, size_t arrlen)
{
	int min;

	if (arrlen <= 0)
		return (0);
	if (!arr)
		return (0);
	min = *arr;
	while (arrlen--)
	{
		if (*arr < min)
			min = *arr;
		arr++;
	}
	return (min);
}
