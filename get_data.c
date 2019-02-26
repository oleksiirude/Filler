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
//    ft_printf("y%d, x%d\n", token->y, token->x);
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
	i = -1;
//	ft_printf("Token:\n");
//	while (++i < token->y)
//		ft_printf("%s\n", token->token[i]);
    return (token);
}

int		**get_map(char **line, t_data *board, int fd)
{
    int	i;
    int	**map;
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
//        ft_dprintf(fd2, "%s\n", *line);
        *line = ft_strsub_free(*line, 4, (size_t)board->x);
        map[i] = str_to_int_conv(*line, board, &en, i);
		en->next = (t_hm*)malloc(sizeof(t_hm));
		en = en->next;
		en->next = NULL;
        free(*line);
    }
//    ft_dprintf(fd2, "%c", '\n');
	map = get_heatmap(map, board);
	while (head)
	{
		en = head;
		head = head->next;
		free(en);
	}
    return (map);
}

int 	**update_map(char **line, t_data *board, int fd)
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
		new_en->next = (t_hm*)malloc(sizeof(t_hm));
		new_en = new_en->next;
		new_en->next = NULL;
        free(*line);
	}
	board->map = apply_heatmap_algorithm(board->map, new_en, board, crd);
	while (head)
	{
		new_en = head;
		head = head->next;
		free(new_en);
	}
    return (board->map);
}
