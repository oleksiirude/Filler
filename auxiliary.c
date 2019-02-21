/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:37:44 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 12:40:32 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_row(char *str, int *pos)
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

int		*ft_str_to_int_conv(char *line, t_data *board)
{
	int i;
	int *row;

	i = 0;
	row = (int*)malloc(sizeof(int) * board->x);
	while (i < board->x)
	{
		row[i] = 0;
		if (line[i] == 'O' || line[i] == 'o')
			row[i] = O;
		else if (line[i] == 'X' || line[i] == 'x')
			row[i] = X;
		ft_printf("%3d", row[i]);
		i++;
	}
	ft_printf("\n");
	return (row);
}

int		ft_atoi_ptr(char **str)
{
	int	res;

	res = 0;
	while ((**str >= '\t' && **str <= '\r') || **str == ' ')
		(*str)++;
	while (**str)
	{
		while (**str >= '0' && **str <= '9')
		{
			res = 10 * res + (**str - '0');
			(*str)++;
		}
		return (res);
	}
	return (0);
}
