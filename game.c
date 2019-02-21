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
	ft_printf("Player: %d\n", board->player);
	ft_printf("Enemy: %d\n", board->enemy);
	while (y < board->y)
	{
		reply.y = y;
		reply.x = x;
		while (x < board->x)
		{
			reply.y = y;
			reply.x = x;
			while (t.y < token->y)
			{
				m.x = x;
				while (t.x < token->x)
				{
					if (board->map[m.y][m.x] == board->player && token->token[t.y][t.x] == '*')
						overlap++;
					else if (board->map[m.y][m.x] == board->enemy && token->token[t.y][t.x] == '*')
						break ;
					t.x++;
					m.x++;
				}
				m.y++;
				t.y++;
				t.x = 0;
			}
			if (overlap == 1)
				exit(0);
			x++;
			m.y = y;
			t.y = 0;
		}
		printf("x->%d\n", x);
		overlap = 0;
		x = 0;
		y++;
	}
}