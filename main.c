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

int 	ft_check_row(char *str, int *pos)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
		{
			while (str[i] == '*')
				i++;
			if (i > *pos)
				*pos = i;
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_cut_width(t_token **piece)
{
	int i;

	i = 0;
//	printf("(*piece)->height[%d]\n", (*piece)->height);
	while (i < (*piece)->height)
	{
		(*piece)->token[i][(*piece)->width] = 0;
		i++;
	}
}

t_token *ft_cut_token(t_token *piece)
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
//	printf("maximum * position is %d\n", max_star_pos);
	piece->width = max_star_pos;
	piece->height = counter;
//	printf("h->%d, w->%d\n", piece->height, piece->width);
	piece->token[counter] = 0;
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
//	printf("tline->%s\n", *line);
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
//		printf("tline->%s\n", *line);
		piece->token[i] = ft_strsub_free(*line, 0, ft_strlen(*line));
	}
	piece->token[piece->height] = 0;
	printf("before h[%d], w[%d]\n", piece->height, piece->width);
	piece = ft_cut_token(piece);
	i = 0;
	while (i < piece->height)
		printf("%s\n", piece->token[i++]);
	printf("last%s\n", piece->token[i]);
	printf("after h[%d], w[%d]\n", piece->height, piece->width);
	return (piece);
}

int		**ft_get_map(char **line, t_ps psz, int fd)
{
	int	i;
	int	**mtrx;

	i = -1;
	mtrx = (int**)malloc(sizeof(int*) * (psz.height));
//	printf("start: i = %d, h -> %d\n", i, psz.height);
	while (++i < psz.height)
	{
		get_next_line(fd, line);
//		printf("line->%s\n", *line);
		*line = ft_strsub_free(*line, 4, (size_t)psz.width);
		mtrx[i] = ft_str_to_int_conv(*line, psz);
		free(*line);
	}
//	printf("end: i = %d, h -> %d\n", i, psz.height);
	return (mtrx);
}

t_ps	ft_get_player(char **line, int fd)
{
	int		sign;
	t_ps	psz;

	sign = 0;
	get_next_line(fd, line);
	if (line[0][10] == '1')
		sign = 1;
	free(*line);
	if (sign)
		psz.player = P1;
	else
		psz.player = P2;
	return (psz);
}

t_ps	ft_get_map_size(char **line, t_ps psz)
{
	char *tmp;

//	get_next_line(0, line);
	tmp = *line;
	*line += 8;
	psz.height = ft_atoi_ptr(line);
	psz.width = ft_atoi_ptr(line);
	free(tmp);
	return (psz);
}

int		main(void)
{
	int		fd;
	t_ps	psz;
	t_token	*token;
	int		sign;
	int		**mtrx;
	char	*line;

	fd = open("../map00", O_RDWR);
	sign = 0;
	psz = ft_get_player(&line, fd);
	while (get_next_line(fd, &line) > 0)
	{
		if (!sign)
			psz = ft_get_map_size(&line, psz);
//		else
//			ft_go_next_line(&line);
		ft_go_next_line(&line, fd);
		mtrx = ft_get_map(&line, psz, fd);
		token = ft_get_token(&line, fd);
		sign = 1;
		write(1, "OK\n", 3);
	}
	write(1, "OUT\n", 4);
//	system("leaks -q Filler");
	return (0);
}
