/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 20:00:03 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int		fd;
	int		sign;
	char	*line;
	t_data	*board;
	t_token	*token;

	sign = 0;
//	fd = open("../test", O_RDWR);
	fd = 0;
	board = (t_data*)malloc(sizeof(t_data));
	get_player(&line, &board, fd);
	board->map = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		sign ? free(line) : get_map_size(&line, &board);
		get_next_line(fd, &line);
		free(line);
		board->map = board->map ? update_map(&line, board, fd)
				: get_map(&line, board, fd);
		token = get_token(&line, fd);
		lets_play(board, token);
		free_token(token);
		sign = 1;
	}
	free_board(board);
	return (0);
}
