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

void	ft_get_player(char **line, t_data **board, int fd)
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

void	ft_get_map_size(char **line, t_data **board)
{
    char *tmp;

    tmp = *line;
    *line += 8;
    (*board)->y = ft_atoi_ptr(line);
    (*board)->x = ft_atoi_ptr(line);
    free(tmp);
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
//	i = -1;
//	ft_printf("Token:\n");
//	while (++i < token->y)
//		ft_printf("%s\n", token->token[i]);
    return (token);
}

int		**ft_get_map(char **line, t_data *board, int fd)
{
    int	i;
    int	**map;

    i = -1;
    map = (int**)malloc(sizeof(int*) * (board->y));
    board->overlap = 0;
    while (++i < board->y)
    {
        get_next_line(fd, line);
        *line = ft_strsub_free(*line, 4, (size_t)board->x);
        map[i] = ft_str_to_int_conv(*line, board);
        free(*line);
    }
	map = get_heatmap(map, board);
    return (map);
}
