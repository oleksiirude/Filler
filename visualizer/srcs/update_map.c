/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:53:55 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vizo_filler.h"

void	paint_square(t_data *box, int y, int x)
{
	int		tmp;
	t_crd	a;
	t_crd	b;

	a.x = box->init.x + (x * box->step);
	a.y = box->init.y + (y * box->step);
	b.x = box->init.x + ((x + 1) * box->step);
	b.y = box->init.y + ((y + 1) * box->step);
	tmp = a.x;
	while (a.y != b.y)
	{
		a.x = tmp;
		while (a.x != b.x)
		{
			mlx_pixel_put(box->mlx.ptr, box->mlx.win, a.x, a.y, box->color);
			a.x++;
		}
		a.y++;
	}
}

void	update_map(t_data *box, char *line, int y)
{
	int x;

	x = 0;
	line += 4;
	while (line[x])
	{
		if ((line[x] == 'O' || line[x] == 'X'
		|| line[x] == 'x' || line[x] == 'o') && (box->map[y][x] == '.'
		|| box->map[y][x] == 'o' || box->map[y][x] == 'x'))
		{
			box->map[y][x] = line[x];
			if (box->map[y][x] == 'O')
				box->color = 16724480;
			else if (box->map[y][x] == 'X')
				box->color = 255;
			else if (box->map[y][x] == 'x')
				box->color = 2949119;
			else if (box->map[y][x] == 'o')
				box->color = 2949119;
			paint_square(box, y, x);
		}
		x++;
	}
}

int		launch_vizo(t_data *box)
{
	int		y;
	char	*line;

	y = -1;
	line = NULL;
	skip_line(line);
	while (++y < box->size.y - 1)
	{
		get_next_line(0, &line);
		update_map(box, line, y);
		free(line);
	}
	if (check_valid(box))
		return (1);
	return (0);
}
