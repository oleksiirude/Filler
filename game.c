/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 20:00:03 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

void	lets_play(t_data *board, t_token *token)
{
	int counter = 0;
	t_crd	m;
	t_crd	t;
	t_reply reply;
	int		overlap;
	int		error;
	int		y;
	int 	x;
	int 	sign;

	y = 0;
	x = 0;
	sign = 0;
	error = 0;
	m.x = 0;
	m.y = 0;
	t.x = 0;
	t.y = 0;
	overlap = 0;
	reply.y = 0;
	reply.x = 0;
	ft_printf("y[%d], x[%d]\n\n", token->y, token->x);
	ft_printf("Player: %d\n", board->player);
	ft_printf("Enemy: %d\n\n", board->enemy);
	while (y + (token->y - 1) < board->y)
	{
		reply.y = y;
		reply.x = x;
		while (x + (token->x - 1) < board->x)
		{
			while (t.y < token->y)
			{
				m.x = x;
				while (t.x < token->x)
				{
					if (board->map[m.y][m.x] == board->player && token->token[t.y][t.x] == '*')
						overlap++;
					else if (board->map[m.y][m.x] == board->enemy && token->token[t.y][t.x] == '*')
					{
						overlap = 0;
						sign = 1;
						break;
					}
					t.x++;
					m.x++;
				}
				m.y++;
				t.y++;
				t.x = 0;
				if (sign)
					break ;
			}
			if (overlap == 1)
			{
				printf("Reply: y-%d, x->%d\n", y, x);
				exit(0);
			}
			x++;
			m.y = y;
			t.y = 0;
			overlap = 0;
		}
		y++;
		m.y = y;
		x = 0;
	}
}