/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/16 14:32:12 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		main(void)
{
	int		sign;
	char	*line;
	t_data	*board;
	t_token	*token;

	sign = 0;
	board = (t_data*)malloc(sizeof(t_data));
	if (get_player(&line, &board))
		return (0);
	board->map = NULL;
	while (get_next_line(0, &line) > 0)
	{
		sign ? free(line) : get_map_size(&line, &board);
		get_next_line(0, &line);
		free(line);
		board->map = board->map ? update_map(&line, board)
				: get_map(&line, board);
		token = get_token(&line);
		board->error = 0;
		lets_play(board, token, sign);
		free_token(token);
		sign = 1;
	}
	free_board(board);
	return (0);
}
