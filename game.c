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

int		get_sum(t_data *board, t_token *token, t_reply reply)
{
	t_crd	crd;
	int		sum;
	int		start_x;

	sum = 0;
	start_x = reply.g_x;
	ft_bzero(&crd, 8);
	while (crd.y < token->y)
	{
		while (crd.x < token->x)
		{
			if (board->map[reply.g_y][reply.g_x] != board->player)
				sum += board->map[reply.g_y][reply.g_x];
			crd.x++;
			reply.g_x++;
		}
		crd.y++;
		crd.x = 0;
		reply.g_x = start_x;
		reply.g_y++;
	}
	return (sum);
}

void	to_zero(t_points *p, t_reply *reply, int *sign)
{
	ft_bzero(p, 16);
	ft_bzero(reply, 24);
	*sign = 0;
}

void	if_valid_overlap(t_reply *reply, t_data *board, t_token *token, int *s)
{
	*s = 1;
	(*reply).sum = get_sum(board, token, *reply);
	if (!(*reply).res)
	{
		(*reply).res = (*reply).sum;
		(*reply).y_res = (*reply).g_y;
		(*reply).x_res = (*reply).g_x;
	}
	else if ((*reply).res > (*reply).sum)
	{
		(*reply).res = (*reply).sum;
		(*reply).y_res = (*reply).g_y;
		(*reply).x_res = (*reply).g_x;
	}
}

void	inside_loops(t_points *p, t_token *token, t_data **b, t_reply *reply)
{
	while ((*p).t.y < token->y)
	{
		(*p).m.x = (*reply).g_x;
		while ((*p).t.x < token->x)
		{
			if ((*b)->map[(*p).m.y][(*p).m.x] == (*b)->player
					&& token->token[(*p).t.y][(*p).t.x] == '*')
				(*b)->overlap++;
			else if ((*b)->map[(*p).m.y][(*p).m.x] == (*b)->enemy
					&& token->token[(*p).t.y][(*p).t.x] == '*')
			{
				(*b)->overlap = 0;
				(*b)->error = 1;
				break ;
			}
			(*p).t.x++;
			(*p).m.x++;
		}
		(*p).m.y++;
		(*p).t.y++;
		(*p).t.x = 0;
		if ((*b)->error)
			break ;
	}
}

void	lets_play(t_data *board, t_token *token, int sign)
{
	t_points	p;
	t_reply		reply;

	to_zero(&p, &reply, &sign);
	while (reply.g_y + (token->y - 1) < board->y)
	{
		while (reply.g_x + (token->x - 1) < board->x)
		{
			inside_loops(&p, token, &board, &reply);
			if (board->overlap == 1)
				if_valid_overlap(&reply, board, token, &sign);
			reply.g_x++;
			p.m.y = reply.g_y;
			p.t.y = 0;
			board->overlap = 0;
			board->error = 0;
		}
		reply.g_y++;
		p.m.y = reply.g_y;
		reply.g_x = 0;
	}
	reply_crd(sign, reply);
}
