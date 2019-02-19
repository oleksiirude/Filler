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

t_psz	ft_get_player(char **line, int fd)
{
	int		sign;
	t_psz	psz;

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

t_psz	ft_get_map_size(char **line, t_psz psz)
{
	char *tmp;

	tmp = *line;
	*line += 8;
	psz.height = ft_atoi_ptr(line);
	psz.width = ft_atoi_ptr(line);
	free(tmp);
	return (psz);
}

int		*ft_str_to_int_conv(char *line, t_psz psz)
{
	int i;
	int *row;

	i = 0;
	row = (int*)malloc(sizeof(int) * psz.width);
	while (i < psz.width)
	{
		if (line[i] == '.')
			row[i] = 0;
		else if (line[i] == 'O' || line[i] == 'o')
			row[i] = O;
		else if (line[i] == 'X' || line[i] == 'x')
			row[i] = X;
		i++;
	}
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
