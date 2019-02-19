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

void	*ft_cut_width(t_token **piece)
{
	int i;

	i = 0;
	while (i < (*piece)->height)
	{
		(*piece)->token[i][(*piece)->width] = 0;
		i++;
	}
}

t_token	*ft_cut_token(t_token *piece)
{
	int i;
	int counter;
	int max_star_pos;

	i = 0;
	counter = 0;
	max_star_pos = 0;
	while (!ft_check_row(piece->token[i], &max_star_pos))
	{
		counter++;
		i++;
	}
	while (piece->token[i] && ft_check_row(piece->token[i++], &max_star_pos))
		counter++;
	while (piece->token[i])
		free(piece->token[i++]);
	piece->width = max_star_pos;
	piece->height = counter;
	free(piece->token[counter]);
	ft_cut_width(&piece);
	return (piece);
}

t_token	*ft_get_token(char **line, int fd)
{
	int		i;
	char	*tmp;
	t_token	*piece;

	piece = (t_token*)malloc(sizeof(t_token));
	get_next_line(fd, line);
	tmp = *line;
	*line += 6;
	piece->height = ft_atoi_ptr(line);
	piece->width = ft_atoi_ptr(line);
	piece->token = (char**)malloc(sizeof(char*) * (piece->height + 1));
	free(tmp);
	i = -1;
	while (++i < piece->height)
	{
		get_next_line(fd, line);
		piece->token[i] = ft_strsub_free(*line, 0, ft_strlen(*line));
	}
	piece->token[piece->height] = 0;
	piece = ft_cut_token(piece);
	return (piece);
}

int		**ft_get_map(char **line, t_psz psz, int fd)
{
	int	i;
	int	**mtrx;

	i = -1;
	mtrx = (int**)malloc(sizeof(int*) * (psz.height));
	while (++i < psz.height)
	{
		get_next_line(fd, line);
		*line = ft_strsub_free(*line, 4, (size_t)psz.width);
		mtrx[i] = ft_str_to_int_conv(*line, psz);
		free(*line);
	}
	return (mtrx);
}

int		main(void)
{
	int		fd;
	int		sign;
	char	*line;
	int		**mtrx;
	t_psz	psz;
	t_token	*token;

	fd = open("../map02", O_RDWR);
	sign = 0;
	psz = ft_get_player(&line, fd);
	while (get_next_line(fd, &line) > 0)
	{
		if (!sign)
			psz = ft_get_map_size(&line, psz);
		if (sign)
			free(line);
		get_next_line(fd, &line);
		free(line);
		mtrx = ft_get_map(&line, psz, fd);
		token = ft_get_token(&line, fd);
		//game and then free all stuff
		ft_free_allocated_stuff(mtrx, token, psz);
		sign = 1;
	}
	system("leaks -q Filler");
	return (0);
}
