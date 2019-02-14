/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:09:13 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/09 19:07:54 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int un;

	un = n;
	if (n < 0)
	{
		ft_putchar('-');
		un = n * -1;
	}
	if (un > 9)
	{
		ft_putnbr(un / 10);
		ft_putnbr(un % 10);
	}
	else
		ft_putchar(un + '0');
}
