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

//	fd = open("../map00", O_RDWR);
	fd = 0;
	sign = 0;
	board = (t_data*)malloc(sizeof(t_data));
	ft_get_player(&line, &board, fd);
	while (get_next_line(fd, &line) > 0)
	{
		if (!sign)
			ft_get_map_size(&line, &board);
		if (sign)
			free(line);
		get_next_line(fd, &line);
		free(line);
		board->map = ft_get_map(&line, board, fd);
		token = ft_get_token(&line, fd);
		lets_play(board, token);
		ft_free_allocated_stuff(board, token);
		sign = 1;
	}
	free(board);
//	system("leaks -q Filler");
	return (0);
}
