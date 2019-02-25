/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_intarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:37:44 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 12:40:32 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_print_intarr(int **arr, int h, int w)
{
	int hh;
	int ww;

	hh = 0;
	ww = 0;
	while (hh < h)
	{
		while (ww < w)
		{
			ft_printf("%5d", arr[hh][ww]);
			ww++;
		}
		ft_printf("\n");
		ww = 0;
		hh++;
	}
	ft_printf("\n");
}