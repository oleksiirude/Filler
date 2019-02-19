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

int 	*ft_str_to_int_conv(char *line, t_ps psz)
{
	int i;
	int *row;

	i = 0;
	row = (int*)malloc(sizeof(int) * psz.width);
	while (i < psz.width)
	{
		if (line[i] == '.')
			row[i] = 0;
		else if (line[i] == 'O')
			row[i] = O;
		else if (line[i] == 'X')
			row[i] = X;
		i++;
	}
	return (row);
}

void	ft_go_next_line(char **line)
{
	get_next_line(0, line);
	free(*line);
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