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

int	formula(int y, int x, t_crd crd)
{
	return (ft_power(y - crd.y, 2) + ft_power(x - crd.x, 2));
}

int	**apply_heatmap_algorithm(int **map, t_hm *enemy, t_data *board)
{
	t_crd	crd;
	int		res;

	ft_bzero(&crd, 8);
	while (enemy->next)
	{
		while (crd.y < board->y)
		{
			while (crd.x < board->x)
				if (map[crd.y][crd.x] == board->player)
					crd.x++;
				else
				{
					res = formula(enemy->crd->y, enemy->crd->x, crd);
					if (map[crd.y][crd.x] > res)
						map[crd.y][crd.x] = res;
					crd.x++;
				}
			crd.x = 0;
			crd.y++;
		}
		enemy = enemy->next;
		crd.y = 0;
	}
	return (map);
}
