/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:37:44 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 12:40:32 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		*update_line(char *line, t_hm **new_en, t_data *b, int y)
{
	int x;
	int *row;
	int sign;

	x = 0;
	row = b->map[y];
	sign = b->enemy == -1 ? P1 : P2;
	while (x < b->x)
	{
		if ((line[x] == 'O' || line[x] == 'o') && row[x] != O)
		{
			if (sign == P1)
				write_down_enemy_crd(y, x, new_en);
			row[x] = O;
		}
		else if ((line[x] == 'X' || line[x] == 'x') && row[x] != X)
		{
			if (sign == P2)
				write_down_enemy_crd(y, x, new_en);
			row[x] = X;
		}
		x++;
	}
	return (row);
}

void	reply_crd(int sign, t_reply reply)
{
	if (!sign)
		ft_printf("%d %d\n", 0, 0);
	else
		ft_printf("%d %d\n", reply.y_res, reply.x_res);
}
