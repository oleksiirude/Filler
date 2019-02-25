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

void	to_zero(t_points *p, t_crd *reply, t_crd *global)
{
	ft_bzero(p, 16);
	ft_bzero(reply, 8);
	ft_bzero(global, 8);
}

void	lets_play(t_data *board, t_token *token)
{
	t_points	p;
	t_crd		reply;
	t_crd		global;
	int			error;
	int			sign;

	to_zero(&p, &reply, &global);
	sign = 0;
	error = 0;
	while (global.y + (token->y - 1) < board->y)
	{
		reply.y = global.y;
		reply.x = global.x;
		while (global.x + (token->x - 1) < board->x)
		{
			while (p.t.y < token->y)
			{
				p.m.x = global.x;
				while (p.t.x < token->x)
				{
					if (board->map[p.m.y][p.m.x] == board->player && token->token[p.t.y][p.t.x] == '*')
						board->overlap++;
					else if (board->map[p.m.y][p.m.x] == board->enemy && token->token[p.t.y][p.t.x] == '*')
					{
						board->overlap = 0;
						error = 1;
						break;
					}
					p.t.x++;
					p.m.x++;
				}
				p.m.y++;
				p.t.y++;
				p.t.x = 0;
				if (error)
					break ;
			}
			if (board->overlap == 1)
			{
				ft_printf("%d %d\n", global.y, global.x);
				sign = 1;
				break ;
			}
			global.x++;
			p.m.y = global.y;
			p.t.y = 0;
			board->overlap = 0;
			error = 0;
		}
		if (sign)
			break ;
		global.y++;
		p.m.y = global.y;
		global.x = 0;
	}
	if (!sign)
		ft_printf("%d %d\n", 0, 0);
}