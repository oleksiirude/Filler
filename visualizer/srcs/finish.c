/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/16 14:34:36 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vizo_filler.h"

t_crd	get_score(char *line)
{
	t_crd	fin;
	char	*tmp;

	tmp = line;
	line += 9;
	fin.x = atoi_ptr(&line);
	free(tmp);
	get_next_line(0, &line);
	tmp = line;
	line += 9;
	fin.y = atoi_ptr(&line);
	free(tmp);
	return (fin);
}

void	print_score(t_data *box, t_crd fin)
{
	char	*score;

	mlx_string_put(box->mlx.ptr, box->mlx.win, 440, 120, 38400,
			"END OF THE GAME!");
	score = ft_itoa(fin.x);
	mlx_string_put(box->mlx.ptr, box->mlx.win, 250, 140, 16724480, score);
	free(score);
	score = ft_itoa(fin.y);
	mlx_string_put(box->mlx.ptr, box->mlx.win, 770, 140, 255, score);
	free(score);
}

int		finish(t_data *box, char *line)
{
	char	*str;
	t_crd	fin;

	fin = get_score(line);
	if (fin.x > fin.y)
	{
		str = ft_strjoin(box->p1, " WINS!");
		mlx_string_put(box->mlx.ptr, box->mlx.win, 420, 140, 16724480, str);
		free(str);
	}
	else if (fin.x < fin.y)
	{
		str = ft_strjoin(box->p2, " WINS!");
		mlx_string_put(box->mlx.ptr, box->mlx.win, 420, 140, 255, str);
		free(str);
	}
	else
		mlx_string_put(box->mlx.ptr, box->mlx.win, 490, 140, 38400, "DRAW!");
	print_score(box, fin);
	return (1);
}
