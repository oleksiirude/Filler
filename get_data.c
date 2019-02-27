/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:37:44 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 12:40:32 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(char **line, t_data **board, int fd)
{
	int		sign;

	sign = 0;
	get_next_line(fd, line);
	if (line[0][10] == '1')
		sign = 1;
	free(*line);
	if (sign)
	{
		(*board)->player = P1;
		(*board)->enemy = P2;
	}
	else
	{
		(*board)->player = P2;
		(*board)->enemy = P1;
	}
}

void	get_map_size(char **line, t_data **board)
{
	char *tmp;

	tmp = *line;
	*line += 8;
	(*board)->y = atoi_ptr(line);
	(*board)->x = atoi_ptr(line);
	free(tmp);
}

t_token	*get_token(char **line, int fd)
{
	int		i;
	char	*tmp;
	t_token	*token;

	token = (t_token*)malloc(sizeof(t_token));
	get_next_line(fd, line);
	tmp = *line;
	*line += 6;
	token->y = atoi_ptr(line);
	token->x = atoi_ptr(line);
	token->token = (char**)malloc(sizeof(char*) * (token->y + 1));
	free(tmp);
	i = -1;
	while (++i < token->y)
	{
		get_next_line(fd, line);
		token->token[i] = ft_strsub_free(*line, 0, ft_strlen(*line));
	}
	token->token[token->y] = 0;
	token = cut_token(token);
	return (token);
}

int		**get_map(char **line, t_data *board, int fd)
{
	int		i;
	int		**map;
	t_hm	*en;
	t_hm	*head;

	i = -1;
	map = (int**)malloc(sizeof(int*) * (board->y));
	board->overlap = 0;
	en = (t_hm*)malloc(sizeof(t_hm));
	en->next = NULL;
	head = en;
	while (++i < board->y)
	{
		get_next_line(fd, line);
		*line = ft_strsub_free(*line, 4, (size_t)board->x);
		map[i] = create_row(*line, board, &en, i);
		free(*line);
	}
	board->map = apply_heatmap_algorithm(map, head, board);
	free_enemy_struct(&head, &en);
	return (map);
}

int		**update_map(char **line, t_data *board, int fd)
{
	int		i;
	t_hm	*new_en;
	t_hm	*head;

	i = -1;
	new_en = (t_hm*)malloc(sizeof(t_hm));
	new_en->next = NULL;
	head = new_en;
	while (++i < board->y)
	{
		get_next_line(fd, line);
		*line = ft_strsub_free(*line, 4, (size_t)board->x);
		board->map[i] = update_line(*line, &new_en, board, i);
		free(*line);
	}
	board->map = apply_heatmap_algorithm(board->map, head, board);
	free_enemy_struct(&head, &new_en);
	return (board->map);
}
