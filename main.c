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

t_token	*ft_cut_token(t_token *token)
{
	int i;
	int counter;
	int max_star_pos;

	i = -1;
	counter = 0;
	max_star_pos = 0;
	while (!ft_check_row(token->token[++i], &max_star_pos))
		counter++;
	while (token->token[i] && ft_check_row(token->token[i++], &max_star_pos))
		counter++;
	while (token->token[i])
		free(token->token[i++]);
	token->x = max_star_pos;
	token->y = counter;
	free(token->token[counter]);
	i = -1;
	while (++i < token->y)
		token->token[i][token->x] = 0;
	return (token);
}

t_token	*ft_get_token(char **line, int fd)
{
	int		i;
	char	*tmp;
	t_token	*token;

	token = (t_token*)malloc(sizeof(t_token));
	get_next_line(fd, line);
	tmp = *line;
	*line += 6;
	token->y = ft_atoi_ptr(line);
	token->x = ft_atoi_ptr(line);
	token->token = (char**)malloc(sizeof(char*) * (token->y + 1));
	free(tmp);
	i = -1;
	while (++i < token->y)
	{
		get_next_line(fd, line);
		token->token[i] = ft_strsub_free(*line, 0, ft_strlen(*line));
	}
	token->token[token->y] = 0;
	token = ft_cut_token(token);
	return (token);
}

int		**ft_get_map(char **line, t_data *board, int fd)
{
	int	i;
	int	**map;

	i = -1;
	map = (int**)malloc(sizeof(int*) * (board->y));
	while (++i < board->y)
	{
		get_next_line(fd, line);
		*line = ft_strsub_free(*line, 4, (size_t)board->y);
		map[i] = ft_str_to_int_conv(*line, board);
		free(*line);
	}
	return (map);
}

int		main(void)
{
	int		fd;
	int		sign;
	char	*line;
	t_data	*board;
	t_token	*token;

	fd = open("../map02", O_RDWR);
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
	system("leaks -q Filler");
	return (0);
}
