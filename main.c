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
//	int 	fd2;
	int		fd;
	int		sign;
	char	*line;
	t_data	*board;
	t_token	*token;

//	fd2 = open("./log.txt", O_RDWR | O_TRUNC);
//	fd = open("../map00", O_RDWR);
//	ft_printf("fd1->%d fd2->%d\n", fd, fd2);
	fd = 0;
	sign = 0;
	board = (t_data*)malloc(sizeof(t_data));
	get_player(&line, &board, fd);
	board->map = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!sign)
			get_map_size(&line, &board);
		else
			free(line);
		get_next_line(fd, &line);
		free(line);
		if (!board->map)
			board->map = get_map(&line, board, fd);
		else
			board->map = update_map(&line, board, fd);
		token = get_token(&line, fd);
		lets_play(board, token);
		free_token(token);
		sign = 1;
	}
	free_board(board);
//	system("leaks -q Filler");
	return (0);
}
