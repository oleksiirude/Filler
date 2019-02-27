/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:37:44 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 12:40:32 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	apply_heatmap_algorithm(int **map, t_hm *en, t_data *board)
{
	t_crd	crd;
	int		res;

	crd.y = 0;
	crd.x = 0;
	while (en->next)
	{
		while (crd.y < board->y)
		{
			while (crd.x < board->x)
				if (map[crd.y][crd.x] == board->player)
					crd.x++;
				else
				{
					res = formula(en->crd->y, en->crd->x, crd);
					if (map[crd.y][crd.x] > res)
						map[crd.y][crd.x] = res;
					crd.x++;
				}
			crd.x = 0;
			crd.y++;
		}
		en = en->next;
		crd.y = 0;
	}
}
