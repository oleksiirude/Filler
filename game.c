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

int 	get_sum(t_data *board, t_token *token, t_crd reply)
{
	t_crd	crd;
	int		sum;
	int 	start_x;

	sum = 0;
	start_x = reply.x;
	ft_bzero(&crd, 8);
	while (crd.y < token->y)
	{
		while (crd.x < token->x)
		{
			if (board->map[reply.y][reply.x] != board->player)
				sum += board->map[reply.y][reply.x];
			crd.x++;
			reply.x++;
		}
		crd.y++;
		crd.x = 0;
		reply.x = start_x;
		reply.y++;
	}
	return (sum);
}

void	to_zero(t_points *p, t_reply *reply, t_crd *global)
{
	ft_bzero(p, 16);
	ft_bzero(reply, 24);
	ft_bzero(global, 8);
}

void	lets_play(t_data *board, t_token *token)
{
	t_points	p;
	t_reply		reply;
	t_crd		global;
	int			error;
	int			sign;

	to_zero(&p, &reply, &global);
	sign = 0;
	error = 0;
	while (global.y + (token->y - 1) < board->y)
	{
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
				sign = 1;
				reply.sum = get_sum(board, token, global);
//				ft_printf("sum: %d\n", reply.sum);
//				ft_printf("crd: %d %d\n", global.y, global.x);
				if (!reply.res)
				{
					reply.res = reply.sum;
					reply.y_res = global.y;
					reply.x_res = global.x;
				}
				else if (reply.res > reply.sum)
				{
					reply.res = reply.sum;
					reply.y_res = global.y;
					reply.x_res = global.x;
				}
//				ft_printf("res: %d\n\n", reply.res);
//				ft_printf("%d %d\n", global.y, global.x);
//				sign = 1;
//				break ;
			}
			global.x++;
			p.m.y = global.y;
			p.t.y = 0;
			board->overlap = 0;
			error = 0;
		}
//		if (sign)
//			break ;
		global.y++;
		p.m.y = global.y;
		global.x = 0;
	}
//	ft_printf("sing: %d\n", sign);
//	ft_printf("final res: %d\n", reply.res);
	if (!sign)
		ft_printf("%d %d\n", 0, 0);
	else
		ft_printf("%d %d\n", reply.y_res, reply.x_res);
}