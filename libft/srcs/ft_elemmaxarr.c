/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemmaxarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:41:18 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/18 13:18:57 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_elemmaxarr(int const *arr, size_t arrlen)
{
	int max;

	if (arrlen <= 0)
		return (0);
	if (!arr)
		return (0);
	max = *arr;
	while (arrlen--)
	{
		if (*arr > max)
			max = *arr;
		arr++;
	}
	return (max);
}
