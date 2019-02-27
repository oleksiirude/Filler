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

#include "filler.h"

int	*update_line(char *line, t_hm **new_en, t_data *board, int y)
{
	int x;
	int *row;
	int sign;

	x = 0;
	row = board->map[y];
	sign = board->enemy == -1 ? P1 : P2;
	while (x < board->x)
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
