/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:53:55 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vizo_filler.h"

void	get_data(t_data *box, int sign)
{
	if (!sign)
	{
		box->step = 35;
		box->init.y = 320;
		box->init.x = 220;
	}
	else if (sign == 1)
	{
		box->step = 23;
		box->init.y = 260;
		box->init.x = 45;
	}
	else if (sign == 2)
	{
		box->step = 8;
		box->init.y = 180;
		box->init.x = 110;
	}
}

int		setup_data_in_window(t_data *box)
{
	if (box->size.y == 16)
		get_data(box, 0);
	else if (box->size.y == 25)
		get_data(box, 1);
	else
		get_data(box, 2);
	box->color = 38400;
	return (0);
}
