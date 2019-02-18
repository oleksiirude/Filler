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

t_token	*ft_get_token(char **line)
{
	int		i;
	char	*tmp;
	t_token	*piece;

	piece = (t_token*)malloc(sizeof(t_token));
	get_next_line(0, line);
	tmp = *line;
	*line += 6;
	piece->height = ft_atoi_ptr(line);
	piece->width = ft_atoi_ptr(line);
	piece->token = (char**)malloc(sizeof(char*) * (piece->height + 1));
	piece->token[piece->height] = 0;
	free(tmp);
	i = -1;
	while (++i < piece->height)
	{
		get_next_line(0, line);
		piece->token[i] = ft_strsub_free(*line, 0, ft_strlen(*line));
	}
	return (piece);
}

int		**ft_get_map(char **line, t_ps psz)
{
	int	i;
	int	**mtrx;

	i = -1;
	mtrx = (int**)malloc(sizeof(int*) * (psz.height));
	while (++i < psz.height)
	{
		get_next_line(0, line);
		*line = ft_strsub_free(*line, 4, (size_t)psz.width);
		mtrx[i] = ft_str_to_int_conv(*line, psz);
		free(*line);
	}
	return (mtrx);
}

t_ps	ft_get_player(char **line)
{
	int		sign;
	t_ps	psz;

	sign = 0;
	get_next_line(0, line);
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

	get_next_line(0, line);
	tmp = *line;
	*line += 8;
	psz.height = ft_atoi_ptr(line);
	psz.width = ft_atoi_ptr(line);
	free(tmp);
	return (psz);
}

int		main(void)
{
	t_ps	psz;
	t_token	*token;
	int		sign;
	int		**mtrx;
	char	*line;

	sign = 0;
	psz = ft_get_player(&line);
	while (42)
	{
		if (!sign)
			psz = ft_get_map_size(&line, psz);
		else
			ft_go_next_line(&line);
		ft_go_next_line(&line);
		mtrx = ft_get_map(&line, psz);
		token = ft_get_token(&line);
		sign = 1;
	}
//	system("leaks -q Filler");
	return (0);
}
