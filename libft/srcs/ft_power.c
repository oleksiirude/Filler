/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:37:44 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 13:09:41 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_power(int nb, int pow)
{
	int	res;

	res = nb;
	if (!pow)
		return (1);
	else if (pow > 1)
		while (pow-- > 1)
			res *= nb;
	return (res);
}
