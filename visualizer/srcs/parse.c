/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:53:55 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vizo_filler.h"

int		check_zz(t_data *box, char *line)
{
	int		i;
	char	*tmp;

	free(line);
	get_next_line(0, &line);
	if (line[0] == '=')
	{
		box->fin = 1;
		return (finish(box, line));
	}
	if (!ft_strncmp(line, "Piece", 5))
	{
		tmp = line;
		line += 6;
		i = atoi_ptr(&line) + 1;
		free(tmp);
		while (i--)
			skip_line(line);
	}
	else
	{
		free(line);
		return (-1);
	}
	return (0);
}

int		check_valid(t_data *box)
{
	int		i;
	int		res;
	char	*line;
	char	*tmp;

	res = 0;
	get_next_line(0, &line);
	tmp = line;
	line += 6;
	i = atoi_ptr(&line);
	free(tmp);
	while (i--)
		skip_line(line);
	get_next_line(0, &line);
	if (line[11] == '0' && line[14] == '0')
	{
		res = check_zz(box, line);
		if (res == 1)
			return (1);
	}
	else
		free(line);
	if (res != -1)
		skip_line(line);
	return (0);
}

void	basic_map(t_data *box)
{
	int i;

	i = -1;
	box->map = (char**)malloc(sizeof(char*) * box->size.y);
	while (++i < box->size.y - 1)
	{
		box->map[i] = (char*)malloc(sizeof(char) * box->size.x);
		box->map[i] = ft_memset(box->map[i],
				46, (size_t)box->size.x - 1);
		box->map[i][box->size.x - 1] = 0;
	}
}

void	get_map_size(char *line, t_data *box)
{
	char *tmp;

	tmp = line;
	line += 8;
	box->size.y = atoi_ptr(&line) + 1;
	box->size.x = atoi_ptr(&line) + 1;
	free(tmp);
}

int		get_basic_data(t_data *box)
{
	int		i;
	char	*line;

	i = -1;
	line = NULL;
	while (++i < 5)
		skip_line(line);
	get_next_line(0, &line);
	if (get_player_name(line, box, 1) < 0)
		return (-1);
	skip_line(line);
	get_next_line(0, &line);
	if (get_player_name(line, box, 0) < 0)
		return (-1);
	skip_line(line);
	get_next_line(0, &line);
	get_map_size(line, box);
	basic_map(box);
	return (0);
}
