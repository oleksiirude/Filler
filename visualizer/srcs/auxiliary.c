/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/16 14:33:35 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vizo_filler.h"

void	skip_line(char *line)
{
	get_next_line(0, &line);
	free(line);
}

int		error_massage(void)
{
	ft_cprintf("REDCLError!STPC\n");
	ft_cprintf("GRNCLVizo Usage: ./[player_name]STPC\n");
	ft_cprintf("YELCL            ./[map]STPC\n");
	return (-1);
}

int		get_player_name(char *line, t_data *box, int sign)
{
	if (sign)
	{
		if (ft_strrchr(line, '/'))
			box->p1 = ft_strrchr(line, '/') + 1;
		else
		{
			free(line);
			return (-1);
		}
	}
	else
	{
		if (ft_strrchr(line, '/'))
			box->p2 = ft_strrchr(line, '/') + 1;
		else
		{
			free(line);
			return (-1);
		}
	}
	return (0);
}

int		atoi_ptr(char **str)
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
