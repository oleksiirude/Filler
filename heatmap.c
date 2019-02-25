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

void	apply_heatmap_algorithm(int **map, t_hm *en, t_data *board, t_crd crd)
{
	int res;

	while (en->next)
	{
		while (crd.y < board->y)
		{
			while (crd.x < board->x)
				if (map[crd.y][crd.x] == board->player)
					crd.x++;
				else
				{
					res = formula(en->crd.y, en->crd.x, crd);
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
t_hm  *find_enemy(int **map, t_data *board)
{
	t_crd	crd;
	t_hm	*head;
	t_hm	*tmp;

	ft_bzero(&crd, 8);
	head = (t_hm*)malloc(sizeof(t_hm));
	head->next = NULL;
	tmp = head;
    while (crd.y < board->y)
    {
        while (crd.x < board->x)
        {
        	if (map[crd.y][crd.x] == board->enemy)
			{
        		tmp->crd = crd;
        		tmp->next = (t_hm*)malloc(sizeof(t_hm));
        		tmp = tmp->next;
        		tmp->next = NULL;
			}
			crd.x++;
        }
		crd.x = 0;
		crd.y++;
    }
	return (head);
}

int     **get_heatmap(int **map, t_data *board)
{
	t_crd	crd;
	t_hm	*en;
	t_hm	*tmp;

	ft_bzero(&crd, 8);
    en = find_enemy(map, board);
    tmp = en;
	apply_heatmap_algorithm(map, en, board, crd);
    while (tmp)
	{
    	en = tmp;
		tmp = tmp->next;
    	free(en);
	}
//	ft_print_intarr(map, board->y, board->x);
    return (map);
}
